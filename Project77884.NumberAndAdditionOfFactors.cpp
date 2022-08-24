#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int CountDivisor(const int & n){
    int result = 0;
    for(int i = 1; i <= n; i++) if(n%i == 0) result++;
    return result;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i != right+1; i++){
        answer = CountDivisor(i)%2 == 0 ? answer + i : answer - i;
    }
    return answer;
}