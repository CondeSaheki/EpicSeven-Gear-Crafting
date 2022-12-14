#pragma once
#include <iostream>

// #define windows 
#define windows

namespace neto
{
    void clear()
    {
        #ifdef windows
        system("cls");
        #endif
        #ifdef linux
        system("clear");
        #endif
    }
}


#ifdef linux
#undef linux
#endif
#ifdef windows
#undef windows
#endif