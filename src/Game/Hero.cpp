#include "Game/Hero.h"

Hero* Hero::mSingleton = NULL;

Hero* Hero::getSingleton(){
	if(!mSingleton)
		mSingleton = new Hero();
	return mSingleton;
}

void Hero::addObject(Object* o){
	mObjects.push_back(o);
}
void Hero::eraseObject(Object* o){
	mObjects.erase(std::find(mObjects.begin(), mObjects.end(), o));
}
void Hero::eraseObject(int i){
	mObjects.erase(mObjects.begin() + i);
}
const std::vector<Object*> Hero::getObjects() const {
	return mObjects;
}

Hero::Hero(){
	
}
