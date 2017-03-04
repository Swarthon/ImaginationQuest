#include "Core/Core.h"

Core::Core(){
	mParts[GamePart] = new Game(this);
	mParts[GuiPart] = new Gui(this);
}
void Core::startGuiMode(int argv, char **args){
	((Gui*)mParts[GuiPart])->start(argv, args);
}
void Core::receiveEvent(Part* p, const Event* evt){
	if(p == mParts[GuiPart])
		sendEvent(mParts[GamePart], evt);
}
void Core::sendEvent(Part* p, const Event* evt){
	p->receiveEvent(evt);
}
