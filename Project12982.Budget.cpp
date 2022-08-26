#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for(auto &b : d){
        budget -= b;
        if(budget<0) break;
        answer++;
    }
    return answer;
}