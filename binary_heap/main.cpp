/**
 * main.cpp -- binary heap.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "BinaryHeap.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    BinaryHeap<int> bh(10);
    
    bh.add(5);
    bh.add(4);
    bh.add(7);
    bh.add(1);
    bh.add(6);
    bh.add(9);
    bh.add(-14);

    bh.print();

    bh.pop();
    bh.print();

    bh.pop();
    bh.print();

    bh.pop();
    bh.print();
        
    return 0;
}
