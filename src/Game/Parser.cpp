#include "Game/Parser.h"

Parser::Parser(){
	mIgnoredWords.push_back("the");
	mIgnoredWords.push_back("a");
	mIgnoredWords.push_back("black");
}
CommandWithParameters Parser::process(std::string text){
	if(text == std::string())
		return CommandWithParameters();
	std::istringstream iss(text);
	std::vector<std::string> words;
	std::string word;
	while(iss >> word)
		if(std::find(mIgnoredWords.begin(), mIgnoredWords.end(), word) == mIgnoredWords.end())
			words.push_back(word);
	std::string command = words[0];
	words.erase(words.begin());

	return CommandWithParameters(command, words);
}
