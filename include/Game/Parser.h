#ifndef PARSER
#define PARSER

// std includes
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

// Game includes
#include "Game/Command.h"

class Parser {
public:
	Parser();
	CommandWithParameters process(std::string text);
protected:
	std::vector<std::string> mIgnoredWords;
};

#endif // PARSER
