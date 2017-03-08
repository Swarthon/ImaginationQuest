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

void Place::addAction(Command command, void(*func)(Place*,Parameters)){
	mAvailableActions[command] = func;
}
void Place::runAction(Place* p, CommandWithParameters cwp){
	if(mAvailableActions.find(cwp.first) != mAvailableActions.end())
		mAvailableActions[cwp.first](p,cwp.second);
}
