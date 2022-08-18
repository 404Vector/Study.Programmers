#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n);
    for(int l : lost) student[l-1] -= 1;
    for(int r : reserve) student[r-1] += 1;
    for(int i = 0; i < student.size(); i++) {
        if(student[i] > -1) {
            answer++;
            continue;
        }
        if(student[i] == -1){
            if(i != 0){
                if(student[i-1] == 1){
                    student[i-1] = student[i] = 0;
                    answer++;
                    continue;
                }
            }
            if(i != student.size()-1){
                if(student[i+1] == 1){
                    student[i+1] = student[i] = 0;
                    answer++;
                    continue;
                }
            }
        }
    }
    cout<<endl;
    return answer;
}