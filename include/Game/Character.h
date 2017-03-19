#ifndef CHARACTER
#define CHARACTER

// std includes
#include <string>
#include <random>
#include <iostream>
#include <chrono>
#include <sstream>

class Character {
public:
	struct FightSumUp {
		double damage = 0;
		bool targetDead = false;
		bool criticalStrike = false;
		bool luckyCounter = false;
	};

	Character();
	static FightSumUp fight(Character*, Character*);

	double getDefense();
	double getAttack();
	double getMana();
	double getLife();

	void addDamage(double);

	virtual void setDead(bool) = 0;
protected:
	void setDefense(double);
	void setAttack(double);
	void setMana(double);
	void setLife(double);
private:
	double mDefense;
	double mAttack;
	double mMana;
	double mLife;
	double mDamage;
};

#endif // CHARACTER
