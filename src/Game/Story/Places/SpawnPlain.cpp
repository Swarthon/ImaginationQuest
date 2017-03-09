#include "Game/Story/Places/SpawnPlain.h"

SpawnPlain::SpawnPlain(){
	addAction("go", &move);

	mGround = new Ground();
	mGround->addObject(new Sword);
	addLocation(mGround);
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
