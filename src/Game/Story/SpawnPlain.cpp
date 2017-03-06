#include "Game/Story/SpawnPlain.h"

void SpawnPlain::enter(){
	output("You are in a plain. On the North you can see moutains. \
On the west there is a road that lead to a town. \
You can see a big forest on the east and on the south you see a big sea with a little village near it.");
}
void SpawnPlain::receiveEvent(const Event* evt){
	if(evt->getType() == "ReprintEvent")
		enter();
}
