#include <iostream>
#include "../../stack/array-stack/CStackArray.h"

bool isValidParentheses(CStackArray<char>* stack, std::string target);
char getSubParentheses(char character);

int main(void) {
    std::string input;

    while (1) {
        std::cout << "請輸入運算式。。。 (輸入 0 離開)\n";
        std::cin >> input;

        if (input == "0")
            break;
        
        CStackArray<char> stack;

        if (isValidParentheses(&stack, input)) {
            std::cout << "\ntrue\n";
        } else {
            std::cout << "\nfalse\n";
        }
    }
};

bool isValidParentheses(CStackArray<char>* stack, std::string target) {
    for (int i = 0; i < target.size(); i++) {
        char sub = getSubParentheses(target[i]);

        if (sub == 'X')
            continue;

        if (i == 0 || stack->top('X') != sub) {
            stack->push(target[i]);
        } else {
            stack->pop();
        }
    }
    return stack->size() == 0;
}

char getSubParentheses(char character) {
    switch (character) {
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
        case '{':
            return '}';
        case '}':
            return '{';
        default:
            return 'X';
    }
    return 'X';
}