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

bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

// number with spaces
void getInput(std::string& input, const std::string msg)
{
    do
    {
        std::cout << msg << std::endl;  
        std::cin >> input;

        //std::cin.ignore();
        // std::getline(std::cin,input);

        if(!isNumber(input))
        {
            std::cout << "Input error,please try again\n";
        }
    } while (!isNumber(input));
}
