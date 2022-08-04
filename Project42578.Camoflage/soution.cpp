#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, vector<string>> itemMap;
    for (auto vec : clothes) itemMap[vec[1]].push_back(vec[0]);
    for (auto kvPair : itemMap)answer *= kvPair.second.size() + 1;
    return answer - 1;
}