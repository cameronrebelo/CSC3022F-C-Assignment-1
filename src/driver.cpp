#include "tags.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main(){
    std::cout << "test" << std::endl;
    std::cout << "Welcome to the tag processing factory!\nPlease type an option and press return\nr: Read and process tag data\np: Print all tags\nd: Write tags to file\nl: List data for specific tag\nq: Exit the factory" << std::endl;
    std::vector<RBLCAM001::TagStruct> tagVector;
    while(true){
        std::string input; 
        std::cin >> input;
        if(input=="r"){
            std::cout << "Enter the name of the file to process" << std::endl;
            std::string filename;
            std::cin >> filename;
            tagVector = RBLCAM001::processTags(filename);
            //read function
        }
        else if(input=="p"){
            std::cout << "Printing" << std::endl;
            RBLCAM001::printTags(tagVector);
            //print function
        }
        else if(input=="d"){
            std::cout << "Dumping" << std::endl;
            //dump function
        }
        else if(input=="l"){
            std::cout << "Listing" << std::endl;
            std::string tagName;
            std::cin >> tagName;
            std::string foundTag;
            if(!tagVector.empty())
            {
                foundTag = RBLCAM001::listTags(tagName,tagVector);
            }
            //output found data
        }
        else if(input=="q"){ //quit function
            std::cout << "Quiting" << std::endl;
            return 0;
        }
        else{
            std::cout << "Looks like you didnt select anything, try again" << std::endl;
        }
    std::cout << "Please type an option and press return\nr: Read and process tag data\np: Print all tags\nd: Write tags to file\nl: List data for specific tag\nq: Exit the factory" << std::endl;        
    }
    //return 0;
}
