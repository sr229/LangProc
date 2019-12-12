// LanguageProcessing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dictionary.h"
#include "TokenParser.h"
#include <string>
#include <vector>

int main()
{
    std::string rawSentence;
    Dictionary dict;
    TokenParser tp;

    // first things first: let's init the Dictionary
    std::cout << "Reading Dictionary files...";

    dict.init();
    std::cout << "Done!" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Welcome to Project Jisho " << std::endl;
    std::cout << "======================== " << std::endl;
    std::cout << std::endl;
    std::cout << "A project made with <3 by: " << std::endl;
    std::cout << std::endl;
    std::cout << "* Ralph Wilson C. Aguilar" << std::endl;
    std::cout << "* Jessica Antoinette O. Muelan" << std::endl;
    std::cout << "* Abdul Aziz D. Pangcoga" << std::endl;
    std::cout << "* Adriel Joshua M. Vale" << std::endl;
    std::cout << std::endl;


    // let's listen for the output now
    while (true)
    {
        std::cout << "Please enter your sentence (5 words maximum, enter e to exit): ";
        std::getline(std::cin, rawSentence);

        if (rawSentence != "e")
        {
            // TODO: put token processing here.
            auto tokens = tp.getTokens(rawSentence);
        }
        else
        {
            break;
        }
    }
}