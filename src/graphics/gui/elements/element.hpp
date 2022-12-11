#ifndef IS_ELEMENT_HPP
#define IS_ELEMENT_HPP

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Element {
public:
    virtual void process() = 0;
};

#endif