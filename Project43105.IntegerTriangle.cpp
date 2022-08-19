#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    if(triangle.size() == 1) return triangle[0][0];
    vector<vector<int>> plan(triangle.size());
    plan[0].push_back(triangle[0][0]);
    for(int row = 1; row < plan.size(); row++){
        plan[row] = vector<int>(triangle[row].size());
        for(int col = 0; col < plan[row].size(); col++){
            int left = (col > 0) ? plan[row-1][col-1] + triangle[row][col] : 0;
            int right = (col < plan[row].size()-1) ? plan[row-1][col] + triangle[row][col] : 0;
            plan[row][col] = max(left,right);
        }
    }
    for(auto col : plan.back()) answer = max(answer, col);
    return answer;
}