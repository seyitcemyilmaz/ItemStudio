#ifndef IS_TEXT_HPP
#define IS_TEXT_HPP

#include "element.hpp"

class Text : public Element {
private:
    const char* mText;

public:
    Text(const char* pText) :
    mText(pText) { }

    void process() {
        ImGui::Text(mText);
    }
};


#endif