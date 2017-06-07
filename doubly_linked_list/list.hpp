#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class list {
private:
    struct node {
        T value;
        node *next;
        node *prev;

        node(const T &val = T(), node *n = nullptr, node *p = nullptr)
                : value(val), next(n), prev(p) {}
    };

    node *_first;
    node *_last;

public:
    list() {
        _first = new node();
        _last = new node();
        _first->next = _last;
        _last->prev = _first;
    }

    list(initializer_list<T> lst) : list() {
        for (auto &it : lst)
            push_back(it);
    }

    list(const list &other) : list() {
        for (auto &it : other)
            push_back(it);
    }

    ~list() {
        while (!empty())
            pop_back();
        delete _first;
        delete _last;
    }

    struct iterator {
        node *curr;

        iterator(node *node) : curr{node} {}

        iterator &operator++() {
            curr = curr->next;
            return *this;
        }

        iterator &operator--() {
            curr = curr->prev;
            return *this;
        }

        T &operator*() const {
            return curr->value;
        }

        bool operator==(const iterator &other) { return curr == other.curr; }

        bool operator!=(const iterator &other) { return curr != other.curr; }
    };

    struct const_iterator {
        node *curr;

        const_iterator(node *node) : curr{node} {}

        const_iterator &operator++() {
            curr = curr->next;
            return *this;
        }

        const_iterator &operator--() {
            curr = curr->prev;
            return *this;
        }

        const T &operator*() const {
            return curr->value;
        }

        bool operator==(const_iterator &other) { return curr == other.curr; }

        bool operator!=(const_iterator &other) { return curr != other.curr; }
    };

    iterator begin() {
        return iterator(_first->next);
    }

    const_iterator begin() const {
        return const_iterator(_first->next);
    }

    const_iterator cbegin() const {
        return begin();
    }

    iterator end() {
        return iterator(_last);
    }

    const_iterator end() const {
        return const_iterator(_last);
    }

    const_iterator cend() const {
        return end();
    }

    void push_back(const T &val) {
        insert(end(), val);
    }

    void pop_back() {
        erase(--end());
    }

    void pop_front() {
        erase(begin());
    }

    void push_front(const T &val) {
        insert(begin(), val);
    }

    iterator insert(iterator p, const T &val) {
        node *n = new node(val, p.curr, p.curr->prev);
        p.curr->prev->next = n;
        p.curr->prev = n;
        return iterator(n);
    }

    iterator erase(iterator p) {
        node *n = p.curr;
        node *ret = n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
        return iterator(ret);
    }

    bool empty() {
        return begin() == end();
    }

    T &front() {
        return *(begin());
    }

    const T &front() const {
        return *(begin());
    }

    T &back() {
        return *(--end());
    }

    const T &back() const {
        return *(--end());
    }
};

#endif //LIST_HPP
