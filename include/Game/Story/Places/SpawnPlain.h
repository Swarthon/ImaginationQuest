#ifndef SPAWNPLAIN
#define SPAWNPLAIN

// Game includes
#include "Game/PlaceHero.h"
#include "Game/Story/Locations/Ground.h"
#include "Game/Story/Weapons/Sword.h"
#include "Game/Story/NPCS/Orc.h"
#include "Game/Hero.h"

#include <iostream>

class SpawnPlain : public PlaceHero {
public:
	SpawnPlain();
	DECLARE_PLACE_CLASS(SpawnPlain)
	virtual void enter();
	virtual void receiveEvent(const Event* evt);

protected:
	static void move(Place*, Parameters);

	Orc* mOrc;
};

#endif // SPAWNPLAIN
