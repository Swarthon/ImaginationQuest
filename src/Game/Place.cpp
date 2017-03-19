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

	mGround = new Ground();
	mLocations.push_back(mGround);
}
void Place::addAction(Command command, void(*func)(Place*,Parameters)){
	mAvailableActions[command] = func;
}
void Place::runAction(Place* p, CommandWithParameters cwp){
	if(mAvailableActions.find(cwp.first) != mAvailableActions.end()){
		mAvailableActions[cwp.first](p,cwp.second);
		update();
	}
	else
		output(std::string("I'm sorry, I didn't understand what you said. What do you mean by \"") + cwp.first + std::string("\" ?"));
}
std::string Place::getNpcsDescription(){
	std::string npcs;	int num = 0;
	for(size_t i = 0; i < mNpcs.size(); i++){
		if(mNpcs[i]->getLife() > 0) {
			npcs += std::string(" ") + mNpcs[i]->getDeterminer() + std::string(" ") + mNpcs[i]->getName();
			num++;
		}
	}
	npcs = std::string("You can see") + npcs + std::string(".");
	if(!num)
		npcs = "";

	return npcs;
}
void Place::look(Place* p, Parameters param){
	p->enter();
}
