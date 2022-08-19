#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
bool Comp(const vector<int>&a,const vector<int>&b){
    return a[2] < b[2];
}
int GetParent(const vector<int> &parents, const int & idx){
    if(idx == parents[idx]) return idx;
    return GetParent(parents, parents[idx]);
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parents(n);
    for(int i = 0; i < n; i++) parents[i] = i;
    sort(costs.begin(),costs.end(), Comp);
    for(auto v : costs){
        int nodeFirst = GetParent(parents,v[0]);        
        int nodeSecond = GetParent(parents,v[1]); 
        if(nodeFirst != nodeSecond){
            parents[nodeSecond] = nodeFirst;
            answer += v[2];
        }
    }
    return answer;
}


