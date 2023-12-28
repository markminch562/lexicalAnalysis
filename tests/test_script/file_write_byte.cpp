//
// Created by Mark Minch  on 11/9/23.
//
//
// Created by Mark Minch  on 11/12/23.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <gtest/gtest.h>
#include <cstdio>


#include <vector>
#include <string>
#include <unordered_map>

struct DataBlob
{
    unsigned int bytes;
    void* data;
};

/**
 * The memory bag should be a byte stream that can be read into memory directly
 * so the first value should tell about what is in the file,
 * total bag size, item count, offset per item
 * item offset lookup table
 */
struct MemoryBag
{
   unsigned int count;
   unsigned int* item_index;
};

void bagReader(MemoryBag& bagData)
{
    std::cout<<"Bag Has "<<bagData.count<<" items\n";
    for(int i = 0; i < bagData.count; i++)
    {
        std::cout<<bagData.item_index[i]<<" ";
    }
    std::cout<<std::endl;
}

template<typename T>
struct MemoryChunk
{
    unsigned int item_count;
    T* item_index;
};

template <typename T>
bool writeData(const MemoryChunk<T>& memory, std::FILE fp)
{
    std::fputc(memory.item_count, fp);
    std::fwrite(memory.item_index, sizeof(T), memory.item_count, fp);
}

// Fast vs slow lookup using compile time map vs std::map
struct IClassWriter
{
    std::string className;
    virtual bool write(const void* data, std::FILE* fp) = 0;
};

template<typename T>
class ClassWriter : public IClassWriter {
public:
    bool write(const void* data, std::FILE* fp) override
    {

        if(writeMethod == nullptr) return false;
        std::cout<<className<<" is being ran currently "<<std::endl;
        return writeMethod((T*)data, fp);
    }
    ClassWriter(bool (*pFunction)(const T* data, std::FILE*), const std::string& _className)
    {
        writeMethod = pFunction;
        className = _className;
    }
private:
    bool (*writeMethod)(const T* data, std::FILE*) = nullptr;
};

struct Camera
{
    int x = 12;
    int y = 15;
    int z = 90;
    double yaw =  30.3;
};

bool writeCameraData(const Camera* data, std::FILE* fp)
{
    if(fp == nullptr) return false;
    if(data->x != 12) return false;
    if(data->y != 15) return false;
    if(data->z != 90) return false;
    if(data->yaw != 30.3) return false;
    std::fwrite(data, sizeof(Camera), 1, fp);
    return true;
}

bool readCameraData(Camera* data, std::FILE* fp)
{
    if(fp == nullptr) return false;
    std::fread(data, sizeof(Camera), 1, fp);
}




TEST(InMemoryTest, TestClassWriter)
{
    std::FILE* fp = nullptr;
    fp = std::fopen("ClassWriterCamera.bin", "wb");
    Camera camera;
    ClassWriter CW(writeCameraData, "Camera");
    ASSERT_TRUE(CW.write(&camera, fp));
    camera.x = 13;
    ASSERT_FALSE(CW.write(&camera, fp));

    IClassWriter* ICW = &CW;
    ICW->write(&camera,fp);

    std::fclose(fp);
    std::freopen("ClassWriterCamera.bin", "rb", fp);
    Camera cameraRead;
    cameraRead.x =30;
    cameraRead.y = 70;
    cameraRead.yaw = 1.05;
    readCameraData(&cameraRead,fp);
    ASSERT_EQ(cameraRead.yaw, 30.3);
}


TEST(InMemoryTest, TestFilerReading)
{
    unsigned int item_count = 5;
    unsigned int items[item_count];

    for(int i = 0 ; i < item_count; ++i)
    {
        items[i] = i*2;
    }

    MemoryBag bag;
    bag.count = item_count;
    bag.item_index = items;

    bagReader(bag);

    FILE* fp;
    // Open/Create a binary file for writing the struct to
    fp = std::fopen("binary_file_test1.bin", "wb");

    std::fputc(item_count, fp);
    std::fwrite(items, sizeof(unsigned int), item_count, fp);
    std::fclose(fp);


    std::freopen("binary_file_test1.bin", "rb", fp);
    unsigned int fileItems;
    fileItems = std::fgetc(fp);
    // get the read buffer
    unsigned int* fileData = (unsigned int*)malloc(sizeof(unsigned int)* fileItems);
    std::cout<<"Reading from the file "<<fileItems<<" items"<<std::endl;
    std::fread(fileData, sizeof(unsigned int), fileItems, fp);
    for(int i = 0; i < fileItems; ++i)
    {
        std::cout<<fileData[i]<<" ";
    }
    std::cout<<std::endl;


}

/*

TEST(AllocateMemory, TypeContainer)
{
    MyAllocator<int> int_array;
    int array[30];
    for(int i = 0; i < 30; i++)
    {
        int_array.push_back(i);
        array[i] = i;
    }

    for(int i = 0; i < 30; i++)
    {
        ASSERT_EQ(array[i], int_array[i]);
    }
    int_array.
    ASSERT_EQ(int_array.)
}
*/
