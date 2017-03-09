#include "Game/PlaceHero.h"

PlaceHero::PlaceHero(){
	addAction("inventory", &inventory);
	addAction("take", &take);
}

void PlaceHero::inventory(Place* p, Parameters param){
	PlaceHero* ph = dynamic_cast<PlaceHero*>(p);
	if(!ph)
		return;
	if(Hero::getSingleton()->getObjects().size() == 0){
		ph->output("In your inventory, you have nothing.");
		return;
	}
	std::string s = "In you inventory, you have";
	for(size_t i = 0; i < Hero::getSingleton()->getObjects().size(); i++)
		s += std::string(" ") + Hero::getSingleton()->getObjects()[i]->getDeterminer() + std::string(" ") + Hero::getSingleton()->getObjects()[i]->getName();
	ph->output(s);
}
void PlaceHero::take(Place* p, Parameters param){
	PlaceHero* ph = dynamic_cast<PlaceHero*>(p);
	if(!ph)
		return;
	if(param == std::vector<std::string>()){
		ph->output("Please specify the object to take");
		return;
	}
	bool taken = false;
	for(size_t i = 0; i < ph->mLocations.size(); i++){
		for(size_t j = 0; j < ph->mLocations[i]->getObjects().size(); j++) {
			if(std::find(param.begin(), param.end(), ph->mLocations[i]->getObjects()[i]->getName()) != param.end()) {
				ph->output(std::string("You have taken ") + ph->mLocations[i]->getObjects()[j]->getDeterminer() + std::string(" ") + ph->mLocations[i]->getObjects()[j]->getName());
				Hero::getSingleton()->addObject(ph->mLocations[i]->getObjects()[j]);
				ph->mLocations[i]->eraseObject(j);
				taken = true;
			}
		}
	}
	if(!taken)
		ph->output("There is nothing with that name to take");
}
