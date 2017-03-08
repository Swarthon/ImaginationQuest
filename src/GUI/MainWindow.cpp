#include "GUI/MainWindow.h"

// Constructor
MainWindow::MainWindow(Observer* o){
	if(o)
		attach(o);
	mHelpAction = new QAction(tr("&Help"), this);
	mInventoryAction = new QAction(tr("&Inventory"), this);
	connect(mHelpAction, SIGNAL(triggered()), this, SLOT(showHelpWindow()));
	connect(mInventoryAction, SIGNAL(triggered()), this, SLOT(showInventoryWindow()));

	mWindowMenu = menuBar()->addMenu(tr("&Windows"));
	mWindowMenu->addAction(mHelpAction);
	mWindowMenu->addAction(mInventoryAction);

	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_W), this, SLOT(menubarVisible()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_H), this, SLOT(showHelpWindow()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_I), this, SLOT(showInventoryWindow()));

	mContent = new Content();
	setCentralWidget(mContent);

	connect(mContent, SIGNAL(input(std::string)), this, SLOT(input(std::string)));

	resize(500,500);
	setWindowTitle(tr("ImaginationQuest"));
	setAttribute(Qt::WA_DeleteOnClose, true);
}
MainWindow::~MainWindow(){
	exit(0);
}

// Public Slots
void MainWindow::menubarVisible(){
	if(menuBar()->isVisible())
		menuBar()->hide();
	else
		menuBar()->show();
}
void MainWindow::showHelpWindow(){
	if(!mOpenedWindows.count("Help")){
		HelpWindow* helpWindow = new HelpWindow;
		helpWindow->show();
		connect(helpWindow, SIGNAL(destroyed()), this, SLOT(closedHelpWindow()));
		mOpenedWindows["Help"] = helpWindow;
	}
}
void MainWindow::showInventoryWindow(){
	if(!mOpenedWindows.count("Inventory")){
		InventoryWindow* inventoryWindow = new InventoryWindow;
		inventoryWindow->show();
		connect(inventoryWindow, SIGNAL(destroyed()), this, SLOT(closedInventoryWindow()));
		mOpenedWindows["Inventory"] = inventoryWindow;
	}
}
void MainWindow::closedHelpWindow(){
	if(mOpenedWindows.count("Help")){
		mOpenedWindows.erase("Help");
	}
}
void MainWindow::closedInventoryWindow(){
	if(mOpenedWindows.count("Inventory")){
		mOpenedWindows.erase("Inventory");
	}
}
void MainWindow::input(std::string s){
	mContent->print(std::string("> ") + s);
	notify(new InputEvent(s));
}
void MainWindow::output(std::string s){
	mContent->print(s);
}
