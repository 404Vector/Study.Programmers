#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool IsMax(vector<int>& v, int& target) {
    for (int i = 0; i < v.size(); i++) if (v[i] > target) return false;
    return true;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (priorities.size() > 0) {
        int first = priorities[0];
        priorities.erase(priorities.begin());
        if (IsMax(priorities, first)) {
            answer++;
            if (location == 0)break;
        }
        else priorities.push_back(first);
        location--;
        if (location < 0) location = priorities.size() - 1;
    }

    return answer;
}