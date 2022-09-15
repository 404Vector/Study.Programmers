#include <string>
#include <vector>

using namespace std;
void ToDown(char& c){
    if(c>='A' && c<='Z') c -= ('A' - 'a');
}
void ToUp(char& c){
    if(c>='a' && c<='z') c += ('A' - 'a');
}
string solution(string s) {
    vector<int> upTargets(1,0);
    for(int i = 0; i != s.size(); i++){
        ToDown(s[i]);
        if(s[i] == ' ') upTargets.push_back(i+1);
    }
    for(auto&idx : upTargets) ToUp(s[idx]);
    return s;
}