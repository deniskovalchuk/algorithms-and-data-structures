/**
 * main.cpp -- Segment tree.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>

using namespace std;

void create_segment_tree(vector<int>& data, vector<int>& st, size_t index, size_t l, size_t r) {
    if (l == r) {
        st[index] = data[l];
        return;
    }
    size_t medium = (l + r) / 2;
    create_segment_tree(data, st, 2 * index, l, medium);
    create_segment_tree(data, st, 2 * index + 1, medium + 1, r);
    st[index] = st[index * 2] + st[index * 2 + 1];
}

int st_sum(vector<int>& st, size_t index, size_t begin, size_t end, size_t l, size_t r) {
    if (l > r)
        return 0;

    if (l == begin && r == end)
        return st[index];
    
    size_t medium = (begin + end) / 2;
    return st_sum(st, index * 2, begin, medium, l, min(r, medium)) +
        st_sum(st, index * 2 + 1, medium + 1, end, max(l, medium + 1), r);
}

int main(int argc, char *argv[]) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> segment_tree(4 * data.size());

    create_segment_tree(data, segment_tree, 1, 0, data.size() - 1);

    for (auto &it : segment_tree) {
        cout << it << " ";
    }
    cout << endl;

    cout << st_sum(segment_tree, 1, 0, data.size() - 1, 1, 5) << endl;
    cout << st_sum(segment_tree, 1, 0, data.size() - 1, 0, 9) << endl;

    return 0;
}
