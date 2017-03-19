#include "Game/Story/Objects/Corpse.h"

Corpse::Corpse(Npc* npc){
	mNpc = npc;
	setName(std::string("corpse of ") + npc->getName());
	setDeterminer(std::string("a"));
}
