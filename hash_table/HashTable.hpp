/**
 * HashTable.hpp
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

class KeyNotFoundException : public exception {    
public:
    virtual const char* what() const throw() {
        return "Key not found.";
    }
} key_not_found;

template<typename TKey, typename TValue>
class HashTable
{
private:
    vector< list< pair<TKey, TValue> > > array;
    int _capacity;
    
    int hash(const TKey key);
    
public:
    HashTable(int capacity = 16);
    virtual ~HashTable();

    void insert(const TKey key, const TValue value);
    void remove(const TKey key) throw(KeyNotFoundException);
    TValue& get(const TKey key) throw(KeyNotFoundException);
};

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable(int capacity) {
    _capacity = capacity;
    array.resize(_capacity);
}

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::~HashTable() {

}

// FAQ6
template<typename TKey, typename TValue>
int HashTable<TKey, TValue>::hash(TKey key) {
	unsigned int hash = 0;
	for (size_t i = 0; i < key.length(); i++) {
		hash += static_cast<unsigned int>(key[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
    return hash % _capacity;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::insert(TKey key, TValue value) {
    int index = hash(key);
    list< pair<TKey, TValue> >& chain = array.at(index);

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            it->second = value;
            return;
        }
    }
    
    chain.push_back(make_pair(key, value));
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::remove(TKey key) throw(KeyNotFoundException) {
    int index = hash(key);
    list< pair<TKey, TValue> >& chain = array.at(index);

    auto it = remove_if(chain.begin(), chain.end(),
              [key](pair<TKey, TValue>& pair) -> bool { return pair.first == key; });

    if (it == chain.end()) {
        throw key_not_found;
    }

    chain.erase(it, chain.end());
}

template<typename TKey, typename TValue>
TValue& HashTable<TKey, TValue>::get(TKey key) throw(KeyNotFoundException) {
    int index = hash(key);
    list< pair<TKey, TValue> >& chain = array.at(index);

    auto it = find_if(chain.begin(), chain.end(),
            [key](pair<TKey, TValue>& pair) -> bool { return pair.first == key; });

    if (it == chain.end()) {
        throw key_not_found;
    }

    return it->second;
}

#endif // HASHTABLE_HPP
