#include "tags.h"
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <sstream>

std::vector<RBLCAM001::TagStruct> processTags(std::string fileName){
    std::vector<std::string> lines;
    std::ifstream in(fileName);
    std::string tag;
    std::string pair;
    std::string data;

    if(!in)
    {
        std::cout << "Could not open file" << std::endl;
    }
    
    std::string line;
    while(std::getline(in, line)){
        lines.push_back(line);
    }
    
    for (size_t i = 0; i < lines.size(); i++)
    {
        std::string processLine = lines[i];
        for (size_t j = 0; j < processLine.length(); j++)
        {
            if (processLine[j]=='<')
            {
                int count=0;
                while(processLine[j+count]!='>'){
                    count++;
                }
                tag = processLine.substr(j,count);
            }
            
        }
        
    }
    
}