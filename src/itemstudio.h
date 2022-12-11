#ifndef ITEMSTUDIO_H
#define ITEMSTUDIO_H

#include "windowmanager.h"
#include "gui.h"

#define ITEM_STUDIO_ID	"mainWindow"

class ItemStudio {
private:
	Window* mWindow;
	GUI* mGUI;
	
	void processInputs();
public:
	ItemStudio(Window* pWindow);
	~ItemStudio();
	void process();
};

#endif
