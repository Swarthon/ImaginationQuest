#include "Game/Weapon.h"

double Weapon::getAttack(){
	return mAttack;
}
double Weapon::getDefense(){
	return mDefense;
}

void Weapon::setAttack(double val){
	mAttack = val;
}
void Weapon::setDefense(double val){
	mDefense = val;
}
