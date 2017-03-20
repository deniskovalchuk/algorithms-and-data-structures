/**
 * main.cpp -- demo a hash table.
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>

#include "HashTable.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    HashTable<string, int> hash_table;

    hash_table.insert("Richard Stallman",   1953);
    hash_table.insert("Bjarne Stroustrup",  1950);
    hash_table.insert("Herbert Schildt",    1951);
    hash_table.insert("Guido van Rossum",   1956);
    hash_table.insert("Linus Torvalds",     1969);
    hash_table.insert("Bjarne Stroustrup",  1951);
    
    cout << "Herbert Schildt:   " << hash_table.get("Herbert Schildt") << endl;
    cout << "Bjarne Stroustrup: " << hash_table.get("Bjarne Stroustrup") << endl;
    cout << "Richard Stallman:  " << hash_table.get("Richard Stallman") << endl;

    try {
        cout << "Steve Jobs: " << hash_table.get("Steve Jobs");        
    } catch (KeyNotFoundException& exception) {
        cout << exception.what() << endl;
    }

    hash_table.remove("Linus Torvalds");

    try {
        cout << "Linus Torvalds: " << hash_table.get("Linus Torvalds") << endl;    
    } catch (KeyNotFoundException& exception) {
        cout << exception.what() << endl;
    }
    
    return 0;
}
