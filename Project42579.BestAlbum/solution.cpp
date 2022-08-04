#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool CompareGScore(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<pair<string, int>> SortGScoreMap(map<string, int>& target) {
    vector<pair<string, int>> v(target.begin(), target.end());
    sort(v.begin(), v.end(), CompareGScore);
    return v;
}

bool CompareScore(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<pair<int, int>> SortScoreMap(map<int, int>& target) {
    vector<pair<int, int>> v(target.begin(), target.end());
    sort(v.begin(), v.end(), CompareScore);
    return v;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, map<int, int>> scoreMap;
    map<string, int>gScoreMap;
    int size = genres.size();
    for (int i = 0; i < size; i++) {
        scoreMap[genres[i]] = map<int, int>();
        gScoreMap[genres[i]] += plays[i];
    }
    auto sortedGScoreMap = SortGScoreMap(gScoreMap);
    for (int i = 0; i < size; i++) {
        scoreMap[genres[i]][i] = plays[i];
    }
    for (auto sgsKVP : sortedGScoreMap) {
        auto scoreMapItem = scoreMap[sgsKVP.first];
        auto sortedItem = SortScoreMap(scoreMapItem);
        for (int i = 0; i < sortedItem.size(); i++) {
            answer.push_back(sortedItem[i].first);
            if (i == 1) break;
        }
    }
    return answer;
}