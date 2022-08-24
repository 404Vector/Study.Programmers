#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool Comp(const pair<int,double> &a, const pair<int,double> &b){
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,int> stageStatus;
    vector<pair<int,double>> ranking;
    for(auto &s : stages)stageStatus[s]++;
    double people = stages.size();
    for(int i = 0; i < N; i++){
        double fail = stageStatus[i+1];
        ranking.push_back(pair<int,double>(i+1, people > 0 ? fail/people: 0));
        people -= fail;
    }
    sort(ranking.begin(), ranking.end(), Comp);
    for(auto &pair : ranking) answer.push_back(pair.first);
    return answer;
}