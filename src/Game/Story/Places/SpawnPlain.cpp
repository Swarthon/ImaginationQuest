#include "Game/Story/Places/SpawnPlain.h"

SpawnPlain::SpawnPlain(){
	addAction("go", &SpawnPlain::move);
	addAction("take", &SpawnPlain::take);
	addAction("look", &SpawnPlain::look);
	mGround = new Ground();
	mGround->addObject(new Sword);
}
void SpawnPlain::enter(){
	output(std::string("You are in a plain. On the north you can see mountains. \
On the west there is a road that leads to a town. \
You can see a big forest on the east and on the south you see a big sea with a little village near it. ") + mGround->getDescription());
}
void SpawnPlain::receiveEvent(const Event* evt){
	Parser p;

	if(dynamic_cast<const ReprintEvent*>(evt))
		enter();
	if(const InputEvent* ievt = dynamic_cast<const InputEvent*>(evt))
		runAction(this, p.process(ievt->getMessage()));
}

void SpawnPlain::move(Place* p, Parameters param){
	SpawnPlain* sp = dynamic_cast<SpawnPlain*>(p);
	if(!sp)
		return;
	if(std::find(param.begin(), param.end(), "north") != param.end())
		sp->mParent->enter(sp->findByName("SpawnPlain"));
}
void SpawnPlain::take(Place* p, Parameters param){
	SpawnPlain* sp = dynamic_cast<SpawnPlain*>(p);
	if(!sp)
		return;
	for(size_t i = 0; i < sp->mGround->getObjects().size(); i++) {
		if(std::find(param.begin(), param.end(), sp->mGround->getObjects()[i]->getName()) != param.end()) {
			Hero::getSingleton()->addObject(sp->mGround->getObjects()[i]);
			sp->mGround->eraseObject(i);
		}
	}
}
void SpawnPlain::look(Place* p, Parameters param){
	SpawnPlain* sp = dynamic_cast<SpawnPlain*>(p);
	if(!sp)
		return;
	sp->enter();
}
