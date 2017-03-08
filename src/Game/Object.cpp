#include "Game/Object.h"

std::string Object::getName() const {
	return mName;
}
void Object::setName(std::string name){
	mName = name;
}
std::string Object::getDeterminer() const {
	return mDeterminer;
}
void Object::setDeterminer(std::string determiner){
	mDeterminer = determiner;
}
