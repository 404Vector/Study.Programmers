#include <math.h>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> pn(n+1,true); pn[0] = false; pn[1] = false;
    for(int i = 2; i != n+1; i++){
        if(!pn[i]) continue;
        answer++;
        for(int j = 2; j <= n/i; j++) pn[i*j] = false;
    }
    return answer;
}