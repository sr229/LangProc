#include "Dictionary.h"

void Dictionary::init()
{
	std::ifstream adjDictFile("dictionary_adjectives.txt");
	std::ifstream verbsDictFile("dictionary_verbs.txt");
	std::ifstream nounsDictFile("dictionary_nouns.txt");

	if (adjDictFile.good() && verbsDictFile.good() && nounsDictFile.good())
	{
		
		std::string currentAdJStream;
		std::string currentNounStream;
		std::string currentVerbStream;

		// stream it to the vectors
		// hopefully it doesn't cause a big ass leak >_<
		while (adjDictFile >> currentAdJStream && verbsDictFile >> currentVerbStream && nounsDictFile >> currentNounStream)
		{
			Dictionary::nouns.push_back(currentNounStream);
			Dictionary::adjectives.push_back(currentAdJStream);
			Dictionary::verbs.push_back(currentVerbStream);
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

bool Dictionary::isTokenNoun(std::string token)
{
	//TODO
}

bool Dictionary::isTokenVerb(std::string token)
{
	//TODO
}

bool Dictionary::isWithinDictionary(std::string token)
{
	//TODO
}