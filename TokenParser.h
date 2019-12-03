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
	std::vector<std::string> getTokens(std::string input);
private:
	bool isTokenAlphaNumeric(std::string input);
};