/**
 * main.cpp -- example (simple) b-tree.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include "b_tree.hpp"

int main(int argc, char *argv[]) {

    b_tree<string, int> b_tree(3); // degree - 3
    b_tree.insert(make_pair("f", 6));
    b_tree.insert(make_pair("a", 1));
    b_tree.insert(make_pair("d", 4));
    b_tree.insert(make_pair("e", 5));
    b_tree.insert(make_pair("c", 3));
    b_tree.insert(make_pair("b", 2));

    vector<int> trvrs;
    b_tree.traverse(trvrs);

    for (const auto& it : trvrs) {
        cout << it << " ";
    }
    cout << endl;

    b_tree["e"] = 47;
    cout << b_tree["e"] << endl;

    return 0;
}
