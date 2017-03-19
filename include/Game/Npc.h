#ifndef NPC
#define NPC

// std includes
#include <string>

// Game includes
#include "Game/Character.h"

class Npc : public Character {
public:
	std::string getName() const;
	std::string getDeterminer() const;
protected:
	void setName(std::string);
	void setDeterminer(std::string);
private:
	std::string mName;
	std::string mDeterminer;
};

#endif // NPC
