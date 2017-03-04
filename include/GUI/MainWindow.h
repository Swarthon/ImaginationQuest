#ifndef MAINWINDOW
#define MAINWINDOW

// Qt includes
#include <QMainWindow>
#include <QMenuBar>
#include <QShortcut>
#include <QApplication>

// GUI includes
#include "GUI/HelpWindow.h"
#include "GUI/InventoryWindow.h"
#include "GUI/Content.h"


// Core includes
#include "Core/Observer.h"

// std includes
#include <map>
#include <iostream>

class MainWindow : public QMainWindow, public Subject{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();
private:
	QAction *mHelpAction;
	QAction *mInventoryAction;
	QMenu *mWindowMenu;
	Content* mContent;

	std::map<std::string,QWidget*> mOpenedWindows;

public slots:
	void menubarVisible();
	void showHelpWindow();
	void showInventoryWindow();
	void closedHelpWindow();
	void closedInventoryWindow();
	void input(std::string);
};

#endif // MAINWINDOW
