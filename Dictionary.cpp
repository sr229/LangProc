#include "Dictionary.h"

void Dictionary::init()
{
	std::ifstream adjDictFile("dictionary_adjectives.txt");
	std::ifstream verbsDictFile("dictionary_verbs.txt");
	std::ifstream nounsDictFile("dictionary_nouns.txt");
	std::ifstream pronounsDictFile("dictionary_pronouns.txt");
	std::ifstream conjDictFile("dictionary_conjunctions.txt");
	std::ifstream prepDictFile("dictionary_prepositions.txt");

	if (adjDictFile.good() && verbsDictFile.good() && nounsDictFile.good() && pronounsDictFile.good() && conjDictFile.good() && prepDictFile.good())
	{
		std::string currentAdJStream;
		std::string currentNounStream;
		std::string currentVerbStream;
		std::string currentPronounStream;
		std::string currentConjunctionStream;
		std::string currentPrepositionStream;


		// stream it to the vectors
		// hopefully it doesn't cause a big ass leak >_<
		while (
			std::getline(adjDictFile, currentAdJStream) 
			&& std::getline(verbsDictFile, currentVerbStream)
			&& std::getline(pronounsDictFile, currentPronounStream)
			&& std::getline(nounsDictFile, currentNounStream)
			&& std::getline(conjDictFile, currentConjunctionStream)
			&& std::getline(prepDictFile, currentPrepositionStream)
			)
		{
			Dictionary::nouns.push_back(currentNounStream);
			Dictionary::adjectives.push_back(currentAdJStream);
			Dictionary::verbs.push_back(currentVerbStream);
			Dictionary::pronouns.push_back(currentPronounStream);
			Dictionary::conjunctions.push_back(currentConjunctionStream);
			Dictionary::prepositions.push_back(currentPrepositionStream);
		}

		// finish reading, we don't need it anymore.
		adjDictFile.close();
		verbsDictFile.close();
		nounsDictFile.close();
		pronounsDictFile.close();
		conjDictFile.close();
		prepDictFile.close();
	}
	else
	{
		throw std::invalid_argument("One or more of the required files is missing!");
	}
}

bool Dictionary::isTokenAdj(std::string token)
{
	if (std::find(Dictionary::adjectives.begin(), Dictionary::adjectives.end(), token) != Dictionary::adjectives.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::isTokenPronoun(std::string token)
{
	if (std::find(Dictionary::pronouns.begin(), Dictionary::pronouns.end(), token) != Dictionary::pronouns.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::isTokenNoun(std::string token)
{
	if (std::find(Dictionary::nouns.begin(), Dictionary::nouns.end(), token) != Dictionary::adjectives.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::isTokenVerb(std::string token)
{
	if (std::find(Dictionary::verbs.begin(), Dictionary::verbs.end(), token) != Dictionary::verbs.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::isTokenPrepoistion(std::string token)
{
	if (std::find(Dictionary::prepositions.begin(), Dictionary::prepositions.end(), token) != Dictionary::prepositions.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::isTokenConjunction(std::string token)
{
	if (std::find(Dictionary::conjunctions.begin(), Dictionary::conjunctions.end(), token) != Dictionary::conjunctions.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::isWithinDictionary(std::string token)
{
	Dictionary dict;
	bool adjCheck = std::find(dict.adjectives.begin(), dict.adjectives.end(), token) != dict.adjectives.end();
	bool nounCheck = std::find(dict.nouns.begin(), dict.nouns.end(), token) != dict.nouns.end();
	bool verbCheck = std::find(dict.verbs.begin(), dict.verbs.end(), token) != dict.verbs.end();
	bool pronounCheck = std::find(Dictionary::pronouns.begin(), Dictionary::pronouns.end(), token) != Dictionary::pronouns.end();
	bool conjunctionCheck = std::find(Dictionary::conjunctions.begin(), Dictionary::conjunctions.end(), token) != Dictionary::conjunctions.end();
	bool prepositionCheck = std::find(Dictionary::prepositions.begin(), Dictionary::prepositions.end(), token) != Dictionary::prepositions.end();

	return !(adjCheck && nounCheck && verbCheck && pronounCheck && conjunctionCheck && prepositionCheck);
}