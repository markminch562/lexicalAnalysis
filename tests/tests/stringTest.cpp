//
// Created by Mark Minch  on 11/25/23.
//
#include "string/pString.h"
int main()
{
    pString testString("Hello");

    if(testString.size != 5)
    {
        return -1;
    }

    char* addedWord = " extra data";
    char* expectedResult = "Hello extra data";

    testString.append_back(addedWord);
    printf("%s\n", testString.string);
    printf("%s\n", expectedResult);

    if(strcmp(expectedResult, testString.string) != 0)
    {
        return -1;
    }



    return 0;
}