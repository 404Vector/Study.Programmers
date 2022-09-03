#include <string>
#include <vector>
#include <iostream>
using namespace std;
string Fix(const string &s){
    if(s.empty()) return s;
    int m = 0;
    int sidx = 0;
    bool checker = true;
    do{
        m = s[sidx++] == '(' ? m+1 : m-1;
        if(m<0) checker = false;
    }while(m!=0);
    string u = s.substr(0, sidx);
    string v = Fix(s.substr(sidx, s.size()-sidx));
    if(!checker){
        for(auto &c : u) c = c=='(' ? ')' : '(';
        return '(' + v + ')' + u.substr(1, u.size()-2);
    }
    else {return u + v;}
}
string solution(string p) {
    return Fix(p);
}