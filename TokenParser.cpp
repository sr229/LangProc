/*
 * Copyright 2019 Ayane Satomi, et al.
 * Licensed under MIT
 * for CS-1101 Final
*/
#include "TokenParser.h"


// Splits a sentence into meaningful tokens.
// We use a vector-based approach since Arrays can't be used on a input we don't know how long it is
// especially its NLP input. We're not exactly sure how large is input here, so we compensate for that.
std::vector<std::string> TokenParser::getTokens(std::string input)
{
	std::vector<std::string> tokens;
	std::vector<std::string> discardedTokens;
	std::stringstream tokenStream(input);
	std::string intermediate;

	while (std::getline(tokenStream, intermediate))
	{
		// check if our sentences has punctuation marks. 
		// if we do, feed it to a throwaway vector we can clear out later.
		if (!TokenParser::isTokenAlphaNumeric(intermediate))
		{
			discardedTokens.push_back(intermediate);
		}
		else
		{
			tokens.push_back(intermediate);
		}

	}

	// clear out the discarded tokens since we don't need them.
	discardedTokens.clear();
	return tokens;
}

// checks if our token is alpha-numeric.
// this is useful if we just want to analyze words from the the vector.
bool TokenParser::isTokenAlphaNumeric(std::string input)
{
	// its easier to do it in regex since we're matching a whole lot of tokens.
	std::regex alphaNumericRegex("^[a-z0-9\\s]+");

	if (!std::regex_match(input, alphaNumericRegex))
	{
		return false;
	}
	else
	{
		return true;
	}
}