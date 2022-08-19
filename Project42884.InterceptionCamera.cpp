#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool IsOverlabed(const vector<int> &r1, const vector<int> &r2){
    return (r1[0] <= r2[0] && r1[1] >= r2[0])||(r1[0] <= r2[1] && r1[1] >= r2[1]);
}
vector<int> GetOverlabRange(const vector<int> &r1, const vector<int> &r2){
    vector<int> result({max(r1[0],r2[0]),min(r1[1],r2[1])});
    return result;
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    vector<int> refRange = routes.back();
    while(!routes.empty()){
        vector<int> last = routes.back(); routes.pop_back();
        if(IsOverlabed(refRange, last) || IsOverlabed(last, refRange)){
            refRange = GetOverlabRange(refRange, last);
        }
        else{
            refRange = last;
            answer++;
        }
    }
    return answer;
}