#include "Core/ImplementedEvents.h"

InputEvent::InputEvent(std::string message){
	setType("InputEvent");
	mMessage = message;
}
std::string InputEvent::getMessage(){
	return mMessage;
}

OutputEvent::OutputEvent(std::string message){
	setType("OutputEvent");
	mMessage = message;
}
std::string OutputEvent::getMessage(){
	return mMessage;
}

ReprintEvent::ReprintEvent(){
	setType("ReprintEvent");
}
