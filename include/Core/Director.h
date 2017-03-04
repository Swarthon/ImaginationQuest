#ifndef DIRECTOR
#define DIRECTOR

// std includes
#include <string>

// Core includes
#include "Core/Event.h"

class Part;

class Director{
public:
	virtual void receiveEvent(Part*, const Event*) = 0;
	virtual void sendEvent(Part*, const Event*) = 0;
protected:
};

class Part {
public:
	Part(Director* director){mDirector = director;}
	virtual void receiveEvent(const Event*) = 0;
protected:
	Director* mDirector;
};

#endif // DIRECTOR
