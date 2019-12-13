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

	// make sure the files are good before we even read them.
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

		// read files individually

		std::cout << "READFILE: dictionary_adjectives.txt ";
		if (adjDictFile.is_open())
		{
			while (adjDictFile >> currentAdJStream && !adjDictFile.eof())
			{
				// we do the same for each vector, reading files is FIFO as always 
				// Note: FIFO means First In, First Out
				Dictionary::adjectives.push_back(currentAdJStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << "READFILE: dictionary_nouns.txt ";
		if (nounsDictFile.is_open())
		{
			while (nounsDictFile >> currentNounStream && !nounsDictFile.eof())
			{
				Dictionary::nouns.push_back(currentNounStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << "READFILE: dictionary_verbs.txt ";
		if (verbsDictFile.is_open())
		{
			while (verbsDictFile >> currentVerbStream && !verbsDictFile.eof())
			{
				Dictionary::verbs.push_back(currentVerbStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << "READFILE: dictionary_pronouns.txt ";
		if (pronounsDictFile.is_open())
		{
			while (pronounsDictFile >> currentPronounStream && !pronounsDictFile.eof())
			{
				Dictionary::pronouns.push_back(currentPronounStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << "READFILE: dictionary_preposition.txt ";
		if (prepDictFile.is_open())
		{
			while (prepDictFile >> currentPrepositionStream && !prepDictFile.eof())
			{
				Dictionary::prepositions.push_back(currentPrepositionStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << "READFILE: dictionary_conjunctions.txt ";
		if (conjDictFile.is_open())
		{
			while (conjDictFile >> currentConjunctionStream && !conjDictFile.eof())
			{
				Dictionary::conjunctions.push_back(currentConjunctionStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << "READFILE: dictionary_articles.txt ";
		if (articleDictFile.is_open())
		{
			
			while (articleDictFile >> currentArticleStream && !articleDictFile.eof())
			{
				Dictionary::articles.push_back(currentArticleStream);
			}

			std::cout << "\t [DONE]" << std::endl;
		}
		else
		{
			std::cout << "\t [FAIL]" << std::endl;
			throw 3;
		}

		std::cout << std::endl;
		std::cout << "Registered " << Dictionary::nouns.size() << " noun(s)." << std::endl;
		std::cout << "Registered " << Dictionary::adjectives.size() << " adjective(s)." << std::endl;
		std::cout << "Registered " << Dictionary::pronouns.size() << " pronoun(s)." << std::endl;
		std::cout << "Registered " << Dictionary::prepositions.size() << " preposition(s)." << std::endl;
		std::cout << "Registered " << Dictionary::verbs.size() << " verb(s)." << std::endl;
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
