#include "Game/Npc.h"

std::string Npc::getName() const {
	return mName;
}
void Npc::setName(std::string name){
	mName = name;
}
std::string Npc::getDeterminer() const {
	return mDeterminer;
}
void Npc::setDeterminer(std::string determiner){
	mDeterminer = determiner;
}
