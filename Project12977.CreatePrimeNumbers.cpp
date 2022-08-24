#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PickNumbers(const vector<int> & nums, vector<int> & target, const int &pickCount, const int & index, const int &depth, int val){
    val += nums[index];
    if(depth == pickCount - 1){
        target.push_back(val);
    }
    else{
        for(int i = index + 1; i < nums.size(); i++){
            PickNumbers(nums, target, pickCount, i, depth+1, val);
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> values;
    vector<bool> primeNumberStatus;
    for(int i = 0; i < nums.size()-2; i++) PickNumbers(nums,values,3,i,0,0);
    sort(values.begin(), values.end());
    int maximum = values.back();
    primeNumberStatus = vector<bool>(maximum+1, true);
    primeNumberStatus[0] = false;
    primeNumberStatus[1] = false;
    for(int i = 2; i <= maximum; i++){
        if(!primeNumberStatus[i]) continue;
        for(int j = 2; j <= maximum/i; j++) primeNumberStatus[j*i] = false;
    }
    for(auto &i : values) if(primeNumberStatus[i]) answer++;
    return answer;
}