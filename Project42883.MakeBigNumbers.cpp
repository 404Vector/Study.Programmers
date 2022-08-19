#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
string GetSubStr(const string & number, const int & deleteIdx){
    string result(number);
    result.erase(result.begin()+deleteIdx);
    return result;
}
string solution(string number, int k) {
    string answer(number);
    for(int i = 0; i<k; i++){
        for(int j = 0; j < answer.size();j++){
            if(j == number.size()-1){
                answer = GetSubStr(answer, j);
                break;
            }
            else if(answer[j] < answer[j+1]){
                answer = GetSubStr(answer, j);
                break;
            }
            continue;
        }
    }
    return answer;
}