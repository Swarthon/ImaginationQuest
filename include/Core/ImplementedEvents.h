#ifndef IMPLEMENTEDEVENTS
#define IMPLEMENTEDEVENTS

// std includes
#include <string>

// Core includes
#include "Core/Event.h"

class InputEvent : public Event {
public:
	InputEvent(std::string message);
	virtual std::string getMessage();
protected:
	std::string mMessage;
};

#endif // IMPLEMENTEDEVENTS
