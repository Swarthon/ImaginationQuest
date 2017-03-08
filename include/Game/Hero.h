#ifndef HERO
#define HERO

// Game includes
#include "Game/Object.h"

// std includes
#include <vector>
#include <algorithm>

class Hero {
public:
	static Hero* getSingleton();

	void addObject(Object*);
	void eraseObject(Object*);
	void eraseObject(int);
	const std::vector<Object*> getObjects() const;
protected:
	std::vector<Object*> mObjects;
private:
	Hero();
	static Hero* mSingleton;
};

#endif // HERO
