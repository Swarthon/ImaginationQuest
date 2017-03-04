#ifndef GUI
#define GUI

// Qt includes
#include <QApplication>
#include <QMainWindow>

// Core includes
#include "Core/Director.h"

// GUI includes
#include "GUI/MainWindow.h"

class Gui : public Part, public Observer {
public:
	Gui(Director* director);
	virtual int  start(int argv, char **args);
	virtual void update(Subject* modifiedSubject, const Event* evt);
	virtual void receiveEvent(const Event* evt){};
protected:
	QApplication* mApp;
	MainWindow* mMainWindow;
};

#endif // GUI
