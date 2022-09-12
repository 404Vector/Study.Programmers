#include <string>
#include <vector>
#include <iostream>
using namespace std;
int Count(const string s, const char target){
    int result = 0;
    for(auto &c:s) if(c==target) result++;
    return result;
}
string ToBinStr(int b){
    string result = "";
    while(b){
        result = to_string(b%2) + result;
        b/=2;
    }
    return result;
}
vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s != "1"){
        int c = Count(s,'1');
        answer[0]++;
        answer[1]+=(s.size()-c);
        s = ToBinStr(c);
    }
    return answer;
}