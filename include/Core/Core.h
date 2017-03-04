#ifndef CORE
#define CORE

// Parts includes
#include "Game/Game.h"
#include "GUI/Gui.h"

// std includes
#include <map>

class Core : public Director {
public:
	Core();
	void startGuiMode(int argv, char **args);
	virtual void receiveEvent(Part*, const Event*);
	virtual void sendEvent(Part*, const Event*);
protected:
	enum Parts {
		GamePart, GuiPart
	};
	std::map<Parts,Part*> mParts;
};

#endif // CORE
