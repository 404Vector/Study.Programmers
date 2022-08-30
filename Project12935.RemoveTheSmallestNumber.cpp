#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1) return vector<int>(1,-1);
    vector<int> answer;
    int m = arr[0];
    for(int &a : arr) m = a > m ? m : a;
    for(int &a : arr) if(a != m) answer.push_back(a);
    return answer;
}