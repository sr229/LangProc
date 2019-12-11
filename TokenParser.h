/*
 * Copyright 2019 Ayane Satomi, et al.
 * Licensed under MIT
 * for CS-1101 Final
*/
#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <cctype>

class TokenParser
{
public:
    // processes raw string input into a vector
    // which we can programmatically filter and categorize
	std::vector<std::string> getTokens(std::string input);
private:
    // checks if our token is alpha-numeric.
   // this is useful if we just want to analyze words from the the vector.
	bool isTokenAlphaNumeric(std::string input);
};