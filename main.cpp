#include <iostream>
#include <string>
#include "inputValidation.h"

// LUHN ALGORITHM https://www.geeksforgeeks.org/program-credit-card-number-validation/

void conversioneStringToInt(int lunghezzaNumCarta, int numberArray[], std::string s_nCartaInput);
void conversioneIntToString(int double1, int &num1Tmp, int &num2Tmp);

int main()
{
    std::string s_nCartaInput;
    int numberArray[30];
    int arrayStep2[30];
    char cControl;
    int double1, num1Tmp, num2Tmp;
    int j = 0, sum1 = 0, sum2 = 0, finalSum = 0;

    do
    {
        getInput(s_nCartaInput, "Insert your credit card number: ");

        std::cout << "Your credit card number is: " << s_nCartaInput << std::endl;

        getInput(cControl, "Is it correct? Yes(y) or Not(n): ");
    }while(cControl=='n');


    int lunghezzaNumCarta = s_nCartaInput.length();

    conversioneStringToInt(lunghezzaNumCarta, numberArray, s_nCartaInput);

    // Luhn Algorithm
    for (int i = lunghezzaNumCarta - 2; i >= 0; i = i - 2) // double every second digit from right to left
    {
        // step 1
        double1 = numberArray[i] * 2;

        if (double1 > 9)
        {
            conversioneIntToString(double1, num1Tmp, num2Tmp);

            arrayStep2[j] = num1Tmp + num2Tmp;
            j++;
        }
        else
        {
            // Number for step 2
            arrayStep2[j] = double1;
            j++;
        }
    }

    // sum step 2
    for (int i = 0; i < j; i++)
    {
        sum1 = sum1 + arrayStep2[i];
    }

    // sum step 3
    if (lunghezzaNumCarta % 2 == 0)
    {
        for (int i = lunghezzaNumCarta - 1; i >= 0; i--)
        {
            if (i % 2 != 0) 
            {
                sum2 = sum2 + numberArray[i];
            }
        }
    }
    else
    {
        for (int i = lunghezzaNumCarta - 1; i >= 0; i--)
        {
            if (i % 2 == 0) // We need to check if is even because array starts at 0,so the odd places are the even places.
            {
                sum2 = sum2 + numberArray[i];
            }
        }
    }

    // final sum step 4
    finalSum = sum1 + sum2;

    // step 5
    if (finalSum % 10 == 0)
    {
        std::cout << "VALID credit card number" << std::endl;
    }
    else
    {
        std::cout << "INVALID credit card number" << std::endl;
    }
return 0;
}


void conversioneStringToInt(int lunghezzaNumCarta, int numberArray[], std::string s_nCartaInput)
{
    // conversion from string to int with ASCII
    for (int i = 0; i < lunghezzaNumCarta; i++)
    {
        numberArray[i] = (int)s_nCartaInput[i] - 48; //-48 cause 0 in ascii is 48 and 9 is 57 so we need to stay in this range
    }
}

void conversioneIntToString(int double1, int &num1Tmp, int &num2Tmp)
{
    std::string tmpToString = std::to_string(double1);
    num1Tmp = (int)tmpToString[0] - 48;
    num2Tmp = (int)tmpToString[1] - 48;
}
