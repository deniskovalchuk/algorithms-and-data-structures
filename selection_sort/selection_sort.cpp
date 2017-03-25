/**
 * selection_sort.cpp 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void selection_sort(vector<T>&);

int main(int argc, char *argv[]) {

    vector<int> vec = {7, 1, 9, 2, 8, 0, 4, 3, 6, 5};

    selection_sort(vec);
    
    for (auto it : vec) {
        cout << it << endl;
    }
    
    return 0;
}

template<typename T>
void selection_sort(vector<T>& container) {
    for (auto i = container.begin(); i != container.end(); ++i) {
        auto searched_max = i;
        T max = *i;
        for (auto j = i + 1; j != container.end(); ++j) {
            if (*j > max) {
                searched_max = j;
                max = *j;
            }
        }
        iter_swap(i, searched_max);
    }
}
