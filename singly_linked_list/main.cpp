/**
 * main.cpp -- demo a linked list.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    
    LinkedList<int> list;
    list.push_back(1);    
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_front(-1);
    list.push_front(-5);

    list.insert(9, 5);
    list.insert(9, 0);
    list.insert(9, list.length() - 1);
    
    list.print();
    cout << endl;
    
    cout << "length: "<< list.length() << endl;
    list.remove(6);
    cout << "length: " << list.length() << endl;
    
    list.print();
    cout << endl;

    cout << list.get(5) << endl;

    list.reverse();
    list.print();
    cout << endl;

    list.push_back(10);
    list.push_front(-10);
    list.print();
    cout << endl;
    
    return 0;
}
