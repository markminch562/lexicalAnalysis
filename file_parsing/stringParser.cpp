//
// Created by Mark Minch  on 10/22/23.
//

#include "parsing/stringParser.h"

namespace Parser
{
    const char* strspan(const char* src, const char* items)
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
        }
        return nullptr;
    }


}