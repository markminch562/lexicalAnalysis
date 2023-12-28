//
// Created by Mark Minch  on 11/12/23.
//

#include <cstdio>
#include <cstdlib>


struct camera
{
    char camera_name[16];
    int width;
    int height;
    unsigned int scene_id;
    float fov;
};

struct pose
{
    float x;
    float y;
    float z;
};

struct Object {
    pose objectPose;
    float scale;
    unsigned int shader_id;
};

int main(int argc, char** argv)
{
    if(argc <=3)
    {
        printf("Unable no file passed in");
        return -1;
    }
    printf("I have been able to pass file: %s", argv[2]);
    return 0;
}