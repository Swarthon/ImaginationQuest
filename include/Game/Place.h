#ifndef PLACE
#define PLACE

// std includes
#include <map>
#include <vector>

// Core incldudes
#include "Core/Event.h"
#include "Core/Observer.h"

// Game includes
#include "Game/Command.h"
#include "Game/Parser.h"
#include "Game/Hero.h"
#include "Game/Location.h"

class Place;

class PlaceManager : public Subject {
public:
	PlaceManager(){}
	~PlaceManager(){}

	virtual void enter(Place*);
	virtual void receiveEvent(const Event* evt);
	virtual void changePlace(Place *place);
	virtual void managePlace(std::string placeName, Place* place);
	virtual Place* findByName(std::string placeName);
	virtual void output(std::string message){notify(new OutputEvent(message));}
protected:
	Place* mActivePlace;
	std::map<std::string, Place*> mPlaces;
};

class Place {
public:
	virtual void enter() = 0;
	virtual void receiveEvent(const Event* evt) = 0;
protected:
	Place();
	void changePlace(Place* place){mParent->changePlace(place);}
	Place* findByName(std::string placeName){return mParent->findByName(placeName);}
	void output(std::string message){mParent->output(message);}

	void addLocation(Location* location);

	void addAction(Command command, void(*func)(Place*,Parameters));
	void runAction(Place* p, CommandWithParameters cwp);

	static void look(Place*, Parameters);

	PlaceManager* mParent;
	std::vector<Location*> mLocations;

private:
	std::map<Command,void(*)(Place*, Parameters)> mAvailableActions;
};

#define DECLARE_PLACE_CLASS(T)						\
static void create(PlaceManager* parent, const std::string name)	\
{										\
	T* myPlace = new T();							\
	myPlace->mParent = parent;						\
	parent->managePlace(name, myPlace);					\
}

#endif // PLACE
