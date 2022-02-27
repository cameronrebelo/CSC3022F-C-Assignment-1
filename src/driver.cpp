#include "driver.h"
#include <string>
#include <iostream>

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
            std::cout << "Reading" << std::endl;
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
