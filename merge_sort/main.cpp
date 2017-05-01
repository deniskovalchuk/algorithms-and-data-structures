/**
 * main.cpp -- merge sort.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& array, size_t lindex, size_t rindex);

int main(int argc, char* argv[]) {
    vector<int> array = {7, 1, 4, 8, 2, 3, 0, 47, 10};

    merge_sort(array, 0, array.size() - 1);

    for (auto it : array) {
        cout << it << endl;
    }

    return 0;
}

void merge_sort(vector<int>& array, size_t lindex, size_t rindex) {
    if (lindex >= rindex) {
        return;
    }

    size_t middle = (lindex + rindex) / 2;
    merge_sort(array, lindex, middle);
    merge_sort(array, middle + 1, rindex);

    vector<int> tmp;
    size_t lidx = lindex, ridx = middle + 1;
    while (lidx <= middle && ridx <= rindex) {
        if (array[lidx] < array[ridx]) {
            tmp.push_back(array[lidx]);
            lidx++;
        } else {
            tmp.push_back(array[ridx]);
            ridx++;
        }
    }

    while (lidx <= middle) {
        tmp.push_back(array[lidx]);
        lidx++;
    }

    while (ridx <= rindex) {
        tmp.push_back(array[ridx]);
        ridx++;
    }

    copy(tmp.begin(), tmp.end(), array.begin() + lindex);
}
