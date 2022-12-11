#ifndef IS_RADIOBUTTON_HPP
#define IS_RADIOBUTTON_HPP

#include <vector>

#include "element.hpp"

class RadioButton : public Element {
private:
    int mSelectedItemIndex;
    std::vector<const char*> mItemNames;

public:
    RadioButton(std::vector<const char*> pItemNames, int pSelectedItemIndex = -1) :
        mItemNames(pItemNames), 
        mSelectedItemIndex(pSelectedItemIndex) { }
    
    void process() {
        for (unsigned int i = 0; i < mItemNames.size(); i++) {
            ImGui::RadioButton(mItemNames[i], &mSelectedItemIndex, i);
        }
    }
};

#endif