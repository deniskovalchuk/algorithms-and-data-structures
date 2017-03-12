/**
 * main.cpp -- demo a binary tree.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "Tree.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Tree tree;

    // see README.md
    tree.add(8);
    tree.add(3);
    tree.add(10);
    tree.add(1);
    tree.add(6);
    tree.add(14);
    tree.add(4);
    tree.add(7);
    tree.add(13);

    tree.print();
    
    tree.remove(8);
    tree.print();
    
    return 0;
}
