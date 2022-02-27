#include "driver.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct TagStruct{
    std::string name;
    int pairs;
    std::string text;
};

int RBLCAM001::main(){
    std::cout << "Welcome to the tag processing factory!\nPlease type an option and press return\nr: Read and process tag data\np: Print all tags\nd: Write tags to file\nl: List data for specific tag\nq: Exit the factory" << std::endl;
    while(true){
        std::string input; 
        std::cin >> input;
        if(input=="r"){
            std::cout << "Enter the name of the file to process" << std::endl;
            std::string filename;
            std::cin >> filename;
            //read function
        }
        if(input=="p"){
            std::cout << "Printing" << std::endl;
            //read function
        }
        if(input=="d"){
            std::cout << "Dumping" << std::endl;
            //read function
        }
        if(input=="l"){
            std::cout << "Listing" << std::endl;
            //read function
        }
        if(input=="q"){
            std::cout << "Quiting" << std::endl;
            //read function
        }
        else{
            std::cout << "Looks like you didnt select anything, try again" << std::endl;
        }
    }
    return 0;
}

std::vector<TagStruct> read(std::string fileName){
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
