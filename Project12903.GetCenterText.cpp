#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.size();
    return string(s.begin()+(n%2==0 ? n/2-1 : n/2), s.begin()+(n%2==0 ? n/2+1 : n/2+1));
}