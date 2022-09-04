#include <string>
#include <vector>
#include <iostream>
using namespace std;
const string opCase[]={"+-*","+*-","-+*","-*+","*+-","*-+"};
bool IsOperator(const char &c) {return c == '+' || c == '-' || c == '*';}
void Processing(vector<string> &exps, const char &op){
    for(int i = 0; i < exps.size(); i++){
        char o = exps[i].back();
        if(o != op) continue;
        long long a = stoll(exps[i-1]);
        long long b = stoll(exps[i+1]);
        a = o == '+' ? a+b : o == '-' ? a-b : a*b;
        exps.erase(exps.begin()+i,exps.begin()+i+2);
        exps[-1 + i--] = to_string(a);
    }
}
long long solution(string expression) {
    long long answer = 0;
    vector<string> exps(1,"");
    for(auto&c : expression){
        if(IsOperator(c)) exps.push_back(string(1,c));
        else if(IsOperator(exps.back()[0])) exps.push_back(string(1,c));
        else exps[exps.size()-1] += c;
    }
    for(auto &ops : opCase){
        vector<string> tempExps(exps);
        for(auto &op : ops) Processing(tempExps,op);
        answer = max(answer, abs(stoll(tempExps[0])));
    }
    return answer;
}