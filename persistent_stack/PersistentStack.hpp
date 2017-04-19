/**
 * PersistentStack.hpp
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef PERSISTENT_STACK_HPP
#define PERSISTENT_STACK_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

template<typename T>
class PersistentStack
{
public:
    PersistentStack();
    void push(const size_t number, const T& element);
    void push(const T& element);
    void pop(const size_t number);
    void pop();
    const T& top(const size_t number) const;
    const T& top() const;
    stack<T> get(const size_t number) const;
    stack<T> get() const;
    
private:
    class Node {
    public:
        Node(T elem, shared_ptr<Node> prev) : element(elem),
                                              previous(prev) { }

        const T& get_element() const {
            return element;
        }

        shared_ptr<Node> get_previous() const {
            return previous;
        }

    private:
        T element;
        shared_ptr<Node> previous;
    };

    /**
     * Vector containing top elements of all stacks.
     */
    vector<shared_ptr<Node>> tops;
    shared_ptr<Node> fictitious_head;
};

template<typename T>
PersistentStack<T>::PersistentStack() {
    fictitious_head = make_shared<Node>(0, nullptr);
    tops.push_back(fictitious_head);
}

/**
 * Push @param{element} to stack number @param{number}. 
 */
template<typename T>
void PersistentStack<T>::push(const size_t number, const T& element) {
    shared_ptr<Node> current_top = tops.at(number);
    shared_ptr<Node> new_top = make_shared<Node>(element, current_top);
    tops.push_back(new_top);
}

/**
 * Push @param{element} to the last modified stack.
 */
template<typename T>
void PersistentStack<T>::push(const T& element) {
    push(tops.size() - 1, element);
}

/**
 * Pop top element of stack number @param{number}.
 */
template<typename T>
void PersistentStack<T>::pop(const size_t number) {
    shared_ptr<Node> previous_top = tops.at(number)->get_previous();
    shared_ptr<Node> new_top = make_shared<Node>(*previous_top);
    tops.push_back(new_top);
}

/**
 * Pop top element of the last modified stack.
 */
template<typename T>
void PersistentStack<T>::pop() {
    pop(tops.size() - 1);
}

/**
 * Return top element of stack number @param{number}.
 */
template<typename T>
const T& PersistentStack<T>::top(const size_t number) const {
    return tops.at(number)->get_element();
}

/**
 * Return top element of the last modified stack.
 */
template<typename T>
const T& PersistentStack<T>::top() const {
    return tops.at(tops.size() - 1)->get_element();
}

/**
 * Return stack number @param{number}.
 */
template<typename T>
stack<T> PersistentStack<T>::get(const size_t number) const {
    shared_ptr<Node> node = tops.at(number);
    deque<T> dstack;

    while (node->get_previous()) {
        dstack.push_front(node->get_element());
        node = node->get_previous();
    }

    return stack<T>(dstack);
}

/**
 * Return the last modified stack.
 */
template<typename T>
stack<T> PersistentStack<T>::get() const {
    return get(tops.size() - 1);
}

#endif // PERSISTENT_STACK_HPP
