#include "tags.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(){
    std::cout << "test" << std::endl;
    std::cout << "Welcome to the tag processing factory!\nPlease type an option and press return\nr: Read and process tag data\np: Print all tags\nd: Write tags to file\nl: List data for specific tag\nq: Exit the factory" << std::endl;
    std::vector<RBLCAM001::TagStruct> tagVector;
    while(true){
        std::string input; 
        std::cin >> input;
        if(input=="r"){
            system("clear");
            std::cout << "Enter the name of the file to process" << std::endl;
            std::string filename;
            std::cin >> filename;
            tagVector = RBLCAM001::processTags(filename);
            //read function
        }
        else if(input=="p"){
            system("clear");
            if(tagVector.empty())
            {
                std::cout << "Read in some data first" << std::endl;
            }
            else{
                std::cout << "Printing" << std::endl;
                RBLCAM001::printTags(tagVector);
            }
        }
        else if(input=="d"){
            system("clear");
            if(tagVector.empty())
            {
                std::cout << "Read in some data first" << std::endl;
            }
            else{
                std::cout << "Dumping" << std::endl;
                RBLCAM001::dumpTags(tagVector);
            }
            
            //dump function
        }
        else if(input=="l"){
            system("clear");
            if(tagVector.empty())
            {
                std::cout << "Read in some data first" << std::endl;
            }
            else{
                std::cout << "Enter a tag to search for" << std::endl;
                std::string tagName;
                std::cin >> tagName;
                std::string foundTag;
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
            system("clear");
        }
    system("clear");
    std::cout << "Please type an option and press return\nr: Read and process tag data\np: Print all tags\nd: Write tags to file\nl: List data for specific tag\nq: Exit the factory" << std::endl;        
    }
    //return 0;
}