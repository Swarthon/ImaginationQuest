#include "Core/ImplementedEvents.h"

InputEvent::InputEvent(std::string message){
	setType("InputEvent");
	mMessage = message;
}
std::string InputEvent::getMessage(){
	return mMessage;
}
