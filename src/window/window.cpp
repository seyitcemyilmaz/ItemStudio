#include "window.h"
#include "windowmanager.h"
#include "algorithms/states.hpp"

#include "io/mouse.h"
#include "io/keyboard.h"
#include "io/camera.h"

Window::Window(std::string pTitle, unsigned int pStates, int pWidth, int pHeight) :
	mTitle(pTitle),
	mWidth(pWidth),
	mHeight(pHeight),
	mStates(pStates),
	mBackgroundColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f)) { }

Window* Window::init() {
	setVisibility(false);
	
	if (States::isActive(&mStates, WINDOW_MAXIMIZE)) {
		int xpos, ypos;
		glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xpos, &ypos, &mWidth, &mHeight);
		glfwWindowHint(GLFW_MAXIMIZED, GL_FALSE);

		createWindow();

		if (!mWindow) {
			glfwTerminate();
			return nullptr;
		}

		setContext();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			glfwTerminate();
			return nullptr;
		}

		int x, y;
		glfwGetWindowPos(mWindow, &x, &y);
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;

		glfwSetWindowAttrib(mWindow, GLFW_RESIZABLE, GL_FALSE);

		int left, top, right, bottom;
		glfwGetWindowFrameSize(mWindow, &left, &top, &right, &bottom);

		int titlebarWidth = abs(left - right);
		int titlebarHeight = abs(right - top);

		mWidth -= titlebarWidth;
		mHeight -= titlebarHeight;

		glfwSetWindowSize(mWindow, mWidth, mHeight);

		glfwSetWindowPos(mWindow, xpos + titlebarWidth, ypos + titlebarHeight);
	}
	else {
		createWindow();

		if (!mWindow) {
			glfwTerminate();
			return nullptr;
		}

		setContext();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			glfwTerminate();
			return nullptr;
		}
	}
	
	/*
	if (States::isActive(&mStates, WINDOW_MAXIMIZE)) {
		glfwWindowHint(GLFW_VISIBLE, 0);

		GLFWmonitor* tMonitor = glfwGetPrimaryMonitor();

		int area_x = 1920, area_y = 1080, area_width = 1920, area_height = 1080;

		mWindow = glfwCreateWindow(mWidth, mHeight, "Title", NULL, NULL);
		glfwGetMonitorWorkarea(tMonitor, &area_x, &area_y, &area_width, &area_height);

		int width, height;
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		width = mode->width;
		height = mode->height;

		glfwSetWindowPos(mWindow,a,b);
		glfwMaximizeWindow(mWindow);
		glfwShowWindow(mWindow);

		setContext();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			glfwTerminate();
			return nullptr;
		}
	}
	*/
	glfwSetWindowUserPointer(mWindow, this);

	glfwSetKeyCallback(mWindow, Keyboard::keyCallback);

	glfwSetCursorPosCallback(mWindow, Mouse::cursorPosCallback);
	glfwSetMouseButtonCallback(mWindow, Mouse::mouseButtonCallback);
	glfwSetScrollCallback(mWindow, Mouse::mouseWheelCallback);


	setResizability(!States::isActive(&mStates, WINDOW_RESIZABILITY_DISABLED));
	setCursorVisibility(!States::isActive(&mStates, WINDOW_CURSOR_DISABLED));

	setVisibility(true);

	return this;
}

void Window::draw() {

}

void Window::update() {
	glClearColor(mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::createWindow()
{
	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);
}

void Window::setWindowWidth(int pWidth) {
	mWidth = pWidth;
}

void Window::setWindowHeight(int pHeight) {
	mHeight = pHeight;
}


void Window::setWindowTitle(std::string pTitle)
{
	mTitle = pTitle;
	glfwSetWindowTitle(mWindow, mTitle.c_str());
}

GLFWwindow* Window::getWindow()
{
	return mWindow;
}

int Window::getWindowHeight() {
	return mHeight;
}
int Window::getWindowWidth() {
	return mWidth;
}

std::string Window::getWindowTitle()
{
	return mTitle;
}

bool Window::getShouldClose()
{
	return glfwWindowShouldClose(mWindow);
}

void Window::setResizability(bool mResizability) {
	if (mResizability) {
		if (mWindow) {
			glfwSetWindowAttrib(mWindow, GLFW_RESIZABLE, GL_TRUE);
		}
		else {
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		}
	}
	else {
		if (mWindow) {
			glfwSetWindowAttrib(mWindow, GLFW_RESIZABLE, GL_FALSE);
		}
		else {
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		}
	}
}

void Window::setMaximize(bool maximize) {
	if (maximize) {
		if (mWindow) {
			glfwMaximizeWindow(mWindow);
		}
		else {
			glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
		}
	}
	else {
		if (mWindow) {
			glfwRestoreWindow(mWindow);
		}
		else {
			glfwWindowHint(GLFW_MAXIMIZED, GL_FALSE);
		}
	}
}

void Window::setVisibility(bool visibility)
{
	if (visibility) {
		if (mWindow) {
			glfwShowWindow(mWindow);
		}
		else {
			glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
		}
	}
	else {
		if (mWindow) {
			glfwHideWindow(mWindow);
		}
		else {
			glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
		}
	}
}

void Window::setShouldClose(bool shouldClose)
{
	glfwSetWindowShouldClose(mWindow, shouldClose);
}

void Window::setCursorVisibility(bool visibility)
{
	if (visibility) {
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	else {
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
}

void Window::setContext()
{
	glfwMakeContextCurrent(mWindow);
}

void Window::newFrame()
{
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}

void Window::setViewport(int pWidth, int pHeight) {
	glViewport(0, 0, pWidth, pHeight);
}

void Window::framebufferSizeCallback(int pWidth, int pHeight) {
	mWidth = pWidth;
	mHeight = pHeight;
	setViewport(mWidth, mHeight);
}

void Window::windowMaximizeCallback(int pMaximize) {
	if (pMaximize) {
		std::cout << mTitle << " window is maximized." << std::endl;
	}
	else {
		std::cout << mTitle << " window is minimized." << std::endl;
	}
}