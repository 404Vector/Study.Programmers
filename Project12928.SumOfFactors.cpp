#include <math.h>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n < 2) return n;
    for(int i = 1; i != n+1; i++){
        if(n%i != 0) continue;
        answer += i;
    }
    return answer;
}