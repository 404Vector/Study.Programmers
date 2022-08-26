#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    unordered_set<int> setList;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            if(i==j) {continue;}
            setList.insert(numbers[i] + numbers[j]);
        }
    }
    answer = vector<int>(setList.begin(), setList.end());
    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}