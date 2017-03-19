#ifndef HERO
#define HERO

// Game includes
#include "Game/Object.h"
#include "Game/Character.h"

// std includes
#include <vector>
#include <algorithm>
#include <map>

class Hero : public Character {
public:
	static Hero* getSingleton();

	void addObject(Object*);
	void eraseObject(Object*);
	void eraseObject(int);
	const std::vector<Object*> getObjects() const;

	void setDead(bool);
protected:
	enum Hand {
		Right,
		Left,
		Both,
	};
	std::vector<Object*> mObjects;
	std::map<Hand, Object*> mHands;
private:
	Hero();
	static Hero* mSingleton;
};

#endif // HERO
