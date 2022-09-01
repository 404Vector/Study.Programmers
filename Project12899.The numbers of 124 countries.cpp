#include <string>
#include <algorithm>
using namespace std;
const string letters = "124";
string solution(int n) {
    string answer = "";
    while(n--){
        answer += letters[(n)%3];
        n/=3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

