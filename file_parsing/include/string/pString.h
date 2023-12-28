//
// Created by Mark Minch  on 11/25/23.
//

#ifndef LEXICALANALYSIS_PSTRING_H
#define LEXICALANALYSIS_PSTRING_H
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

struct pString
{
    size_t size;
    size_t buffer_size;
    char* string;
    bool useStack;
    pString(char* source, bool useStack = true);
    /**
     * Adds the char array data to string for "length" or until null termination
     * @param source char array data to add to pString
     * @param length max number char values to take from source, will go to null terminator if length is zero
     */
    void append_back(char* source, size_t length = 0);
    void append_front(char* source, size_t length = 0);
    void insert(char* source, size_t pose, size_t length = 0);

    // todo
    /*
    void cat(pString source, size_t length = 0);
    void cat(char* source, size_t length);
    */

};

void resize(pString* string_source, size_t bytes);

#endif //LEXICALANALYSIS_PSTRING_H
