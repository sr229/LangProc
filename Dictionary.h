#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <iterator>

class Dictionary
{
public:
	void init();
	bool isTokenVerb(std::string token);
	bool isTokenAdj(std::string token);
	bool isTokenNoun(std::string token);
	bool isTokenPronoun(std::string token);
	bool isTokenPreposition(std::string token);
	bool isTokenConjunction(std::string token);
	bool isTokenArticle(std::string token);

private:
	std::vector<std::string> nouns;
	std::vector<std::string> pronouns;
	std::vector<std::string> verbs;
	std::vector<std::string> adjectives;
	std::vector<std::string> prepositions;
	std::vector<std::string> conjunctions;
	std::vector<std::string> articles;
};

