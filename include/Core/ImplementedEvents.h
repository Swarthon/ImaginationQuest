#ifndef IMPLEMENTEDEVENTS
#define IMPLEMENTEDEVENTS

// std includes
#include <string>
#include <iostream>

// Core includes
#include "Core/Event.h"

class InputEvent : public Event {
public:
	InputEvent(std::string message);
	virtual std::string getMessage() const;
protected:
	std::string mMessage;
};

class OutputEvent : public Event {
public:
	OutputEvent(std::string message);
	virtual std::string getMessage() const;
protected:
	std::string mMessage;
};

class ReprintEvent : public Event {
public:
	ReprintEvent();
protected:
};

#endif // IMPLEMENTEDEVENTS
