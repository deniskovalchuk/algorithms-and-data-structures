/**
 * bfs.cpp
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <map>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool bfs(vector<vector<int>>&, int, int);
void bfs(vector<vector<int>>& graph, int start_vertice);

int main(int argc, char *argv[]) {

    /*
      ---------> 6<-----------------
      |                            |
      |                     ------>2
      |                     |
      |                     |
      |                     |
      |             ------>1|
      |             |       |
      |             |       ------>3
      |             |              |
      4<------------0              |
      |             |              |
      |             |              |
      |             |   7<---------- 
      |             |   |
      5<------------    |
      ^                 |
      -------------------
    */

    vector<vector<int>> graph {
      // 0, 1, 2, 3, 4, 5, 6  7  
        {0, 1, 0, 0, 1, 1, 0, 0}, // 0                                 
        {0, 0, 1, 1, 0, 0, 0, 0}, // 1
        {0, 0, 0, 0, 0, 0, 1, 0}, // 2
        {0, 0, 0, 0, 0, 0, 0, 1}, // 3
        {0, 0, 0, 0, 0, 1, 1, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0}, // 5
        {0, 0, 0, 0, 0, 0, 0, 0}, // 6
        {0, 0, 0, 0, 0, 1, 0, 0}  // 7
    };                             

    // from 5 to 4
    if (bfs(graph, 5, 4)) {
        cout << "Path exists!" << endl;
    }

    bfs(graph, 0);
    
    return 0;
}

void add_candidates(deque<int>& candidates, vector<int>& neighbors, list<int>& used) {
    for (size_t i = 0; i < neighbors.size(); i++) {
        if (neighbors.at(i) == 1 && find(used.begin(), used.end(), i) == used.end()) {
            candidates.push_back(i);
            used.push_back(i);
        }
    }
}

/**
 * Return true if a path between start_verice and search_vertice exists.
 */
bool bfs(vector<vector<int>>& graph, int start_vertice, int search_vertice) {
    deque<int> candidates;
    list<int> used;

    used.push_back(start_vertice);
    add_candidates(candidates, graph.at(start_vertice), used);
    
    while (!candidates.empty()) {
        int candidate = candidates.front();
        candidates.pop_front();
        // used.push_back(candidate);
        if (search_vertice == candidate) {
            return true;
        }
        add_candidates(candidates, graph.at(candidate), used);
    }
    return false;
}

/**
 * Print all shortest lengths from start_vectice to others.
 */
void bfs(vector<vector<int>>& graph, int start_vertice) {
    deque<int> candidates;
    list<int> used;
    vector<int> parent(graph.at(0).size());
    vector<int> distance(graph.at(0).size(), 0);
    
    parent.at(start_vertice) = -1;
    candidates.push_front(start_vertice);
    
    while (!candidates.empty()) {
        int candidate = candidates.front();
        candidates.pop_front();
        for (size_t i = 0; i < graph.at(candidate).size(); i++) {
            if (graph.at(candidate).at(i) == 1 &&
                find(used.begin(), used.end(), i) == used.end()) {
                used.push_back(i);
                candidates.push_back(i);
                parent.at(i) = candidate;
                distance.at(i) = distance.at(candidate) + 1;
            }
        }
    }

    for (size_t i = 0; i < distance.size(); i++) {
        cout << "path from vertice " << start_vertice <<
            " to vertice " << i << " = " << distance.at(i) << endl;
    }
}
