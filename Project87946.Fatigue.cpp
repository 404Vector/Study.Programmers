#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> MakePermutation(vector<int> & data){
    vector<vector<int>> result;
    do{
        vector<int> subVec(data.begin(),data.end());
        result.push_back(subVec);
    }while(next_permutation(data.begin(),data.end()));
    return result;
}
int GetAvailableCount(vector<vector<int>> &dungeons, vector<int>& idxs, int k){
    int result = 0;
    for(int idx : idxs){
        if(dungeons[idx][0]>k) break;
        k -= dungeons[idx][1];
        result++;
    }
    return result;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> idxVec(dungeons.size());
    for(int i = 0; i<dungeons.size(); i++)idxVec[i] = i;
    auto p = MakePermutation(idxVec);
    for(auto v : p){
        answer = max(GetAvailableCount(dungeons,v,k), answer);
    }
    return answer;
}