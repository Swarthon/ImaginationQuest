#include "Core/ImplementedEvents.h"

InputEvent::InputEvent(std::string message){
	mMessage = message;
}
std::string InputEvent::getMessage() const{
	return mMessage;
}

OutputEvent::OutputEvent(std::string message){
	mMessage = message;
}
std::string OutputEvent::getMessage() const {
	return mMessage;
}

ReprintEvent::ReprintEvent(){
}
