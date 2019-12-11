#include "Dictionary.h"

void Dictionary::init()
{
	std::ifstream adjDictFile("dictionary_adjectives.txt");
	std::ifstream verbsDictFile("dictionary_verbs.txt");
	std::ifstream nounsDictFile("dictionary_nouns.txt");
	std::ifstream pronounsDictFile("dictionary_pronouns.txt");

	if (adjDictFile.good() && verbsDictFile.good() && nounsDictFile.good() && pronounsDictFile.good())
	{
		
		std::string currentAdJStream;
		std::string currentNounStream;
		std::string currentVerbStream;
		std::string currentPronounStream;

		// stream it to the vectors
		// hopefully it doesn't cause a big ass leak >_<
		while (adjDictFile >> currentAdJStream && verbsDictFile >> currentVerbStream && nounsDictFile >> currentNounStream && pronounsDictFile >> currentPronounStream)
		{
			Dictionary::nouns.push_back(currentNounStream);
			Dictionary::adjectives.push_back(currentAdJStream);
			Dictionary::verbs.push_back(currentVerbStream);
			Dictionary::pronouns.push_back(currentPronounStream);
		}
	}
}

bool Dictionary::isTokenAdj(std::string token)
{
	if (std::find(Dictionary::adjectives.begin(), Dictionary::adjectives.end(), token) != Dictionary::adjectives.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Dictionary::isTokenPronoun(std::string token)
{
	if (std::find(Dictionary::pronouns.begin(), Dictionary::pronouns.end(), token) != Dictionary::pronouns.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Dictionary::isTokenNoun(std::string token)
{
	if (std::find(Dictionary::nouns.begin(), Dictionary::nouns.end(), token) != Dictionary::adjectives.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Dictionary::isTokenVerb(std::string token)
{
	if (std::find(Dictionary::verbs.begin(), Dictionary::verbs.end(), token) != Dictionary::verbs.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Dictionary::isWithinDictionary(std::string token)
{
	Dictionary dict;
	bool adjCheck = std::find(dict.adjectives.begin(), dict.adjectives.end(), token) != dict.adjectives.end();
	bool nounCheck = std::find(dict.nouns.begin(), dict.nouns.end(), token) != dict.nouns.end();
	bool verbCheck = std::find(dict.verbs.begin(), dict.verbs.end(), token) != dict.verbs.end();
	bool pronounCheck = std::find(Dictionary::pronouns.begin(), Dictionary::pronouns.end(), token) != Dictionary::pronouns.end();

	return !(adjCheck && nounCheck && verbCheck && pronounCheck);
}