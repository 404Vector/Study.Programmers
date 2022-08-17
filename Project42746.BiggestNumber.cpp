#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    auto comp = [](const string& a, const string& b) {
        return a + b > b + a;
    };
    vector<string> sN;
    for (int n : numbers) sN.push_back(to_string(n));
    sort(sN.begin(), sN.end(), comp);
    for (string s : sN) answer += s;
    if (answer[0] == '0') answer = "0";
    return answer;
}