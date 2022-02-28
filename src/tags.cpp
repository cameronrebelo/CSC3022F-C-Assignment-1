#include "tags.h"
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <sstream>
#include <cstring>

std::vector<RBLCAM001::TagStruct> RBLCAM001::processTags(std::string fileName){
    std::vector<std::string> lines;
    std::ifstream in(fileName);
    std::string tag;
    std::string pair;
    std::string data;
    std::vector<RBLCAM001::TagStruct> tg;
    if(!in)
    {
        std::cout << "Could not open file" << std::endl;
    }
    
    std::string line;
    while(std::getline(in, line)){
        lines.push_back(line);
        //line.find_first_of
    }
    
    for (size_t i = 0; i < lines.size(); i++)
    {
        std::string processLine = lines[i];
        for (size_t j = 0; j < processLine.length(); j++)
        {
            if (processLine[j]=='<' && processLine[j+1]!=' ')
            {
                int count=0;
                while(processLine[j+count]!='>'){
                    count++;
                }
                tag = processLine.substr(j,count);
                // if (tag.find("\ ") != std::string::npos) {
                //     std::cout << "found!" << '\n';
                // }
            }

        }
        
    }
    return tg;
}

void RBLCAM001::dumpTags(){

}
std::string RBLCAM001::printTags(){
    return "Hey you did it";
}