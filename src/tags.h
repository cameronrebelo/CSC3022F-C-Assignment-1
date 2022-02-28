#ifndef _DRIVER
#define _DRIVER

#include <string>

namespace RBLCAM001 {

    struct TagStruct{
        std::string name;
        int pairs;
        std::string text;
    };

    std::vector<TagStruct> processTags(std::string filename){};
}

#endif 