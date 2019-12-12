#include "Dictionary.h"

void Dictionary::init()
{
	namespace fs = std::filesystem;
	
	// we'll read from the files. This'll take a while.
	fs::path rawPath = fs::current_path();
	std::string cwd = rawPath.string();


	std::ifstream adjDictFile(cwd + "\\dictionary_adjectives.txt");
	std::ifstream verbsDictFile(cwd + "\\dictionary_verbs.txt");
	std::ifstream nounsDictFile(cwd + "\\dictionary_nouns.txt");
	std::ifstream pronounsDictFile(cwd + "\\dictionary_pronouns.txt");
	std::ifstream conjDictFile(cwd + "\\dictionary_conjunctions.txt");
	std::ifstream prepDictFile(cwd + "\\dictionary_preposition.txt");
	std::ifstream articleDictFile(cwd + "\\dictionary_articles.txt");

	if (adjDictFile.good() && verbsDictFile.good() && nounsDictFile.good() && pronounsDictFile.good() && conjDictFile.good() && prepDictFile.good() && articleDictFile.good())
	{

		std::string currentAdJStream;
		std::string currentNounStream;
		std::string currentVerbStream;
		std::string currentPronounStream;
		std::string currentConjunctionStream;
		std::string currentPrepositionStream;
		std::string currentArticleStream;

		std::stringstream buf;

		// read adjective file first
		if (adjDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_adjectives.txt ";
			while (adjDictFile >> currentAdJStream && !adjDictFile.eof())
			{
				Dictionary::adjectives.push_back(currentAdJStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}

		if (nounsDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_nouns.txt ";
			while (nounsDictFile >> currentNounStream && !nounsDictFile.eof())
			{
				Dictionary::nouns.push_back(currentNounStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}

		if (verbsDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_verbs.txt ";
			while (verbsDictFile >> currentVerbStream && !verbsDictFile.eof())
			{
				Dictionary::verbs.push_back(currentVerbStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}

		if (pronounsDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_pronouns.txt ";
			while (pronounsDictFile >> currentPronounStream && !pronounsDictFile.eof())
			{
				Dictionary::pronouns.push_back(currentPronounStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}

		if (prepDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_preposition.txt ";
			while (prepDictFile >> currentPrepositionStream && !prepDictFile.eof())
			{
				Dictionary::prepositions.push_back(currentPrepositionStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}

		if (conjDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_conjunctions.txt ";
			while (conjDictFile >> currentConjunctionStream && !conjDictFile.eof())
			{
				Dictionary::conjunctions.push_back(currentConjunctionStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}

		if (articleDictFile.is_open())
		{
			std::cout << "READFILE: dictionary_articles.txt ";
			while (articleDictFile >> currentArticleStream && !articleDictFile.eof())
			{
				Dictionary::articles.push_back(currentArticleStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
	}
	else
	{
		std::cout << "Cannot read dictionary files! Program will now exit." << std::endl;
		throw 127;
	}
}

bool Dictionary::isTokenAdj(std::string token)
{
	return (std::find(Dictionary::adjectives.begin(), Dictionary::adjectives.end(), token) != Dictionary::adjectives.end());
}

bool Dictionary::isTokenPronoun(std::string token)
{
	return (std::find(Dictionary::pronouns.begin(), Dictionary::pronouns.end(), token) != Dictionary::pronouns.end());
}

bool Dictionary::isTokenNoun(std::string token)
{
	return (std::find(Dictionary::nouns.begin(), Dictionary::nouns.end(), token) != Dictionary::nouns.end());
}

bool Dictionary::isTokenVerb(std::string token)
{
	return (std::find(Dictionary::verbs.begin(), Dictionary::verbs.end(), token) != Dictionary::verbs.end());
}

bool Dictionary::isTokenPreposition(std::string token)
{
	return (std::find(Dictionary::prepositions.begin(), Dictionary::prepositions.end(), token) != Dictionary::prepositions.end());
}

bool Dictionary::isTokenConjunction(std::string token)
{
	return (std::find(Dictionary::conjunctions.begin(), Dictionary::conjunctions.end(), token) != Dictionary::conjunctions.end());
}

bool Dictionary::isTokenArticle(std::string token)
{
	return (std::find(Dictionary::articles.begin(), Dictionary::articles.end(), token) != Dictionary::articles.end());
}

// DEPRECATED FUNCTION: DO NOT USE.
bool Dictionary::isWithinDictionary(std::string token)
{
	Dictionary dict;
	bool adjCheck = std::find(dict.adjectives.begin(), dict.adjectives.end(), token) != dict.adjectives.end();
	bool nounCheck = std::find(dict.nouns.begin(), dict.nouns.end(), token) != dict.nouns.end();
	bool verbCheck = std::find(dict.verbs.begin(), dict.verbs.end(), token) != dict.verbs.end();
	bool pronounCheck = std::find(Dictionary::pronouns.begin(), Dictionary::pronouns.end(), token) != Dictionary::pronouns.end();
	bool conjunctionCheck = std::find(Dictionary::conjunctions.begin(), Dictionary::conjunctions.end(), token) != Dictionary::conjunctions.end();
	bool prepositionCheck = std::find(Dictionary::prepositions.begin(), Dictionary::prepositions.end(), token) != Dictionary::prepositions.end();

	return (adjCheck && nounCheck && verbCheck && pronounCheck && conjunctionCheck && prepositionCheck);
}
