/**
 * main.cpp -- demo a red-black tree.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "RedBlackTree.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    RedBlackTree<int> red_black_tree;
    
    red_black_tree.add(100);
    red_black_tree.add(500);
    red_black_tree.add(600);
    red_black_tree.add(50);
    red_black_tree.add(40);
    red_black_tree.add(70);
    red_black_tree.add(80);
    
    red_black_tree.postorder();
    
    return 0;    
}
