#ifndef B_TREE_HPP
#define B_TREE_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename TKey, typename TValue>
class b_tree {
private:
    struct node;

public:

    explicit b_tree(size_t min_dgr): root(nullptr), min_degree(min_dgr) { }

    ~b_tree();

    void insert(const pair<TKey, TValue>&);

    TValue& operator[](const TKey&);

    const TValue& operator[](const TKey&) const;

    void traverse(vector<TValue>&) const;

private:

    struct node {
        vector<pair<TKey, TValue>> keys;

        vector<node *> children;

        size_t min_degree;

        bool leaf;

        node(size_t min_dgr, bool lf);

        ~node();

        void insert_non_full(const pair<TKey, TValue>&);

        void split_child(int i, node *y);

        TValue& operator[](const TKey&);

        void traverse(vector<TValue>&) const;

        inline bool full() const;
    };

    node *root;

    size_t min_degree;

    TValue& search(node *node, const TKey& key);
};

template<typename TKey, typename TValue>
b_tree<TKey, TValue>::node::node(size_t min_dgr, bool lf) : min_degree(min_dgr), leaf(lf) {
    keys.reserve(2 * min_degree - 1);
    children.reserve(2 * min_degree);
}

template<typename TKey, typename TValue>
b_tree<TKey, TValue>::node::~node() {
    for (const auto& it : children)
        delete it;
}

template<typename TKey, typename TValue>
b_tree<TKey, TValue>::~b_tree() {
    delete root;
}

template<typename TKey, typename TValue>
TValue&
b_tree<TKey, TValue>::operator[](const TKey& key) {
    return search(root, key);
}

template<typename TKey, typename TValue>
const TValue&
b_tree<TKey, TValue>::operator[](const TKey& key) const {
    return search(root, key);
}

template<typename TKey, typename TValue>
inline bool
b_tree<TKey, TValue>::node::full() const {
    return keys.size() == min_degree * 2 - 1;
}


template<typename TKey, typename TValue>
TValue&
b_tree<TKey, TValue>::search(node *node, const TKey& key) {
    if (node == nullptr) {
        insert(make_pair(key, TValue()));
        return search(root, key);
    }

    auto it = find_if(node->keys.begin(), node->keys.end(), [&](const pair<TKey, TValue>& pr) {
        return key <= pr.first;
    });

    if (it != node->keys.end() && (*it).first == key)
        return (*it).second;

    if (node->leaf) {
        insert(make_pair(key, TValue()));
        return search(root, key);
    }

    return search(node->children[distance(node->keys.begin(), it)], key);
}

template<typename TKey, typename TValue>
void
b_tree<TKey, TValue>::traverse(vector<TValue>& vec) const {
    if (root != nullptr)
        root->traverse(vec);
}

template<typename TKey, typename TValue>
void
b_tree<TKey, TValue>::node::traverse(vector<TValue>& vec) const {
    size_t i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse(vec);
        vec.push_back(keys[i].second);
    }
    if (!leaf)
        children[i]->traverse(vec);
}

template<typename TKey, typename TValue>
void
b_tree<TKey, TValue>::insert(const pair<TKey, TValue> &elem) {
    if (root == nullptr) {
        root = new node(min_degree, true);
        root->keys.push_back(elem);
    } else {
        if (root->full()) {
            node *new_root = new node(min_degree, false);
            new_root->children.push_back(root);
            new_root->split_child(0, root);
            if (elem.first < new_root->keys[0].first)
                new_root->children[0]->insert_non_full(elem);
            else
                new_root->children[1]->insert_non_full(elem);
            root = new_root;
        } else {
            root->insert_non_full(elem);
        }
    }
}

template<typename TKey, typename TValue>
void
b_tree<TKey, TValue>::node::insert_non_full(const pair<TKey, TValue>& elem) {
    if (leaf) {
        auto it = find_if(keys.begin(), keys.end(), [&](const pair<TKey, TValue>& pr) {
            return elem.first <= pr.first;
        });

        if (it->first == elem.first)
            it->second = elem.second;
        else
            keys.insert(it, elem);
    } else {
        auto it = find_if(keys.begin(), keys.end(), [&](const pair<TKey, TValue>& pr) {
            return elem.first < pr.first;
        });
        auto pos = distance(keys.begin(), it);

        if (children[pos]->full()) {
            split_child(pos, children[pos]);
            if (keys[pos].first < elem.first)
                ++pos;
        }
        children[pos]->insert_non_full(elem);
    }
}

template<typename TKey, typename TValue>
void
b_tree<TKey, TValue>::node::split_child(int i, node *y) {
    // right node after split
    node *z = new node(y->min_degree, y->leaf);

    copy(y->keys.begin() + min_degree, y->keys.end(), back_inserter(z->keys));

    if (!y->leaf) {
        copy(y->children.begin() + min_degree, y->children.end(), back_inserter(z->children));
        y->children.erase(y->children.begin() + min_degree, y->children.end());
    }

    children.insert(children.begin() + i + 1, z);

    keys.insert(keys.begin() + i, y->keys[min_degree - 1]);

    y->keys.erase(y->keys.begin() + min_degree - 1, y->keys.end());
}

#endif // B_TREE_HPP
