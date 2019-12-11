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
    std::cout << "Reading Dictionary files..." << std::endl;
    std::cout << std::endl;

    dict.init();

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
    std::cout << "Please enter your sentence (5 words maximum): ";
    std::getline(std::cin, rawSentence);

    // now this is where the fun part begins
    // well at least that's how I learned it to be...
    std::vector<std::string> processedSentence = tp.getTokens((std::string)rawSentence);

}