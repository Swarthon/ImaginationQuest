#include "Game/Story/Locations/Ground.h"

Ground::Ground(){
	setName("Ground");
}

std::string Ground::getDescription() const {
	if(getObjects().size() == 0)
		return "There is nothing on the ground.";
	std::string desc;
	desc += "On the ground, you can see";
	if(getObjects().size() >= 1) {
		desc += std::string(" ") + getObjects()[0]->getDeterminer() + std::string(" ") + getObjects()[0]->getName();
		for(size_t i = 1; i < getObjects().size() -1; i++)
			desc += std::string(",") + std::string(" ") + getObjects()[i]->getDeterminer() + std::string(" ") + getObjects()[i]->getName();
		desc += std::string(" and ") + getObjects()[getObjects().size()-1]->getDeterminer() + std::string(" ") + getObjects()[getObjects().size()-1]->getName();
	}
	desc += ".";
	return desc;
}
