#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> pMap;
    for (int n : nums) {
        if (pMap.count(n)) pMap[n]++;
        else pMap.insert(pair<int, int>(n, 1));
    }
    int answer = pMap.size() > nums.size() / 2 ? nums.size() / 2 : pMap.size();
    return answer;
}