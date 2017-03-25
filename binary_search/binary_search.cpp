/**
 * binary_search.cpp 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
typename vector<T>::const_iterator binary_search(const vector<T>&, const T);

int main(int argc, char *argv[]) {
    
    vector<int> vec = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    auto  itr = binary_search(vec, 7);

    if (itr != vec.end()) {
        cout << *itr << endl;
    }
    
    return 0;
}

template<typename T>
typename vector<T>::const_iterator binary_search(const vector<T>& container, const T element) {
    typename vector<T>::const_iterator low = begin(container);
    typename vector<T>::const_iterator high = end(container);

    if (container.size() == 0 || container.front() > element || container.back() < element) {
        return container.end();
    }

    typename vector<T>::const_iterator middle;
    while  (distance(low, high) >= 0) {
        middle = low + distance(low, high) / 2;

        if (*middle == element) {
            return middle;
        }

        if (element > *middle) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    
    return container.end();
}
