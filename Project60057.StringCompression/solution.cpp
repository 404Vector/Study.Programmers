#include <string>
#include <vector>
#include <iostream>

using namespace std;
void SplitToToken(string& target, vector<string>& token, int size) {
    for (int i = 0; i < target.size(); i++) {
        if (i % size == 0) { token.push_back(""); }
        token.back() += target[i];
    }
}
string CreateStringByToken(vector<string>& token) {
    string result = "";
    string lastToken = "";
    for (int i = 0; i < token.size(); i++) {
        string s = token[i];
        if (lastToken == s) { continue; }
        int score = 1;
        lastToken = s;

        for (int j = i + 1; j < token.size(); j++) {
            if (j > token.size() - 1) break;
            if (token[j] == token[i]) score++;
            else break;
        }
        s = score > 1 ? to_string(score) + s : s;
        result += s;
    }
    return result;
}
int solution(string s) {
    int answer = s.size();
    vector<int> caseScore;
    for (int i = 0; i < s.size(); i++)
    {
        vector<string>token;
        SplitToToken(s, token, i + 1);
        string ts = CreateStringByToken(token);
        answer = ts.size() < answer ? ts.size() : answer;
    }
    return answer;
}