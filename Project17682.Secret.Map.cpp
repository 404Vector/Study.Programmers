#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i = 0; i < n; i++){
        int r = arr1[i]|arr2[i];
        for(int b = n-1; b >= 0; b--){
            answer[i] += (r>>b)&1 == 1 ? "#" : " ";
        }
    }
    return answer;
}