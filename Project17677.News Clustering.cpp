#include <string>
#include <map>
#include <iostream>
using namespace std;
void DownCasting(string& s){
    for(auto &c : s) c = (c >= 'A' && c<='Z') ? c - ('A'-'a') : c;
}
void Mapping(string& s, map<string,int>& target){
    DownCasting(s);
    for(int i = 0; i != s.size()-1; i++){
        if(s[i]<'a' || s[i]>'z') continue;
        else if(s[i+1]<'a' || s[i+1]>'z') continue;
        else{target[s.substr(i,2)]++;}
    }
}
int solution(string str1, string str2) {
    double n = 0;
    double u = 0;
    map<string,int> map1;
    map<string,int> map2;
    Mapping(str1, map1);
    Mapping(str2, map2);
    for(auto& p : map1){
        n += min(p.second, map2[p.first]);
        u += min(p.second, map2[p.first]);
    }
    for(auto& p : map2) u += max(p.second, map1[p.first]);
    return u==n ? 65536 : (int)(65536 * n / (u-n));
}