#include "GUI/Gui.h"

Gui::Gui(Director* director) : Part(director){
}
int Gui::start(int argv, char **args){
	mApp = new QApplication(argv, args);
	mMainWindow = new MainWindow();
	mMainWindow->attach(this);
	mMainWindow->show();
	return mApp->exec();
}
void Gui::update(Subject* modifiedSubject, const Event* evt){
	mDirector->receiveEvent(this, evt);
}
