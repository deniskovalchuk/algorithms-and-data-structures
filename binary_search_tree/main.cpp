/**
 * main.cpp -- demo a binary search tree.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "BinarySearchTree.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    BinarySearchTree<int> tree;
    // see a img in README
    tree.add(8);
    tree.add(3);
    tree.add(10);
    tree.add(1);
    tree.add(6);
    tree.add(14);
    tree.add(4);
    tree.add(7);
    tree.add(13);
     
    tree.preorder();
    cout << endl;
    
    tree.postorder();
    cout <<  endl;

    tree.clear();

    tree.add(40);
    tree.add(60);
    tree.add(50);
    tree.add(45);
    tree.add(47);
    tree.add(48);
    tree.add(55);
    tree.add(70);
    tree.add(65);
    tree.add(61);

    tree.postorder();
    
    tree.remove(60);
    cout << endl;
    
    tree.postorder();
    cout << endl;
    
    return 0;
}
