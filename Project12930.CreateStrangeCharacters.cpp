#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int i = 0;
    for(auto &c : s){
        if(c == ' ') {i=0; continue;}
        c = i % 2 == 0 ? toupper(c) : tolower(c);
        i++;
    }
    return s;
}