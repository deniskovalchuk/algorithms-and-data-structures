/**
 * BinarySearchTree.hpp
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{    
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    
    void add(T key);
    void remove(T key);
    void preorder();
    void inorder();
    void postorder();
    void clear();
    
private:
    class Node {
    public:
        T key;
        Node *left;
        Node *right;
    };
    
    Node *root;
    
    Node *add(Node *node, T key);
    Node *remove(Node *node, T key);
    void preorder(Node *node);
    void inorder(Node *node);
    void postorder(Node *node);
    void delete_tree(Node *node);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete_tree(root);
}

template<typename T>
void BinarySearchTree<T>::add(T key) {
    if (root == nullptr) {
        root = new Node();
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        add(root, key);
    }    
}

template<typename T>
void BinarySearchTree<T>::remove(T key) {
    if (root->key == key) {
        root = remove(root, key);
        return;
    }
        
    if (key < root->key) {
        root->left = remove(root->left, key);
        return;
    }
    
    if (key > root->key) {
        root->right = remove(root->right, key);
        return;
    }
}

template<typename T>
void BinarySearchTree<T>::preorder() {
    preorder(root);
}

template<typename T>
void BinarySearchTree<T>::inorder() {
    inorder(root);
}

template<typename T>
void BinarySearchTree<T>::postorder() {
    postorder(root);
}

template<typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::add(Node *node, T key) {
    if (node == nullptr) {
        node = new Node();
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    
    if (key > node->key) {
        node->right = add(node->right, key);
    } else {
        node->left = add(node->left, key);
    }
    return node;   
}

template<typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::remove(Node *node, T key) {
    if (node == nullptr) {
        return node;
    }

    if (node->key == key) {
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

        Node *left_successor;
        left_successor = node->left;
        while (left_successor->left) {
            left_successor = left_successor->left;
        }
        node->key = left_successor->key;
        node->left = remove(node->left, left_successor->key);
    }
    
    if (key < node->key) {
        node->left = remove(node->left, key);
    }

    if (key > node->key) {
        node->right = remove(node->right, key);
    }
    return node;

}

template<typename T>
void BinarySearchTree<T>::preorder(Node *node) {
    if (node == nullptr) {
        return;
    }
    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

template<typename T>
void BinarySearchTree<T>::inorder(Node *node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

template<typename T>
void BinarySearchTree<T>::postorder(Node *node) {
    if (node == nullptr) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

template<typename T>
void BinarySearchTree<T>::clear() {
    delete_tree(root);
    root = nullptr;
}

template<typename T>
void BinarySearchTree<T>::delete_tree(Node *node) {
    if (node != nullptr) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

#endif // BINARY_SEARCH_TREE_HPP
