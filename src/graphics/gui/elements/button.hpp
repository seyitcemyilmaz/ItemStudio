#ifndef IS_BUTTON_HPP
#define IS_BUTTON_HPP

#include <iostream>

#include "element.hpp"

class Button : public Element {
private:
    bool mIsClicked;
    const char* mText;
public:
    Button(const char* pText) : 
        mText(pText) {
        mIsClicked = false;
    }

    void process() {
        if (ImGui::Button(mText)) {
            mIsClicked = true;
            std::cout << "Clicked" << std::endl;
        }
        else {
            mIsClicked = false;
        }
    }
};

#endif