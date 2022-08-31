#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int digits = 0;
    int y = x;
    while(y){digits += y%10; y/=10;}
    return x%digits == 0;
}