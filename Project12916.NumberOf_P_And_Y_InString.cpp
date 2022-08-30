#include <string>
#include <map>
using namespace std;

bool solution(string s)
{
    map<char,int> m;
    for(auto&c : s) m[c]++;
    return (m['p'] + m['P']) == (m['y'] + m['Y']);
}