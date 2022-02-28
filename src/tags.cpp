#include "tags.h"
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <sstream>
#include <cstring>

std::vector<RBLCAM001::TagStruct> RBLCAM001::processTags(std::string fileName){
    std::vector<std::string> lines;
    std::ifstream in;
    in.open("data/"+fileName);
    std::string tag;
    int pair;
    std::string data;
    std::vector<RBLCAM001::TagStruct> tg;
    if(fileName.empty())
    {
        std::cout << "No filename detected" <<std::endl;
        //return tg;
    }
    if(!in)
    {
        std::cout << "Could not open file "+fileName << std::endl;
        //return tg;
    }

    
    std::string line;
    bool dataStop = false;
    
    while(std::getline(in,line))// for (size_t i = 0; i < lines.size(); i++)
    {
        std::string processLine = line;
        for (size_t j = 0; j < processLine.length(); j++){
            if (processLine[j]=='<' && processLine[j+1]!=' '){
                int count=0;
                while(processLine[j+count]!='>'){
                    count++;
                }
                std::cout << count << std::endl;

                if((processLine.substr(j+1,count-1)).find('/') == std::string::npos){
                    tag = processLine.substr(j+1,count-1);
                }
                else{
                    std::cout << "hey buddy" << std::endl;
                    dataStop = true;
                    //data = processLine.substr();
                }
                std::cout << tag << std::endl;
                j+=count;
            }
            else{
                if(dataStop){
                    std::cout << data << std::endl;
                    RBLCAM001::TagStruct tagToAdd ;
                    tagToAdd.name = tag;
                    tagToAdd.pairs = pair;
                    tagToAdd.text = data;
                    tg.push_back(tagToAdd);
                    dataStop = false;
                }
                data.append(1, processLine[j]);
                //std::cout << data << std::endl;
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

std::string RBLCAM001::listTags(std::string tagName, std::vector<RBLCAM001::TagStruct> tagVector){
    std::string temp;
    for (size_t i = 0; i < tagVector.size(); i++)
    {
        if(tagVector[i].name == tagName)
        {
            
            temp = tagVector[i].name + "," + std::to_string(tagVector[i].pairs) + "," + tagVector[i].text;
            return temp;
        }
    }
    return temp;
}