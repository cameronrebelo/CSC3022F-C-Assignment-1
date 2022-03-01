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
    int pair = 1;
    std::string data;
    std::vector<RBLCAM001::TagStruct> tg;
    if(fileName.empty())
    {
        std::cout << "No filename detected" <<std::endl;
        return tg;
    }
    if(!in)
    {
        std::cout << "Could not open file "+fileName << std::endl;
        return tg;
    }

    
    std::string line;
    bool dataStop = false;
    bool exists = false;
    
    while(std::getline(in,line))
    {
        std::string processLine = line;
        for (size_t j = 0; j < processLine.length(); j++){
            if (processLine[j]=='<' && processLine[j+1]!=' '){
                int count=0;
                while(processLine[j+count]!='>'){
                    count++;
                }
                if((processLine.substr(j+1,count-1)).find('/') == std::string::npos){
                    tag = processLine.substr(j+1,count-1);
                }
                else{
                    dataStop = true;
                    for (size_t i = 0; i < tg.size(); i++)
                    {
                        if(tag==tg[i].name){
                            exists = true;
                            pair++;
                            tg[i].text.append(":"+data);
                            tg[i].pairs=(tg[i].pairs+1);
                        }
                    }
                    if(dataStop&&!exists){
                        RBLCAM001::TagStruct tagToAdd ;
                        tagToAdd.name = tag;
                        tagToAdd.pairs = pair;
                        tagToAdd.text = data;
                        tg.push_back(tagToAdd);
                        dataStop = false;
                        data = "";
                        pair = 1;
                    }
                    else if (dataStop&&exists){  
                        data = "";
                        pair = 1;
                        exists = false;
                        dataStop = false;
                    }
                }
                j+=count;
            } 
            else{
                data.append(1, processLine[j]);
            }

        }
        
    }
    return tg;
}

void RBLCAM001::dumpTags(std::vector<RBLCAM001::TagStruct> tagVector){
    std::ofstream out("data/tags.txt");
    std::string temp="";
    for (size_t i = 0; i < tagVector.size(); i++)
    {
        temp+= (tagVector[i].name + "," + std::to_string(tagVector[i].pairs) + "," + tagVector[i].text)+"\n";
    } 
    out << temp;
    std::cout << "Wrote to file" << std::endl;
}
void RBLCAM001::printTags(std::vector<RBLCAM001::TagStruct> tagVector){
    for (size_t i = 0; i < tagVector.size(); i++)
    {
        std::cout << (tagVector[i].name + "," + std::to_string(tagVector[i].pairs) + "," + tagVector[i].text) << std::endl;
    }   
}

std::string RBLCAM001::listTags(std::string tagName, std::vector<RBLCAM001::TagStruct> tagVector){
    std::string temp=" ";
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