#include <iostream>

// ALGORITMO DI LUHN https://www.geeksforgeeks.org/program-credit-card-number-validation/

// DA IMPLEMENTARE ROBA (mettere qualche controllo,implementare classi ma non so se utile)

void conversioneStringToInt(int lunghezzaNumCarta, int numberArray[], std::string s_nCartaInput);
void conversioneIntToString(int double1, int &num1Tmp, int &num2Tmp);

int main()
{
    std::string s_nCartaInput;
    int numberArray[30];
    int arrayStep2[30];

    int double1, num1Tmp, num2Tmp;
    int j = 0, sum1 = 0, sum2 = 0, finalSum = 0;

    std::cout << "Inserisci i numeri della tua carta di credito: ";

    std::cin >> s_nCartaInput;

    std::cout << "Il numero di carta inserito e': " << s_nCartaInput << "\n";

    int lunghezzaNumCarta = s_nCartaInput.length();

    conversioneStringToInt(lunghezzaNumCarta, numberArray, s_nCartaInput);

    // Algoritmo di Luhn
    for (int i = lunghezzaNumCarta - 2; i >= 0; i = i - 2) // double every second digit from right to left
    {

        double1 = numberArray[i] * 2;

        if (double1 > 9)
        {
            // bisogna sommare le due cifre per ottenere il numero a cifra singola da utilizzare per lo step 2
            // provo a convertire il numero in un array di char,per poi ri-convertire l'array di char in un array di integers
            conversioneIntToString(double1, num1Tmp, num2Tmp);

            arrayStep2[j] = num1Tmp + num2Tmp;
            j++;
        }
        else
        {
            // conservare il numero a cifra singola da utilizzare per lo step 2
            arrayStep2[j] = double1;
            j++;
        }
    }

    // somma step 2
    for (int i = 0; i <= j; i++)
    {
        sum1 = sum1 + arrayStep2[i];
    }

    // somma step 3
    for (int i = lunghezzaNumCarta - 1; i >= 0; i--)
    {
        if (i % 3 == 0)
        {
            sum2 = sum2 + numberArray[i];
        }
    }

    // somma finale step 4
    finalSum = sum1 + sum2;

    // step 5
    if (finalSum % 10 == 0)
    {
        std::cout << "Numero carta VALIDO" << std::endl;
    }
    else
    {
        std::cout << "Numero carta INVALIDO" << std::endl;
    }
return 0;
}


void conversioneStringToInt(int lunghezzaNumCarta, int numberArray[], std::string s_nCartaInput)
{
    // Conversione da string a int tramite ascii
    for (int i = 0; i < lunghezzaNumCarta; i++)
    {
        numberArray[i] = (int)s_nCartaInput[i] - 48; //-48 perchè in ascii lo 0 sarebbe 48 e il 9 sarebbe 57 quindi dobbiamo rimanere in quel range
    }
}

void conversioneIntToString(int double1, int &num1Tmp, int &num2Tmp)
{
    std::string tmpToString = std::to_string(double1);
    num1Tmp = (int)tmpToString[0] - 48;
    num2Tmp = (int)tmpToString[1] - 48;
}