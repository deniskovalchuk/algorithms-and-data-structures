/**
 * LinkedList.hpp 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList
{
public:
    LinkedList();
    virtual ~LinkedList();

    void push_back(const T value);
    void push_front(const T value);
    void insert(const T value, const int position);
    void remove(const T value);
    void clear();
    T get(const int position);
    void reverse();
    bool empty() const;
    void print() const;
    int length() const;

private:
    class Node {
    public:
        T value;
        Node *next;
    };
    
    Node *head;
    Node *tail;
    int _length;

    void init(const T value);
};

template<typename T>
LinkedList<T>::LinkedList() {
    _length = 0;
    head = tail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void LinkedList<T>::clear() {
    _length = 0;
    for (Node *node = head; node != nullptr; node = node->next) {
        delete node;
    }  
}

template<typename T>
void LinkedList<T>::push_back(const T value) {
    if (empty()) {
        init(value);
        return;
    }
    _length++;
    tail->next = new Node();
    tail = tail->next;
    tail->value = value;
}

template<typename T>
void LinkedList<T>::push_front(const T value) {
    if (empty()) {
        init(value);
        return;
    }
    _length++;
    Node *node = new Node();
    node->value = value;
    node->next = head;
    head = node;
}

// warning: complexity O(n)
template<typename T>
void LinkedList<T>::insert(const T value, const int position) {
    if (position < 0 || position > _length) {
        throw out_of_range("Incorrect a position.");
    }    

    if (position == 0) {
        if (empty()) {
            init(value);
            return;
        }
        _length++;
        Node *node = new Node();
        node->value = value;
        node->next = head;
        head = node;
        return;
    }
    _length++;    
    Node *node = head;
    for (int i = 0; i < position - 1; i++, node = node->next);
    Node *tmp = node->next;
    Node *new_node = new Node();
    new_node->value = value;
    node->next = new_node;
    new_node->next = tmp;
}

template<typename T>
void LinkedList<T>::remove(const T value) {
    if (empty()) {
        return;
    }
    for (Node *node = head; node->next != nullptr; node = node->next) {
        if (value == node->next->value) {
            _length--;
            Node *tmp = node->next;
            node->next = node->next->next;
            delete tmp;
            break;
        }
    }
}

template<typename T>
void LinkedList<T>::reverse() {
    Node *previous = nullptr;
    Node *current;
    Node *next;
    tail = head;
    for (current = head; current != nullptr; current = next) {
        next = current->next;
        current->next = previous;
        previous = current;
    }
    head = previous;
}

template<typename T>
void LinkedList<T>::init(const T value) {
    _length++;
    head = new Node();
    head->value = value;
    tail = head;
}

template<typename T>
T LinkedList<T>::get(const int position) {
    if (position < 0 || position > _length - 1) {
        throw out_of_range("Incorrect a position.");
    }
    Node *node = head;
    for (int i = 0; i != position; i++, node = node->next);
    return node->value;
}

template<typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
void LinkedList<T>::print() const {
    for (Node *node = head; node != nullptr; node = node->next) {
        cout << node->value << " ";
    }
}

template<typename T>
int LinkedList<T>::length() const {
   return _length; 
}

#endif // LINKED_LIST_HPP
