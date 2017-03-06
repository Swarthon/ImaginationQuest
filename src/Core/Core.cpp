#include "Core/Core.h"

Core::Core(){
	mParts[GamePart] = new Game(this);
	mParts[GuiPart] = new Gui(this);
}
int Core::startGuiMode(int argv, char **args){
	return ((Gui*)mParts[GuiPart])->start(argv, args);
}
void Core::receiveEvent(Part* p, const Event* evt){
	if(p == mParts[GuiPart])
		sendEvent(mParts[GamePart], evt);
	if(p == mParts[GamePart])
		sendEvent(mParts[GuiPart], evt);
}
void Core::sendEvent(Part* p, const Event* evt){
	p->receiveEvent(evt);
}
