//
// Created by Mark Minch  on 11/25/23.
//

#include "string/pString.h"
#include <assert.h>
#define EMPTY 0

pString::pString(char* source, bool useStack)
{
    this->useStack = useStack;
    size = strlen(source);
    buffer_size = sizeof(char)*size;
    if(!useStack)
    {
        string = (char*)malloc(buffer_size);
        strcpy(string, source);
    }
    else
    {
        string = source;
    }
}

size_t adjustLength(char *source, size_t length)
{
    size_t str_length = strlen(source);
    // nothing to copy
    if(str_length == EMPTY) return 0;
    if(length > str_length || length == EMPTY)
    {
        length = str_length;
    }
    return length;
}

void pString::append_front(char *source, size_t length) {
    return;
}

void pString::append_back(char *source, size_t length) {


    length = adjustLength(source, length);
    if(length == EMPTY) return;

    size_t remaining_space = buffer_size - (size*sizeof(char));
    size_t source_size = length*sizeof(char);
    // grow buffer if space is needed
    char* buffer = string;
    if(remaining_space < source_size)
    {
        buffer = (char*)malloc(buffer_size+source_size);
        strncpy(buffer, string, size*sizeof(char));
        buffer_size = buffer_size+source_size;

        if(useStack)
        {
            useStack = false;
        }
        else
        {
            free(string);
        }
        string = buffer;
    }

    strncpy(buffer+size, source, source_size);
    size = size+length;
}

void pString::insert(char *source, size_t pose, size_t length)
{
    if(pose >= size)
    {
        append_back(source, length);
        return;
    }
    length = adjustLength(source, length);
    if(length == EMPTY) return;

    //check size
    size_t source_buffer = sizeof(char)*length;
    size_t remaining_buffer = buffer_size - (sizeof(char)*size);
    char* buffer = string;

    if(remaining_buffer < source_buffer)
    {
        buffer_size = source_buffer+buffer_size;
        buffer = (char*)malloc(buffer_size);
    }
    // basically append front
    if(0 == pose)
    {
        strncpy(buffer, source, source_buffer);
        strncpy(buffer+source_buffer, string, size);
    }
    else
    {
        // three copies done
        strncpy(buffer, string, pose);
        strcpy(buffer+pose+length, string+pose);
        char store = buffer[pose+length];
        strncpy(buffer + pose, source, length);
        buffer[pose+length] = store;
    }
    size = length+size;

    // perform cleanup on data
    if(useStack)
    {
        useStack = false;
    }
    else
    {
        free(string);
    }
    string = buffer;
}