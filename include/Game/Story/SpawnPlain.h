#ifndef SPAWNPLAIN
#define SPAWNPLAIN

#include "Game/Place.h"

#include <iostream>

class SpawnPlain : public Place {
public:
	DECLARE_PLACE_CLASS(SpawnPlain)
	virtual void enter();
	virtual void receiveEvent(const Event* evt);
};

#endif // SPAWNPLAIN
