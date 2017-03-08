#include "Game/Location.h"

std::string Location::getName() const {
	return mName;
}
void Location::setName(std::string name){
	mName = name;
}

void Location::addObject(Object* o){
	mObjects.push_back(o);
}
void Location::eraseObject(Object* o){
	mObjects.erase(std::find(mObjects.begin(), mObjects.end(), o));
}
void Location::eraseObject(int i){
	mObjects.erase(mObjects.begin() + i);
}
const std::vector<Object*> Location::getObjects() const {
	return mObjects;
}

std::string Location::getDescription() const {
	return std::string();
}
