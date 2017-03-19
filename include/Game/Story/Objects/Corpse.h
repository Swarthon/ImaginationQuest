#ifndef CORPSE
#define CORPSE

// Game includes
#include "Game/Object.h"
#include "Game/Npc.h"

class Corpse : public Object {
public:
	Corpse(Npc*);
protected:
private:
	Npc* mNpc;
};

#endif // CORPSE
