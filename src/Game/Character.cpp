#include "Game/Character.h"

Character::Character(){
	mDefense = 0;
	mAttack = 0;
	mMana = 0;
	mLife = 0;
	mDamage = 0;
}
Character::FightSumUp Character::fight(Character* attacker, Character* target){
	FightSumUp fsu;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(0.5,1.5);

	double rndAtk = distribution(generator);
	double hit = attacker->getAttack() * rndAtk;
	if(hit < 0)			hit = 0;
	if(rndAtk > 1.35)		fsu.criticalStrike = true;

	double rndDef = distribution(generator);
	double counter = target->getDefense() * rndDef;
	if(counter < 0)			counter = 0;
	if(rndDef > 1.35)		fsu.luckyCounter = true;

	if(hit - counter > 0) {
		target->addDamage(hit - counter);
		fsu.damage = hit - counter;
	}
	if(target->getLife() < 0) {
		target->setDead(true);
		fsu.targetDead = true;
	}

	return fsu;
}

double Character::getDefense(){
	return mDefense;
}
double Character::getAttack(){
	return mAttack;
}
double Character::getMana(){
	return mMana;
}
double Character::getLife(){
	return mLife - mDamage;
}

void Character::addDamage(double damage){
	mDamage += damage;
}

void Character::setDefense(double defense){
	mDefense = defense;
}
void Character::setAttack(double attack){
	mAttack = attack;
}
void Character::setMana(double mana){
	mMana = mana;
}
void Character::setLife(double life){
	mLife = life;
}
