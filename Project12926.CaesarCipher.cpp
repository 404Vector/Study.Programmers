#include <string>
#include <vector>

using namespace std;
void Decording(char &c, int n){
    if(c >= 'a' && c <= 'z'){
        c = (c-'a' + n)%('z'-'a'+1) +'a';
    }
    else if(c >= 'A' && c<= 'Z'){
        c = (c-'A' + n)%('Z'-'A'+1) +'A';
    }
    else{return;}
}
string solution(string s, int n) {
    for(auto &c : s) Decording(c, n);
    return s;
}