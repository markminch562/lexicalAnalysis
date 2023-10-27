//
// Created by Mark Minch  on 10/22/23.
//

#ifndef LEXICALANALYSIS_STRINGPARSER_H
#define LEXICALANALYSIS_STRINGPARSER_H
#include <stdio.h>
#include <stdlib.h>
namespace Parser
{
    /**
     * takes the source input and returns a const char* to the first place in
     * src where a char value in items appears, if none appear it returns nullptr
     * @param src input string to be searched
     * @param items input list of char items to search for
     * @return
     */
    const char* strspan(const char* src, const char* items);

    struct bracketSubstring
    {
        size_t startPose;
        size_t endPose;
    };

    size_t getBrackets(const char* src);
}
#endif //LEXICALANALYSIS_STRINGPARSER_H
