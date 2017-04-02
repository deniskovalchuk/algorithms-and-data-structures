/**
 * main.cpp -- Dijkstra’s algorithm. 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <algorithm>

using namespace std;

int find_lowest_cost_node(vector<int>&, list<int>&);

int main(int argc, char *argv[]) {

    // see image in README.md
    vector<vector<pair<int, int>>> graph = {
        {pair<int, int>(1, 7), pair<int, int>(2, 9), pair<int, int>(5, 14)},
        {pair<int, int>(2, 10), pair<int, int>(3, 15)},
        {pair<int, int>(5, 2), pair<int, int>(3, 11)},
        {},
        {pair<int, int>(3, 6)},
        {pair<int, int>(4, 9)}
    };

    const int count_of_vertice = graph.size();
    
    vector<int> parent(count_of_vertice);
    vector<int> costs(count_of_vertice, numeric_limits<int>::max());
    list<int> used;

    int start_vertice = 0;
    costs.at(start_vertice) = 0;
    
    int node = find_lowest_cost_node(costs, used);
    while (node != -1) {
        vector<pair<int, int>> neighbors = graph.at(node);
        for (size_t i = 0; i < neighbors.size(); i++) {
            int neighbor = neighbors.at(i).first;
            int neighbor_cost = neighbors.at(i).second;
            if (costs.at(neighbor) > (costs.at(node) + neighbor_cost)) {
                parent.at(neighbor) = node;
                costs.at(neighbor) = costs.at(node) + neighbor_cost;
            }    
        }        
        used.push_back(node);
        node = find_lowest_cost_node(costs, used);
    }


    for (size_t i = 0; i < costs.size(); i++) {
        cout << "Shortest path from " << start_vertice <<
            " to " << i << " = " << costs.at(i) << endl;
    }
    
    return 0;
}

int find_lowest_cost_node(vector<int>& costs, list<int>& used) {
    int node = -1;
    int lowest_cost = numeric_limits<int>::max();
    for (size_t i = 0; i < costs.size(); i++) {
        if (costs.at(i) < lowest_cost
            && find(used.begin(), used.end(), i) == used.end()) {
            lowest_cost = costs.at(i);
            node = i;
        }
    }
    return node;
}
