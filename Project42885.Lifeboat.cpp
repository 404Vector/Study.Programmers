#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(), greater<int>());
    int frontIdx = 0;
    int backIdx = people.size()-1;
    while(frontIdx <= backIdx){
        if(people[frontIdx]+people[backIdx] <=limit) backIdx--;
        frontIdx++;
    }
    return frontIdx;
}