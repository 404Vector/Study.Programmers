#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define PII pair<int,int>
using namespace std;
int GetValue(const vector<int>& v, const int& idx) {
    return v[idx % v.size()];
}
bool Compair(const PII& a, const PII& b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<PII> scores = vector<PII>({ PII(0,1), PII(0,2), PII(0,3) });
    vector<int> A = vector<int>({ 1, 2, 3, 4, 5 });
    vector<int> B = vector<int>({ 2, 1, 2, 3, 2, 4, 2, 5 });
    vector<int> C = vector<int>({ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 });
    for (int i = 0; i < answers.size(); i++) {
        if (GetValue(A, i) == answers[i]) scores[0].first++;
        if (GetValue(B, i) == answers[i]) scores[1].first++;
        if (GetValue(C, i) == answers[i]) scores[2].first++;
    }
    sort(scores.begin(), scores.end(), Compair);
    answer.push_back(scores[0].second);
    if (scores[0].first == scores[1].first) answer.push_back(scores[1].second);
    if (scores[0].first == scores[2].first) answer.push_back(scores[2].second);
    return answer;
}