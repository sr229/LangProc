#pragma once
#include <string>
#include <array>

class Dictionary
{
public:
	bool isTokenVerb(std::string token);
	bool isTokenAdj(std::string token);
	bool isTokenNoun(std::string token);
	bool isWithinDictionary(std::string token);
private:
	//TODO: make array
	std::string nouns;
	//TODO: make array
	std::string adjectives;
	//TODO: make array
	std::string verbs;
};

