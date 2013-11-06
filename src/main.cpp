#include <iostream>

extern "C" 
{
#include "libavcodec/avcodec.h"
#include "libavutil/avutil.h"
}

int main(int argc, const char *argv[])
{
    avcodec_register_all();
    return 0;
}
