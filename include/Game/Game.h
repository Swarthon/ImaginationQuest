#ifndef GAME
#define GAME

// Core includes
#include "Core/Director.h"
#include "Core/ImplementedEvents.h"

#include <iostream>

class Game : public Part {
public:
	Game(Director* director);
	virtual void receiveEvent(const Event* evt);
protected:
	void play(std::string);
};

#endif // GAME
