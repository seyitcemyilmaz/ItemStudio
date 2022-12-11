#include "windowmanager.h"

#include "mouse.h"
#include "keyboard.h"

std::map<std::string, Window*> WindowManager::mIdToWindow;
std::map<GLFWwindow*, Window*> WindowManager::mGLFWwindowToWindow;

bool WindowManager::initalized = false;

WindowManager::WindowManager() {

}

Window* WindowManager::addNewWindow(std::string id, std::string title, unsigned int states, int width, int height) {
	if (!initalized) {
		glfwSetErrorCallback(errorCallback);
		if (!glfwInit()) {
			return nullptr;
		}
		const char* glsl_version = "#version 150";
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	Window* window = new Window(title, states, width, height);
	mIdToWindow[id] = window;
	mGLFWwindowToWindow[window->getWindow()] = window;

	return window->init();
}

Window* WindowManager::getWindow(std::string id) {
	return mIdToWindow[id];
}

void WindowManager::processInput()
{
	/*
	static double dt = 0.0f;
	static double lastFrame = 0.0f;
	static double currentTime = 0.0f;

	currentTime = glfwGetTime();
	dt = currentTime - lastFrame;
	lastFrame = currentTime;
	*/
	/*
	if (Keyboard::key(GLFW_KEY_ESCAPE)) {
		WindowManager::getActiveWindow()->setShouldClose(true);
	}
	*/
	/*
	double dx = Mouse::getDX();
	double dy = Mouse::getDY();

	if (dx != 0 || dy != 0) {
		Camera::activeCamera->updateCameraDirection(dx, dy);
	}

	double scrollDy = Mouse::getScrollDY();

	if (scrollDy != 0) {
		Camera::activeCamera->updateCameraZoom(scrollDy);
	}

	if (Keyboard::key(GLFW_KEY_ESCAPE)) {
		WindowManager::getActiveWindow()->setShouldClose(true);
	}

	if (Keyboard::key(GLFW_KEY_W)) {
		Camera::activeCamera->updateCameraPosition(CameraDirection::FORWARD, dt);
	}

	if (Keyboard::key(GLFW_KEY_S)) {
		Camera::activeCamera->updateCameraPosition(CameraDirection::BACKWARD, dt);
	}

	if (Keyboard::key(GLFW_KEY_D)) {
		Camera::activeCamera->updateCameraPosition(CameraDirection::RIGHT, dt);
	}

	if (Keyboard::key(GLFW_KEY_A)) {
		Camera::activeCamera->updateCameraPosition(CameraDirection::LEFT, dt);
	}

	if (Keyboard::key(GLFW_KEY_SPACE)) {
		Camera::activeCamera->updateCameraPosition(CameraDirection::UP, dt);
	}

	if (Keyboard::key(GLFW_KEY_LEFT_SHIFT)) {
		Camera::activeCamera->updateCameraPosition(CameraDirection::DOWN, dt);
	}

	WindowManager::activeWindow->scene->processInput(dt);
	*/
}

void WindowManager::framebufferSizeCallback(GLFWwindow* pWindow, int pWidth, int pHeight) {
	Window* tWindow = (Window*) glfwGetWindowUserPointer(pWindow);

	if (tWindow) {
		tWindow->framebufferSizeCallback(pWidth, pHeight);
	}
}

void WindowManager::windowMaximizeCallback(GLFWwindow* pWindow, int pMaximize) {
	Window* tWindow = (Window*)glfwGetWindowUserPointer(pWindow);

	if (tWindow) {
		tWindow->windowMaximizeCallback(pMaximize);
	}
}

void WindowManager::errorCallback(int pErrorCode, const char* pDescription) {
	std::cout << "Error code " << pErrorCode << ":" << pDescription;
}