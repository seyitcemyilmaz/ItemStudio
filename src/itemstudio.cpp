#include "itemstudio.h"

#include <keyboard.h>

ItemStudio::ItemStudio(Window* pWindow) : mWindow(pWindow) {
    this->mGUI = new GUI();
    mGUI->init(mWindow->getWindow());
}

ItemStudio::~ItemStudio() {
    delete mGUI;
}

void ItemStudio::process() {
    while (!mWindow->getShouldClose()) {
        processInputs();

        mWindow->update();

        //WindowManager::getActiveWindow()->draw();

        
        mGUI->render();

        mWindow->newFrame();
    }
}

void ItemStudio::processInputs() {
    /*
    static double dt = 0.0f;
    static double lastFrame = 0.0f;
    static double currentTime = 0.0f;

    currentTime = glfwGetTime();
    dt = currentTime - lastFrame;
    lastFrame = currentTime;
    */

    if (Keyboard::key(GLFW_KEY_ESCAPE)) {
        mWindow->setShouldClose(true);
    }
}