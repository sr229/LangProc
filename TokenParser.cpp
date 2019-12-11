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
	std::regex word_regex("(\\w+)");
	auto words_begin = std::sregex_iterator(input.begin(), input.end(), word_regex);
	auto words_end = std::sregex_iterator();

	// we split the words using a regex-based approach, then feed it to a vector.
	// How this works is basically the regex matches all known words, removing non alphanumeric characters.
	// then iterates over all that matched and is pushed into the vector.
	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		std::smatch match = *i;
		std::string matched_tokens = match.str();

		tokens.push_back(matched_tokens);
	}

	return tokens;
}

// checks if our token is alpha-numeric.
// this is useful if we just want to analyze words from the the vector.
bool TokenParser::isTokenAlphaNumeric(std::string input)
{
	// its easier to do it in regex since we're matching a whole lot of tokens.
	std::regex alphaNumericRegex("^[a-z0-9\\s]+");

	return (!std::regex_match(input, alphaNumericRegex));
}