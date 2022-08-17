#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int widthMax = 0;
    int heightMax = 0;
    for(auto &v : sizes){
        if(v[0] > v[1]){
            int temp = v[0];
            v[0] = v[1];
            v[1] = temp;
        }
        widthMax = widthMax > v[0] ? widthMax : v[0];
        heightMax = heightMax > v[1] ? heightMax : v[1];
    }
    answer = widthMax * heightMax;
    return answer;
}