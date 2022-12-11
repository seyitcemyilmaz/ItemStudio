#ifndef ITEM_STUDIO_GUI_H
#define ITEM_STUDIO_GUI_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "line.hpp"

#include "button.hpp"
#include "checkbox.hpp"
#include "radiobutton.hpp"
#include "text.hpp"

class GUI {
public:
	bool mInitialized;
public:
	GUI();
	~GUI();
	void init(GLFWwindow* pWindow);
	void render();
};


#endif