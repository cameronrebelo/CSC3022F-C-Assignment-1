#ifndef _TAGS
#define _TAGS

#include <string>
#include <vector>

namespace RBLCAM001 {

    struct TagStruct{
        std::string name;
        int pairs;
        std::string text;
    };

    std::vector<TagStruct> processTags(std::string filename);
    std::string printTags();
    void dumpTags();
}

#endif 