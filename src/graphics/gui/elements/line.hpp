#ifndef IS_LINE_HPP
#define IS_LINE_HPP

#include <vector>

#include "element.hpp"

class Line : public Element {
private:
    std::vector<Element*> mElements;

public:
    Line(std::vector<Element*> pElements) : 
        mElements(pElements) { }

    void process() {
        for (unsigned int i = 0; i < mElements.size() - 1; i++) {
            mElements[i]->process();
            ImGui::SameLine();
        }
        mElements[mElements.size() - 1]->process();
    }
};

#endif