#include "Game/Game.h"

Game::Game(Director* director) : Part(director){
	mPlaceManager = new PlaceManager();
	mPlaceManager->attach(this);

	SpawnPlain::create(mPlaceManager, "SpawnPlain");
	mPlaceManager->enter(mPlaceManager->findByName("SpawnPlain"));
}
void Game::receiveEvent(const Event* evt){
	mPlaceManager->receiveEvent(evt);
}
void Game::update(Subject* modifiedSubject, const Event* evt){
	mDirector->receiveEvent(this, evt);
}
