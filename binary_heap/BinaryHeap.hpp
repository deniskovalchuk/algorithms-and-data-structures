/**
 * binary_heap.hpp
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BinaryHeap {
private:
    int _size;
    vector<T> container;

    void put_up(int index);
    void put_down(int index);
    int get_parent(const int index) const;
    
public:
    BinaryHeap(int size = 10);
    ~BinaryHeap();
    
    void add(const T key);
    T top() const;
    void pop();
    void print() const;
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int size) {
    _size = 0;
    container.resize(size);
}

template<typename T>
BinaryHeap<T>::~BinaryHeap() {

}

template<typename T>
void BinaryHeap<T>::add(T key) {
    container.at(_size) = key;
    put_up(_size);
    _size++;
    
    if (_size == container.capacity()) {
        container.resize(container.size() * 2);
    }
}

template<typename T>
T BinaryHeap<T>::top() const {
    return container.at(0);
}

template<typename T>
void BinaryHeap<T>::put_up(int index) {
    int parent = get_parent(index);
    while (container.at(index) < container.at(parent)) {
        swap(container.at(index), container.at(parent));
        index = parent;
        parent = get_parent(index);
    }
}

template<typename T>
void BinaryHeap<T>::put_down(int index) {
    int index_child1 = index * 2 + 1;
    int index_child2 = index * 2 + 2;

    int new_index = index_child1;
    if (new_index > _size) {
        return;
    }
    
    if (index_child2 <= _size &&
        container.at(index_child2) < container.at(index_child1)) {
        new_index = index_child2;
    }

    if (container.at(index) > container.at(new_index)) {
        swap(container.at(index), container.at(new_index));    
        put_down(new_index);
    }
}

template<typename T>
void BinaryHeap<T>::pop() {
    if (_size == 0) {
        return;
    }
    
    container.at(0) = container.at(--_size);
    put_down(0);
}

template<typename T>
int BinaryHeap<T>::get_parent(int index) const {
    return index % 2 == 0 && index != 0 ? index / 2 - 1 : index / 2;
}

template<typename T>
void BinaryHeap<T>::print() const {
    for (int i = 0; i < _size; i++) {
        cout << container.at(i) << " ";
    }
    cout << endl;
}

#endif // BINARY_HEAP_HPP



