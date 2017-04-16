/**
 * main.cpp
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <stack>

#include "PersistentStack.hpp"

using namespace std;

template<typename T>
void print_stack(stack<T> stack);

int main(int argc, char *argv[]) {

    PersistentStack<int> persistent_stack;
    // see README.md
    persistent_stack.push(17); // stack 1
    persistent_stack.push(27); // stack 2
    persistent_stack.push(4);  // stack 3
    persistent_stack.push(23); // stack 4
    persistent_stack.pop();    // stack 5

    stack<int> stack1 = persistent_stack.get(1);
    stack<int> stack4 = persistent_stack.get(4);
    stack<int> stack5 = persistent_stack.get(5);
    print_stack(stack1);
    print_stack(stack4);
    print_stack(stack5);
    
    persistent_stack.push(4, 47); // stack 6 - push 47 to stack number 4
    persistent_stack.push(5, 74); // stack 7 - push 74 to stack number 74
    persistent_stack.pop(3);      // stack 8 - pop top element of stack number 3

    stack<int> stack6 = persistent_stack.get(6);
    stack<int> stack7 = persistent_stack.get(7);
    stack<int> stack8 = persistent_stack.get(8);
    print_stack(stack6);
    print_stack(stack7);
    print_stack(stack8);
    
    return 0;
}

template<typename T>
void print_stack(stack<T> stack) {
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();        
    }
    cout << endl;
}
