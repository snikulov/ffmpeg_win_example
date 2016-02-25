#include <iostream>

extern "C" 
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"
}

int main(int argc, const char *argv[])
{
    av_register_all();
    avcodec_register_all();
    avformat_network_init();
    avdevice_register_all();
    unsigned ver = avdevice_version();
    std::cout << ((ver >> 16) & 0xff) << "." << ((ver >> 8) & 0x0f) << "." << ((ver) & 0x0f) << std::endl;
    
//    std::cout << avdevice_configuration() << std::endl;


    AVOutputFormat * odev = av_output_audio_device_next(NULL);
    while (odev)
    {
        std::cout << odev->name << std::endl;
        odev = av_output_audio_device_next(odev);
    }

    AVInputFormat *idev = av_input_audio_device_next(nullptr);
    while (idev)
    {
        std::cout << idev->name << " " << idev->long_name << std::endl;
        idev = av_input_audio_device_next(idev);
    }
    return 0;
}
