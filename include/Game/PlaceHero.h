#ifndef PLACEHERO
#define PLACEHERO

// Game includes
#include "Game/Place.h"
#include "Game/Hero.h"

class PlaceHero : public Place {
public:
	PlaceHero();
protected:
	static void inventory(Place*, Parameters);
	static void take(Place*, Parameters);
	static void fight(Place*, Parameters);
private:
};

#endif // PLACEHERO
