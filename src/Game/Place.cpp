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

Place::Place(){
	addAction("look", &look);
}
void Place::addLocation(Location* location){
	mLocations.push_back(location);
}
void Place::addAction(Command command, void(*func)(Place*,Parameters)){
	mAvailableActions[command] = func;
}
void Place::runAction(Place* p, CommandWithParameters cwp){
	if(mAvailableActions.find(cwp.first) != mAvailableActions.end())
		mAvailableActions[cwp.first](p,cwp.second);
	else
		output(std::string("I'm sorry, I didn't understand what you said. What do you mean by \"") + cwp.first + std::string("\" ?"));
}
void Place::look(Place* p, Parameters param){
	p->enter();
}
