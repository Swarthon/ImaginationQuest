#ifndef GAME
#define GAME

// Core includes
#include "Core/Director.h"
#include "Core/ImplementedEvents.h"

// Game includes
#include "Game/Parser.h"
#include "Game/Place.h"

// Game story includes
#include "Game/Story/Places/SpawnPlain.h"

#include <iostream>

class Game : public Part, public Observer {
public:
	Game(Director* director);
	virtual void receiveEvent(const Event* evt);
	virtual void update(Subject* modifiedSubject, const Event* evt);
protected:
	PlaceManager* mPlaceManager;
};

#endif // GAME
