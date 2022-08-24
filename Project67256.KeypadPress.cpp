#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int,vector<int>> KEY_POSITION_MAP({
    {1,{0,0}},
    {2,{0,1}},
    {3,{0,2}},
    {4,{1,0}},
    {5,{1,1}},
    {6,{1,2}},
    {7,{2,0}},
    {8,{2,1}},
    {9,{2,2}},
    {10,{3,0}},
    {0,{3,1}},
    {11,{3,2}},
});
int GetNorm1Distance(const vector<int> &a, const vector<int> &b){
    int result = 0;
    for(int i = 0; i<a.size(); i++){
        result += abs(a[i] - b[i]);
    }
    return result;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> posL = KEY_POSITION_MAP[10];
    vector<int> posR = KEY_POSITION_MAP[11];
    for(auto n : numbers){
        auto targetPos = KEY_POSITION_MAP[n];
        if(targetPos[1] == 0){
            posL = vector<int>(targetPos);
            answer += "L";
        }
        else if (targetPos[1] == 2){
            posR = vector<int>(targetPos);
            answer += "R";
        }
        else{
            int dLeft = GetNorm1Distance(posL, targetPos);
            int dRight = GetNorm1Distance(posR, targetPos);
            if(dLeft == dRight){
                if(hand == "right"){
                    posR = vector<int>(targetPos);
                    answer += "R";
                }
                else{
                    posL = vector<int>(targetPos);
                    answer += "L";
                }
            }
            else{
                if(dLeft > dRight){
                    posR = vector<int>(targetPos);
                    answer += "R";
                }
                else{
                    posL = vector<int>(targetPos);
                    answer += "L";
                }
            }
        }
    }
    return answer;
}