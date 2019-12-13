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

    dict.init();
    
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
            // process token
            auto tokens = tp.getTokens(rawSentence);
            int lastTokenCount = 0;

            std::cout << "Sentence Analysis: " << std::endl;
            std::cout << "=================================" << std::endl;
            std::cout << "Word\t\tClassification" << std::endl;
            std::cout << "=================================" << std::endl;

            for (const auto& token : tokens)
            {
                int presentTokenCount = token.size() + lastTokenCount;
                lastTokenCount = presentTokenCount;

                if (dict.isTokenAdj(token))
                {
                    std::cout << token << "\t\t" << "adjective" << std::endl;
                }
                else if (dict.isTokenNoun(token))
                {
                    std::cout << token << "\t\t" << "noun" << std::endl;
                }
                else if (dict.isTokenConjunction(token))
                {
                    std::cout << token << "\t\t" << "conjunction" << std::endl;
                }
                else if (dict.isTokenPronoun(token))
                {
                    std::cout << token << "\t\t" << "pronoun" << std::endl;
                }
                else if (dict.isTokenVerb(token))
                {
                    std::cout << token << "\t\t" << "verb" << std::endl;
                }
                else if (dict.isTokenPreposition(token))
                {
                    std::cout << token << "\t\t" << "preposition" << std::endl;
                }
                else if (dict.isTokenArticle(token))
                {
                    std::cout << token << "\t\t" << "article" << std::endl;
                }
                else
                {
                    std::cout << token << "\t\t" << "UNKNOWN" << std::endl;
                }
            }
            std::cout << "---------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "Statistics:";
            std::cout << std::endl;
            std::cout << "Words: " << tokens.size() << std::endl;
            std::cout << "Letters: " << lastTokenCount << std::endl;
        }
        else
        {
            // break the loop
            break;
        }
    }
}