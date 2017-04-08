/**
 * main.cpp -- depth-first search. 
 *
 * Copyright (c) 2017, Denis Kovalchuk <deniskk25@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>&, vector<int>&, list<int>&, int);

int main(int argc, char *argv[]) {

    vector<vector<int>> graph = {
        {1, 3},
        {2},
        {},
        {4, 5},
        {6},
        {},                        
        {}
    };

    vector<int> used(graph.size());
    list<int> ans;
    
    dfs(graph, used, ans, 0);

    reverse(ans.begin(), ans.end());

    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;
    
    return 0;
}

void dfs(vector<vector<int>>& graph, vector<int>& used, list<int>& ans, int start) {
    used.push_back(start);
    for (size_t i = 0; i < graph.at(start).size(); i++) {
        if (find(used.begin(), used.end(), graph.at(start).at(i)) == used.end()) {
            dfs(graph, used, ans, graph.at(start).at(i));
        }
    }
    ans.push_back(start);
}
