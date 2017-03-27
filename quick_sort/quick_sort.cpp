/**
 * quick_sort.cpp 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void quick_sort(vector<T>&, int, int);

int main(int argc, char *argv[]) {

    vector<int> vec = {3, 7, 1, 0, 5, 9, 6, 2, 4, 8};
    
    quick_sort(vec, 0, vec.size() - 1);
    
    for (auto it : vec) {
        cout << it << endl;
    }
    
    return 0;
}

template<typename T>
void quick_sort(vector<T>& container, int left, int right) {
    int i = left, j = right;
    int pivot = container[left + (right - left) / 2];

    while (i <= j) {
        while (container.at(i) < pivot)
            i++;

        while (container.at(j) > pivot)
            j--;

        if (i <= j) {
            swap(container.at(i++), container.at(j--));
        }
    };

    if (left < j)
        quick_sort(container, left, j);

    if (i < right)
        quick_sort(container, i, right);
}
