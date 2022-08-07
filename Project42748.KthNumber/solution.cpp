#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto c : commands) {
        vector<int>subArray = vector<int>(c[1] - c[0] + 1);
        copy(array.begin() + c[0] - 1, array.begin() + c[1], subArray.begin());
        sort(subArray.begin(), subArray.end());
        answer.push_back(subArray[c[2] - 1]);
    }
    return answer;
}