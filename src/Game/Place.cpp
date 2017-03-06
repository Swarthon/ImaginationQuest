#include "Game/Place.h"

void PlaceManager::enter(Place* p){
	changePlace(p);
	mActivePlace->enter();
}
void PlaceManager::receiveEvent(const Event* evt){
	mActivePlace->receiveEvent(evt);
}
void PlaceManager::changePlace(Place* p){
	mActivePlace = p;
}
void PlaceManager::managePlace(std::string placeName, Place* place){
	mPlaces[placeName] = place;
}
Place* PlaceManager::findByName(std::string placeName){
	return mPlaces[placeName];
}



void Place::addAction(Command command, void(Place::*func)(Parameters)){
	mAvailableActions[command] = func;
}
void Place::runAction(CommandWithParameters cwp){
	(*this.*mAvailableActions[cwp.first])(cwp.second);
}
