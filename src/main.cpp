#include "itemstudio.h"

int main() {
    //Window* itemStudioWindow = WindowManager::addNewWindow(ITEM_STUDIO_ID, "Item Studio v0.1", WINDOW_MAXIMIZE);
    Window* itemStudioWindow = WindowManager::addNewWindow(ITEM_STUDIO_ID, "Item Studio v0.1", 0, 800, 600);

    if (!itemStudioWindow) {
        return -1;
    }

    ItemStudio itemStudio(itemStudioWindow);

    itemStudio.process();
    
    return 0;
}