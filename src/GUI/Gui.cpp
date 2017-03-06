#include "GUI/Gui.h"

Gui::Gui(Director* director) : Part(director){
}
int Gui::start(int argv, char **args){
	mApp = new QApplication(argv, args);
	mMainWindow = new MainWindow(this);
	mMainWindow->show();
	mDirector->receiveEvent(this, new ReprintEvent());
	return mApp->exec();
}
void Gui::update(Subject* modifiedSubject, const Event* evt){
	mDirector->receiveEvent(this, evt);
}
void Gui::receiveEvent(const Event* evt){
	if(evt->getType() == "OutputEvent")
		mMainWindow->output(((OutputEvent*)evt)->getMessage());
}
