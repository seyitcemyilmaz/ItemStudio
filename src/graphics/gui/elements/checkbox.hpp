#ifndef IS_CHECKBOX_HPP
#define IS_CHECKBOX_HPP

#include "element.hpp"

#include <iostream>

class Checkbox : public Element {
private:
    bool mIsChecked;
    const char* mText;
public:
    Checkbox(const char* pText, bool pIsChecked = false) : 
        mText(pText), 
        mIsChecked(pIsChecked) { }

    void process() {
        ImGui::Checkbox(mText, &mIsChecked);
    }

    bool isChecked() {
        return mIsChecked;
    }
};


#endif