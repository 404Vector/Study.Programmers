#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<bool> check(s.size());
    for(int i = 0; i < s.size(); i++){
        if(check[i]) continue;
        check[i] = true;
        if(s[i] >= '0'&&s[i] <= '9') answer = answer * 10 + s[i] - '0';
        else{
            string sub = string(s.begin()+i, s.begin()+i+2);
            int n = 10;
            if(sub == "on"){ 
                n = 1; for(int j = 0; j < 3; j++) check[i+j] = true;
            }
            if(sub == "tw"){
                n = 2; for(int j = 0; j < 3; j++) check[i+j] = true;
            }
            if(sub == "th"){
                n = 3; for(int j = 0; j < 5; j++) check[i+j] = true;
            }
            if(sub == "fo"){ 
                n = 4; for(int j = 0; j < 4; j++) check[i+j] = true;
            }
            else if(sub == "fi"){ 
                n = 5; for(int j = 0; j < 4; j++) check[i+j] = true;
            }
            else if(sub == "si"){ 
                n = 6; for(int j = 0; j < 3; j++) check[i+j] = true;
            }
            else if(sub == "se"){ 
                n = 7; for(int j = 0; j < 5; j++) check[i+j] = true;
            }
            else if(sub == "ei"){ 
                n = 8; for(int j = 0; j < 5; j++) check[i+j] = true;
            }
            else if(sub == "ni"){ 
                n = 9; for(int j = 0; j < 4; j++) check[i+j] = true;
            }
            else if(sub == "ze"){ 
                n = 0; for(int j = 0; j < 4; j++) check[i+j] = true;
            }
            answer = answer * 10 + n;
        }
    }
    return answer;
}