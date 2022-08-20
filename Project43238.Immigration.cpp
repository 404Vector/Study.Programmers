#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long minTime = 0;
    long long maxTime = times.back() * ((long long )n);
    while(minTime <= maxTime){
        long long meanTime = (maxTime+minTime) / 2;
        long long humans = 0;
        for(auto &t:times) humans+=meanTime/t;
        if(humans >= n) maxTime = meanTime - 1;
        else minTime = meanTime + 1;
    }
    return maxTime+1;
}