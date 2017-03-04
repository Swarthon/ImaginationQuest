#include "GUI/HelpWindow.h"

HelpWindow::HelpWindow(){
	resize(250,250);
	setAttribute(Qt::WA_DeleteOnClose, true);
	setWindowTitle(tr("Help Window"));
}
