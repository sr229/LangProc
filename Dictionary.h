#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <algorithm>

class Dictionary
{
public:
	void init();
	bool isTokenVerb(std::string token);
	bool isTokenAdj(std::string token);
	bool isTokenNoun(std::string token);
	bool isWithinDictionary(std::string token);

private:
	std::vector<std::string> nouns;
	std::vector<std::string> verbs;
	std::vector<std::string> adjectives;
};

