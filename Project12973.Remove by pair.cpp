#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> cs;
    for(auto &c : s){
        if(cs.empty() || cs.top() != c) {cs.push(c);}
        else {cs.pop();}
    }
    return cs.empty() ? 1 : 0;
}