driver.cpp:
    driver class of the program that handles the input from the user. 
    Links to all other functions and then displays the correct info back to the user

tags.cpp:
    class that contains all the functions for the programs.
    contains:
        - processing data function that accepts a file name and then returns a vector of TagStructs containg the formatted tag data
        - print all function that lists all the data in a vector of TagStructs paramater
        - list all function that lists all the data of a vector of TagStructs that matches a given tag
        - dump function that writes given TagStruct vector data to a file called tags.txt 

tags.h:
    header class

NOTE:   when typing the name of the file containing data, the program automatically adds "data/" as a prefix
        therefore any test files must be placed in the data directory.

        Also note that the makefile generates an executable file called tagrun.exe 
