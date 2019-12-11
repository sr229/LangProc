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
	return (std::find(Dictionary::nouns.begin(), Dictionary::nouns.end(), token) != Dictionary::adjectives.end());
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
