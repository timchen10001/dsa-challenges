#include "../../stack/array-stack/CStackArray.h"
#include <iostream>

int main(void) {

    CStackArray<char> stack;

    std::string name = "Tim Chen";

    for (int i = 0; i < name.size(); i++) {
        stack.push(name[i]);
    }

    std::string reversedName = "";

    char character;
    while (stack.size()) {
        stack.pop(character);
        reversedName += character;
    }

    std::cout << "Reversed Name >>> " << reversedName << std::endl;
};