#ifndef OBSERVER
#define OBSERVER

// Core includes
#include "Core/Event.h"
#include "Core/ImplementedEvents.h"

// std includes
#include <vector>
#include <algorithm>

class Subject;

class Observer {
public:
	virtual void update(Subject* modifiedSubject, const Event* evt) = 0;
protected:
};

class Subject {
public:
	virtual void attach(Observer* o){
		mObservers.push_back(o);
	}
	virtual void detach(Observer* o){
		mObservers.erase(std::find(mObservers.begin(), mObservers.end(), o));
	}
	virtual void notify(Event* evt){
		for(size_t i = 0; i < mObservers.size(); i++)
			mObservers[i]->update(this, evt);
	}
protected:
private:
	std::vector<Observer*> mObservers;
};

#endif // OBSERVER
