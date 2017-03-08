#include "Game/Story/Locations/Ground.h"

Ground::Ground(){
	setName("Ground");
}

std::string Ground::getDescription() const {
	if(getObjects().size() == 0)
		return "There is nothing on the ground.";
	std::string desc;
	desc += "On the ground, you can see";
	for(size_t i = 0; i < getObjects().size(); i++)
		desc += std::string(" ") + getObjects()[i]->getDeterminer() + std::string(" ") + getObjects()[i]->getName();
	desc += ".";
	return desc;
}
