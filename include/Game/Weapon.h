#ifndef WEAPON
#define WEAPON

// Game includes
#include "Game/Object.h"

class Weapon : public Object {
public:
	double getAttack();
	double getDefense();
protected:
	void setAttack(double);
	void setDefense(double);
private:
	double mAttack;
	double mDefense;
};

#endif // WEAPON
