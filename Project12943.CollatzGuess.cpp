#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while(num != 1){
        if(answer > 450) return -1;
        num = num%2 ? num*3 + 1 : num/2;
        answer++;
    }
    return answer;
}