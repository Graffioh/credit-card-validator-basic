#pragma once

#include <iostream>
#include <string>
#include <limits>



template<typename T>
void getInput(T& input, const std::string msg)
{
    std::cout << msg << std::endl;
    std::cin >> input;

    while (std::cin.fail()) // Input validation using limits library
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input error,please try again\n";

        std::cout << msg << std::endl;  
        std::cin >> input;
    }
}

// number with spaces
/*void getInput(std::string& input, const std::string msg)
{
    std::cout << msg << std::endl;
    std::cin.ignore();
    std::getline(std::cin,input);


    while (std::cin.fail())  // Input validation using limits library
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input error,please try again\n";

        std::cout << msg << std::endl;  
        std::getline(std::cin,input);
    }
   
}*/