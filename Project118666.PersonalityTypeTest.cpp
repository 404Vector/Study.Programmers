#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
const char r[] = {'T','R','F','C','M','J','A','N',};
char GetResult(map<char,int> &scoreMap, const char &a, const char &b){
    return scoreMap[a] == scoreMap[b] ? min(a,b) : scoreMap[a] > scoreMap[b] ? a : b;
}
string solution(vector<string> survey, vector<int> choices) {
    string answer = "0000";
    map<char,int> scoreMap;
    for(auto c : r) scoreMap[c] = 0;
    for(int i = 0; i < survey.size(); i++){
        string s = survey[i];
        int score = choices[i];
        if(score < 4) {
            scoreMap[s[0]] += 4 - score;
        }
        else if(score > 4){
            scoreMap[s[1]] += score - 4;
        }
    }
    answer[0] = GetResult(scoreMap,'T','R');
    answer[1] = GetResult(scoreMap,'C','F');
    answer[2] = GetResult(scoreMap,'J','M');
    answer[3] = GetResult(scoreMap,'A','N');
    return answer;
}