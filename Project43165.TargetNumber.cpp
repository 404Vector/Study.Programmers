#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int>results(1);
    for(auto n : numbers){
        vector<int>nextResults;
        for(auto r : results) {
            nextResults.push_back(r+n);
            nextResults.push_back(r-n);
        }
        results = nextResults;
    }
    for(auto r : results) if(r == target) answer++;
    return answer;
}