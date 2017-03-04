#include "GUI/InventoryWindow.h"

InventoryWindow::InventoryWindow(){
	resize(250,250);
	setAttribute(Qt::WA_DeleteOnClose, true);
	setWindowTitle(tr("Inventory Window"));
}
