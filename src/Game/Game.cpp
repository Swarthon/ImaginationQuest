#include "Game/Game.h"

Game::Game(Director* director) : Part(director){
}
void Game::receiveEvent(const Event* evt){
	if(evt->getType() == "InputEvent")
		play(((InputEvent*)evt)->getMessage());
}

void Game::play(std::string str){
}
