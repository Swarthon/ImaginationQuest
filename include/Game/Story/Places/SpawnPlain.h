#ifndef SPAWNPLAIN
#define SPAWNPLAIN

// Game includes
#include "Game/Place.h"
#include "Game/Story/Locations/Ground.h"
#include "Game/Story/Weapons/Sword.h"
#include "Game/Hero.h"

#include <iostream>

class SpawnPlain : public Place {
public:
	SpawnPlain();
	DECLARE_PLACE_CLASS(SpawnPlain)
	virtual void enter();
	virtual void receiveEvent(const Event* evt);

protected:
	static void move(Place*, Parameters);
	static void take(Place*, Parameters);
	static void look(Place*, Parameters);
	std::map<Command,void(SpawnPlain::*)(Parameters)> mAvailableActions;

	Ground* mGround;


};

#endif // SPAWNPLAIN
