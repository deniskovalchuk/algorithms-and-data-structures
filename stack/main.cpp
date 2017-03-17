/**
 * main.cpp -- demo a stack.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "Stack.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Stack<int> stack;

    for (int i = 0; i < 7; i++) {
        stack.push(i);
    }

    stack.pop();

    cout << stack.top() << endl;

    for (int i = 0; i < 20; i++) {
        try {
            stack.push(i);
        } catch (out_of_range) {
            break;
        }
    }

    cout << stack.top() << endl;
    
    return 0;
}
