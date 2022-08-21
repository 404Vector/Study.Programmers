#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    map<int,vector<int>> edgeMap;
    vector<vector<int>> depths;
    queue<int> bfsQueue;
    vector<bool> visited(n,false);
    for(auto v : edge){
        edgeMap[v[0]].push_back(v[1]);
        edgeMap[v[1]].push_back(v[0]);
    }
    bfsQueue.push(1);
    while(!bfsQueue.empty()){
        queue<int> nextBfs;
        vector<int> depth;
        while(!bfsQueue.empty()){
            int node = bfsQueue.front(); bfsQueue.pop();
            if(visited[node-1]) continue;
            depth.push_back(node);
            visited[node-1] = true;
            for(auto j : edgeMap[node]) nextBfs.push(j);
        }
        bfsQueue = queue<int>(nextBfs);
        if(!depth.empty()){depths.push_back(depth);}
    }
    return depths.back().size();
}