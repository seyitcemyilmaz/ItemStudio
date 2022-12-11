#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_MAJOR_VERSION	3
#define GLFW_MINOR_VERSION	3

#define WINDOW_RESIZABILITY_DISABLED	(unsigned int)0b00000001
#define WINDOW_MAXIMIZE					(unsigned int)0b00000010
#define WINDOW_CURSOR_DISABLED			(unsigned int)0b00000100

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <functional>

class Window {
private:
	GLFWwindow* mWindow = nullptr;

	std::string mTitle;

	int mHeight;
	int mWidth;

	unsigned int mStates;

	glm::vec4 mBackgroundColor;
public:
	Window(std::string pTitle, unsigned int pStates = 0, int pWidth = 0, int pHeight = 0);

	Window* init();
	void update();
	void createWindow();

	void setWindowHeight(int pHeight);
	void setWindowWidth(int pWidth);
	void setWindowTitle(std::string pTitle);

	GLFWwindow* getWindow();
	int getWindowHeight();
	int getWindowWidth();
	std::string getWindowTitle();
	bool getShouldClose();

	void setResizability(bool pResizability);
	void setMaximize(bool pMaximize);
	void setVisibility(bool pVisibility);
	void setShouldClose(bool pShouldClose);
	void setCursorVisibility(bool pVisibility);

	void setContext();
	void setViewport(int pWidth, int pHeight);

	void draw();

	void newFrame();

	void framebufferSizeCallback(int pWidth, int pHeight);
	void windowMaximizeCallback(int pMaximize);
};
#endif