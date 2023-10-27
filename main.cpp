#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <iostream>

#include "parsing/stringParser.h"
/*
 * I want this file to read its own source code and then output blocks about it to the screen
 *
 */

/*
struct tokenPoses
{
    int start;
    int end;
};

// grabs block of text and chunks it
int getBlock(const char* stringP, int start)
{
    int end = start;
    while(stringP[end] != ' ' && stringP[end] != '\0')
    {
        end++;
    }
    return end;
}

char* bufferCopy(char* strBuffer,unsigned int start,  unsigned int end)
{
    unsigned int length = end-start;
    char* block = (char*)malloc(length+1);
    strncpy(block, strBuffer+start, length);
    return block;
}

void parseTokens(char* stringBuffer, size_t size)
{
    // find all the white space in the string
    // tokens are first put into a simple buffer
    // then if we run out of space in the token buffer we will create a new buffer and copy the data into it
    tokenPoses tokenBuffer[20];
    int end = 0;
    while(stringBuffer[end] != ' ' && stringBuffer[end] != '\0')
    {
        end++;
    }
    return ;
}

int* spaceIndex(const char* stringData, size_t length)
{
    // create buffer just as long as the string we are working with
    int* tokenIndex = (int*)malloc(length*sizeof(int));
    memset(tokenIndex, -1, length*sizeof(int));
    int index = 0;
    for(int i = 0; i < length; ++i)
    {
        if(stringData[i] == ' ' || stringData[i] == '\0')
        {
            tokenIndex[index] = i;
            ++index;
        }
    }
    return tokenIndex;
}

void spaceIndexToTokens(const char* stringData, size_t length, int* tokenIndex)
{
    if (length == 0) return;
    int tokenStart = 0;
    for(int i = 0; i < length; ++i)
    {
        if(tokenIndex[i] == -1) break;
        if(tokenIndex[i] != tokenStart)
        {
            printf("word found of: %.*s\n", (tokenIndex[i] - tokenStart), stringData +tokenStart);
        }
        tokenStart = tokenIndex[i]+1;
    }
}

void runTokenIndex(const char* string)
{
    size_t stringSize = strlen(string);
    int* TokenIndex = nullptr;
    TokenIndex = spaceIndex(string, stringSize);
    spaceIndexToTokens(string, stringSize, TokenIndex);
}

void collectToken(const char* stringData, size_t length)
{
    size_t tokenStart = 0;
    size_t tokenEnd = 0;
    for(int i = 0; i <= length; ++i) {
        if (stringData[i] >= '!' && stringData[i] <= '~')
        {
            tokenEnd = i;
        }
        else
        {
            // reset condition
            if(tokenStart != tokenEnd)
            {
                printf("word found of: %.*s\n", (tokenEnd - tokenStart), stringData + tokenStart);
            }
            tokenStart = tokenEnd;
        }
    }
}

int getFirstLetter(const char* stringData, size_t stringLength, size_t startPose)
{
    int i = startPose;
    while(i < stringLength)
    {
        if (stringData[i] >= '!' && stringData[i] <= '~') break;
        ++i;
    }
    return i;
}

int getFirstNonLetter(const char* stringData, size_t stringLength, size_t startPose)
{
    int i = startPose;
    while(i < stringLength)
    {
        if (stringData[i] < '!' || stringData[i] > '~') break;
        ++i;
    }

    return i;
}

int printWord(const char* stringData, size_t length)
{
    int startParse = 0;
    char stringBuffer[40];

    int FirstLetter = getFirstLetter(stringData, length, startParse);
    int FirstSpace = getFirstNonLetter(stringData, length, startParse);
    if(FirstSpace > FirstLetter)
    {
        strncpy(stringBuffer, stringData+startParse, FirstSpace - FirstLetter);
        stringBuffer[FirstSpace - FirstLetter] = '\0';
        printf("\n new word: %s", stringBuffer);
    }
    else
    {
        startParse = FirstLetter;
    }
    return startParse;
}

size_t printBracket(const char* stringData, size_t length, size_t startPose)
{
    bool foundStart = false;
    bool foundEnd = false;
    int pose = startPose;
    int startBracket = 0;
    int endBracket = 0;
    while(pose < length && !foundEnd)
    {
        char  letter = stringData[pose];
        if(letter == '{' || letter == '}') {
            if (letter == '{')
            {
                if (foundStart)
                {
                    pose = printBracket(stringData, length, pose);
                } else
                {
                    foundStart = true;
                    startBracket = pose;
                }
            }
            else
            {
                foundEnd = true;
                endBracket = pose;
            }
        }
        pose += 1;
    }
    if(endBracket > startBracket)
    {
        printf("word found of: %.*s\n", ((endBracket + 1) - startBracket), stringData + startBracket);
    }
    return pose;
}

const char* my_strspn(const char* src, const char* items)
{

    for(const char*  pose = src; *pose != 0; ++pose)
    {
        for(const char* p_items = items; *p_items != 0; ++p_items)
        {
            if(*pose == *p_items)
            {
                return pose;
            }
        }
        pose++;
    }
    return src;
}
*/

int main() {

    const char word[] = "Lorem ipsum dolor sit amet, eu eum doctus vocent quaeque. Cu eos mucius animal electram. Vel cu autem inimicus facilisis, ius in dolor sapientem. Te nec corpora vituperatoribus, ea verear nostrum mandamus nam. Labore tincidunt reprehendunt et sed, duo minimum appareat expetenda ne. Ea aliquip necessitatibus est.\n"
                        "\n"
                        "Justo perpetua intellegat cum cu, quo adhuc error ut. Te vidisse civibus pertinacia sit, tempor suscipit et per. Simul omittam iudicabit an quo, omnes aperiam percipit vix ex, ne per iudico sanctus elaboraret. Mea insolens voluptatibus eu, ad nam harum facete quaerendum. Has stet erroribus no. Cu alia movet alienum per, ex tempor commune vix.\n"
                        "\n"
                        "Tation feugiat fabulas et qui. Id euripidis concludaturque qui. Nostrud percipit cu vim, sit ei petentium elaboraret necessitatibus. An cum tractatos intellegebat, ullum utroque qui cu, ei mel liber tantas decore. Option invidunt similique ex mel, illud soleat nemore ei ius, ei admodum recusabo salutandi vel. Et nibh minimum delectus mel, ea vel ubique vivendo, quem legendos pertinacia te mea.\n"
                        "\n"
                        "Est an rebum omittam, option aperiri salutandi vis eu. Mei cu labitur appareat honestatis, ipsum probatus elaboraret his ex. Pericula mnesarchum id vel. Aliquid omittantur id pro. Clita utinam usu at, percipit expetenda reprimique ea vis.\n"
                        "\n"
                        "Erat adipisci definiebas an est, erat deleniti posidonium mea ut, mei ne primis aperiri molestie. Per oporteat cotidieque in, modo augue mundi no sea, qui impedit reformidans ullamcorper ad. Ius ullum voluptua no. Vim id noluisse constituto. Zril dicunt vix ei, usu ut senserit tractatos sadipscing, an eos eruditi constituam.";
    char subString[40000];
    subString[39999] = '\0';
    size_t length = strlen(word); // strlen does count
    /*
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    size_t count = 500000;
    auto t1 = high_resolution_clock::now();
    for(int i = 0; i < count; ++i) {
        strCopy1(word, subString, length);
    }
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms\n";
    */


    //strncpyy(subString,  word, 400);

    //printf("%i length",length);
    //printf("%c", word[length-1]);

    //size_t firstLetter = getFirstLetter(word, length);
    //size_t firstSpace = getFirstNonLetter(word, length);
    //printf("first letter: %c\nlast letter: %c", word[firstLetter], word[firstSpace-1]);
    //printWord(word, length);
    //printBracket(word, length, 0);
    //collectToken(word, strlen(word));

    /*
    char sampleText[] = "- this is some text [we want to find] {brackets} {nested {brackets}} and line ends\nthats cool right //Hello world its mark\n you know you love me";
    char items[] = "[]{}\n";

    const char*  pose = my_strspn(sampleText, items);
    int backslashCount = 0;
    pose = sampleText;
    char uncomment[]  = "/";
    while(*pose != 0)
    {
        pose = my_strspn(pose, uncomment);
        if(*(pose) != 0 && *(pose+1) == '/')
        {
            //printf("found comment of: %s", pose);
            const char* startComment = pose += 2;
            pose = my_strspn(startComment, "\n");
            if(pose == startComment)
            {
                printf("found comment of: %s\n", startComment);
            }
            else
            {
                printf("found comment of: %.*s", (pose - startComment), startComment);
            }
        }
        pose += 1;
    }


     */


    const char text[] = "here is some text { some text in a bracket }, {if(true) { then go to after } }";
    const char searchItem[] = "{}";
    const char* start = Parser::strspan(text, searchItem);
    const char* end  = Parser::strspan(start+1, searchItem);
    printf("original block: %s\n", text);
    printf("word found of: %.*s\n", (end +1) - start, start);

    start = Parser::strspan(text, searchItem);
    while(start != nullptr)
    {
        start = Parser::strspan(start, searchItem);
        if(start != nullptr)
        {
            printf("block %s\n", start);
            start++;
        }
    }

    return 0;
}
