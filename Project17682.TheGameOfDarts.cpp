#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    vector<int> scores;
    int s = 0;
    for(char & c : dartResult){
        if(c == '*'){
            scores[scores.size()-1] *= 2;
            scores[scores.size()-2] *= 2;
        }
        else if(c == '#'){
            scores[scores.size()-1] *= -1;
        }
        else if(c == 'S'){
            scores.push_back(pow(s, 1));
            s = 0;
        }
        else if(c == 'D'){
            scores.push_back(pow(s, 2));
            s = 0;
        }
        else if(c == 'T'){
            scores.push_back(pow(s, 3));
            s = 0;
        }
        else{
            s = s*10 + (c-'0');
        }
    }
    return scores[0] + scores[1] + scores[2];
}