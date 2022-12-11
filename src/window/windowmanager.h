#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <iostream>
#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "window.h"


class WindowManager {
private:
	static std::map<std::string, Window*> mIdToWindow;
	static std::map<GLFWwindow*, Window*> mGLFWwindowToWindow;
	static bool initalized;

public:
	WindowManager();

	static Window* addNewWindow(std::string id, std::string title, unsigned int states = 0, int width = 800, int height = 600);

	static Window* getWindow(std::string id);

	static void errorCallback(int pErrorCode, const char* pDescription);

	static void framebufferSizeCallback(GLFWwindow* pWindow, int pWidth, int pHeight);
	static void windowMaximizeCallback(GLFWwindow* pWindow, int pMaximize);

	static void processInput();
};

#endif