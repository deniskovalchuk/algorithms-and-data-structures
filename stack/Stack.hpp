/**
 * Stack.hpp 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Stack
{
public:
    Stack(const int capacity = 16);
    virtual ~Stack();

    void push(const T& value) throw(std::out_of_range);
    void pop();
    T& top() const;
    int size() const;
    int capacity() const;
    bool empty() const;
    
private:
    int _capacity;
    int _top;
    T *array;
};

template<typename T>
Stack<T>::Stack(const int capacity) {
    _capacity = capacity;
    array = new T[capacity];
    _top = 0;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template<typename T>
void Stack<T>::push(const T& value) throw(std::out_of_range) {
    if (_top == _capacity) {
        throw std::out_of_range("Incorrect a index.");
    }
    array[++_top] = value;
}

template<typename T>
void Stack<T>::pop() {
    if (_top  == 0) {
        return;
    }
    _top--;
}

template<typename T>
T& Stack<T>::top() const {
    return array[_top];
}

template<typename T>
int Stack<T>::size() const {
    return _top;
}

template<typename T>
int Stack<T>::capacity() const {
    return _capacity;
}

template<typename T>
bool Stack<T>::empty() const {
    return _top < 0;
}

#endif // STACK_HPP
