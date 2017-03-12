/**
 * Tree.hpp -- binary tree.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Tree();
    virtual ~Tree();

    void add(int value);
    void remove(int value);
    void print();
    
private:
    Node *root;
    Node *add(Node *parent, int value);
    Node *remove(Node *node, int value);
    void print(Node *node);
    void delete_tree(Node *node);
};

#endif // TREE_HPP
