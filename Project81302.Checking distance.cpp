#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool IsX(const vector<string> &place, int row, int col, char x){
    if(row <0 || row > 4 || col < 0 || col > 4) return false;
    return place[row][col] == x;
}
int Check(const vector<string> &p){
    for(int r = 0; r < 5; r++){
        for(int c = 0; c < 5; c++){
            if(IsX(p,r,c,'P')){
                if(IsX(p,r+1,c,'P')||IsX(p,r,c+1,'P')) return 0;
                if(IsX(p,r+1,c,'O') && IsX(p,r+2,c,'P')) return 0;
                if(IsX(p,r,c+1,'O') && IsX(p,r,c+2,'P')) return 0;
                if(IsX(p,r,c+1,'O') && IsX(p,r+1,c+1,'P')) return 0;
                if(IsX(p,r+1,c,'O') && IsX(p,r+1,c+1,'P')) return 0;
                if(IsX(p,r,c+1,'O') && IsX(p,r-1,c+1,'P')) return 0;
                if(IsX(p,r-1,c,'O') && IsX(p,r-1,c+1,'P')) return 0;
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto &place : places) answer.push_back(Check(place));
    return answer;
}