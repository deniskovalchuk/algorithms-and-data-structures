#include <iostream>
#include "list.hpp"

using namespace std;

template<typename Iter>
Iter maximum(Iter begin, Iter end) {
    Iter max = begin;
    for (; begin != end; ++begin) {
        if (*max < *begin)
            max = begin;
    }
    return max;
}

template<typename T>
void print_list(list<T> l) {
    for (auto &it : l)
        cout << it << " ";
    cout << endl;
}

int main() {

    list<int> a = {1, 3, 5, 8, -5};

    print_list(a);

    auto it = maximum(a.begin(), a.end());
    a.insert(it, 7);
    print_list(a);
    
    return 0;
}
