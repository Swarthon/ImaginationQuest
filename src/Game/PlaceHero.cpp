#include "Game/PlaceHero.h"

PlaceHero::PlaceHero(){
	addAction("inventory", &inventory);
	addAction("take", &take);
	addAction("attack", &fight);
}

void PlaceHero::inventory(Place* p, Parameters param){
	PlaceHero* ph = dynamic_cast<PlaceHero*>(p);
	if(!ph)
		return;
	if(Hero::getSingleton()->getObjects().size() == 0){
		ph->output("In your inventory, you don't have anything.");
		return;
	}
	std::string s = "In your inventory, you have";
	for(size_t i = 0; i < Hero::getSingleton()->getObjects().size(); i++)
		s += std::string(" ") + Hero::getSingleton()->getObjects()[i]->getDeterminer() + std::string(" ") + Hero::getSingleton()->getObjects()[i]->getName();
	ph->output(s);
}
void PlaceHero::take(Place* p, Parameters param){
	PlaceHero* ph = dynamic_cast<PlaceHero*>(p);
	if(!ph)
		return;
	if(param == Parameters()){
		ph->output("What do you want to take ?");
		return;
	}
	bool taken = false;
	for(size_t i = 0; i < ph->mLocations.size(); i++){
		for(size_t j = 0; j < ph->mLocations[i]->getObjects().size(); j++) {
			if(std::find(param.begin(), param.end(), ph->mLocations[i]->getObjects()[i]->getName()) != param.end()) {
				ph->output(std::string("You have taken the ") + ph->mLocations[i]->getObjects()[j]->getName());
				Hero::getSingleton()->addObject(ph->mLocations[i]->getObjects()[j]);
				ph->mLocations[i]->eraseObject(j);
				taken = true;
			}
		}
	}
	if(!taken)
		ph->output("There is nothing with that name to take");
}
void PlaceHero::fight(Place* p, Parameters param){
	PlaceHero* ph = dynamic_cast<PlaceHero*>(p);
	if(!ph)
		return;
	if(param == Parameters()){
		ph->output("Who do you want to attack ?");
		return;
	}
	bool attacked = false;
	for(size_t i = 0; i < ph->mNpcs.size(); i++){
		if(std::find(param.begin(), param.end(), ph->mNpcs[i]->getName()) != param.end()){
			if(ph->mNpcs[i]->getLife() < 0) {
				ph->output(std::string("The ") + ph->mNpcs[i]->getName() + std::string(" is already dead."));
				attacked = true;
			}
			else {
				ph->output(std::string("You have attacked the ") + ph->mNpcs[i]->getName() + std::string("."));
				Character::FightSumUp fsu = Character::fight(Hero::getSingleton(), ph->mNpcs[i]);
				std::ostringstream oss;	oss << fsu.damage;	std::string s = oss.str();
				ph->output(std::string("\tYou have inflicted ") + s + std::string(" damages to the ") + ph->mNpcs[i]->getName() + std::string("."));
				if(fsu.criticalStrike)	ph->output("\tCritical strike !");
				if(fsu.targetDead){
					ph->output(std::string("\tYou have killed the ") + ph->mNpcs[i]->getName() + std::string(" !"));
					ph->mGround->addObject(new Corpse(ph->mNpcs[i]));
					ph->mNpcs.erase(ph->mNpcs.begin() + i);
				}
				attacked = true;
			}
		}
	}
	if(!attacked)
		ph->output("There is no character with that name.");
}
