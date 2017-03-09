#ifndef HERO
#define HERO

// Game includes
#include "Game/Object.h"

// std includes
#include <vector>
#include <algorithm>
#include <map>

class Hero {
public:
	static Hero* getSingleton();

	void addObject(Object*);
	void eraseObject(Object*);
	void eraseObject(int);
	const std::vector<Object*> getObjects() const;

	double getAttack();
	double getDefense();
protected:
	enum Hand {
		Right,
		Left,
		Both,
	};
	std::vector<Object*> mObjects;
	std::map<Hand, Object*> mHands;

	void setAttack(double);
	void setDefense(double);
private:
	Hero();
	static Hero* mSingleton;

	double mAttack;
	double mDefense;
};

#endif // HERO
