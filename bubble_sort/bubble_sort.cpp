/**
 * bubble_sort.cpp 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void bubble_sort(vector<T>&);

int main(int argc, char *argv[]) {

    vector<int> vec = {3, 4, 1, 8, 9, 2, 5, 7, 6, 0};

    bubble_sort(vec);

    for (auto it : vec) {
        cout << it << endl;
    }
    
    return 0;
}

template<typename T>
void bubble_sort(vector<T>& container) {
    for (size_t i = 0; i < container.size() - 1; ++i) {
        for (size_t j = 0; j < container.size() - 1 - i; ++j) {
            if (container.at(j) > container.at(j + 1)) {
                swap(container.at(j), container.at(j + 1));
            }
        }
    }
}
