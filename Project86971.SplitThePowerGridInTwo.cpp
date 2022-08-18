#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<int,vector<int>> CreateGraph(const vector<vector<int>>&data){
    map<int,vector<int>> result;
    for(auto v : data){
        result[v[0]].push_back(v[1]);
        result[v[1]].push_back(v[0]);
    }
    return result;
}

void Search(map<int,vector<int>> &graph, vector<bool> &visited, int idx, const vector<int> &ignore){
    if(visited[idx-1]) return;
    visited[idx-1] = true;
    for(auto v : graph[idx]){
        if(idx == ignore[0] && v == ignore[1]){
            continue;
        }
        else if(idx == ignore[1] && v == ignore[0]){
            continue;
        }
        Search(graph,visited,v,ignore);
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    map<int,vector<int>> graph = CreateGraph(wires);
    int answer = n;
    for(int i = 0; i < wires.size(); i++){
        vector<int>ignore = wires[i];
        vector<bool>visited(n);
        Search(graph,visited,1,ignore);
        int s = 0;
        for(auto b : visited) if(b) s++;
        answer = min(answer, abs(n - (2*s)));
    }
    return answer;
}