#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
void CreateCombination(string& order, map<string,int>& comb, string s, const int &pick, const int idx, const int depth){
    s += order[idx];
    if(depth == pick-1){
        comb[s]++;
        return;
    }
    for(int i = idx+1; i != order.size(); i++){
        CreateCombination(order, comb, s, pick, i, depth+1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<map<string,int>> comb(20);
    for(auto& order : orders){
        sort(order.begin(), order.end());
        for(int& c :course){
            for(int i = 0; i < order.size(); i++){
                CreateCombination(order, comb[c], "", c, i, 0);
            }
        }
    }
    
    for(auto &idx : course){
        map<int, vector<string>> tempMap;
        if(comb[idx].empty()) {continue;}
        for(auto&p:comb[idx]) tempMap[p.second].push_back(p.first);
        auto pair = *prev(tempMap.end());
        if(pair.first <2){continue;}
        for(auto&s : pair.second) answer.push_back(s);
    }
    sort(answer.begin(),answer.end());
    return answer;
}