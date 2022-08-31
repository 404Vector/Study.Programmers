#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
int solution(int n) {
    int answer = 0;
    vector<int> tb;
    while(n){
        tb.push_back(n%3);
        n /= 3;
    }
    for(int i = 0; i != tb.size(); i++) answer += tb[i] * pow(3, tb.size()-1-i);
    return answer;
}
    