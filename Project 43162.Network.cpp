#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;
void DFS(map<int,unordered_set<int>> & network,vector<bool> &visited, int node, int depth){
    if(depth == network.size()) return;
    visited[node] = true;
    for(auto n : network[node]){
        if(visited[n]) continue;
        DFS(network, visited, n, depth+1);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false); 
    map<int,unordered_set<int>> network;
    for(int i=0; i < n; i++){
        for(int j=0;j<computers[i].size();j++){
            if(i == j || computers[i][j] == 0) continue;
            network[i].insert(j);
        }
    }
    for(int i = 0; i<n; i++){
        if(visited[i]) continue;
        DFS(network,visited,i,0);
        answer++;
    }
    return answer;
}