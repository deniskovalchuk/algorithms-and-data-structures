/**
 * Tree.cpp -- binary tree. 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */


#include "Tree.hpp"

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    delete_tree(root);
}

void Tree::add(int value)
{
    if (root == nullptr) {
        root = new Node();
        root->value = value;
    } else {
        add(root, value);
    }
}

Node *Tree::add(Node *node, int value)
{
    if (node == nullptr) {
        node = new Node();
        node->value = value;
        node->left = node->right = nullptr;
        return node;
    }
    
    if (value > node->value) {
        node->right = add(node->right, value);
    } else {
        node->left = add(node->left, value);
    }
    return node;
}

void Tree::remove(int value)
{
    if (root->value == value) {
        root = remove(root, value);
        return;
    }
        
    if (value < root->value) {
        root->left = remove(root->left, value);
        return;
    }
    
    if (value > root->value) {
        root->right = remove(root->right, value);
        return;
    }
}

Node *Tree::remove(Node *node, int value)
{
    if (!node) {
        cerr << "Value not found." << endl;
        return node;
    }

    if (node->value == value) {
        // if a node hasn't children
        if (node->left == node->right) {
            delete node;
            return nullptr;
        }
        // if only a right child
        if (node->left == nullptr) {
            Node *tmp = node->right;
            delete node;
            return tmp;
        }
        // if only a left child
        if (node->right == nullptr) {
            Node *tmp = node->left;
            delete node;
            return tmp;            
        }

        Node *tmp_right, *tmp_right2;
        tmp_right = node->right;
        tmp_right2 = node->right;
        
        while (tmp_right->left) {
            tmp_right = tmp_right->left;
        }
        tmp_right->left = node->left;
        delete node;
        return tmp_right2;        
    }
    
    if (value < node->value) {
        node->left = remove(node->left, value);
    }

    if (value > node->value) {
        node->right = remove(node->right, value);
    }
    return node;
}

void Tree::delete_tree(Node *node)
{
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

void Tree::print()
{
    print(root);
}

void Tree::print(Node *node)
{
    if (node == nullptr) {
        return;
    }

    cout << node->value << endl;
    print(node->left);
    print(node->right);
}
