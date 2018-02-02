//
//  main.cpp
//  Playground 3
//
//  Created by Takáts Bálint on 2018. 01. 11..
//  Copyright © 2018. Takáts Bálint. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<int> nodes[5002];
vector<int> rout,sols;
bool check [5002];
int node, edges;
int target_a , target_b;
bool dfs_r(const int curr_node,const int target){
    if (curr_node == target)
        return true;
    check[curr_node] = true;
    //bool mark = false;
    for (auto i : nodes[curr_node]){
        if(check[i] == false ){
            if(dfs_r(i,target) == true){
                rout.push_back(curr_node);
                //check[curr_node] = false;
                return true;
            }
        }
    }
    //check[curr_node] = false;
    return false;
}
bool dfs(const int curr_node,const int target){
    if (curr_node == target)
        return true;
    check[curr_node] = true;
    for (auto i : nodes[curr_node]){
        if(check[i] == false ){
            if(dfs(i,target) == true){
                check[curr_node] = false;
                return true;
            }
        }
    }
    //check[curr_node] = false;
    return false;
}
int main() {
    // insert code here...
    //std::cout << "Hello, World!\n";9 9 8 8 7
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> node  >> edges;
    cin >> target_a >> target_b;
    for (int i = 0; i < edges; i++){
        int t ,tt;
        cin >> t >> tt;
        nodes[t].push_back(tt);
        nodes[tt].push_back(t);
    }
    dfs_r(target_a,target_b);
    for(int i = 0; i < node + 2; i++)
        check[i] = false;
    check[target_b] = true;
    int current_start = target_b;
    for(int i = 0; i < rout.size()-1;i++){
        check[rout[i]] = true;
        check[current_start] = true;
        if(dfs(current_start,target_a) != true){
            check[rout[i]] = true;
            current_start = rout[i];
            sols.push_back(rout[i]);
        }
        else
            check[rout[i]] = false;
    }
    cout << sols.size() <<"\n";
    for (auto i: sols){
        cout << i << " ";
    }
}


















