#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
vector<vector<string>> Split(const string &s){
    vector<string> arrays;
    for(int i = 1; i < s.size()-1; i++){
        auto c = s[i];
        if(c == '{') {arrays.push_back("");}
        else if(c == '}'){ i++; }
        else{ arrays[arrays.size()-1] += c; }  
    }
    vector<vector<string>> result;
    for(auto&a : arrays){
        vector<string> n(1,"");
        for(char &c:a){
            if(c == ',') {n.push_back("");}
            else{n[n.size()-1] += c;}
        }
        result.push_back(n);
    }
    return result;
}
bool Comp(const vector<string> &a,const vector<string> &b){
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    map<string,int> wordCount;
    vector<vector<string>> splitedStr = Split(s);
    sort(splitedStr.begin(),splitedStr.end(),Comp);
    for(auto&v : splitedStr){
        for(auto&s : v) {
            if(wordCount[s]) continue;
            answer.push_back(stoi(s));
            wordCount[s]++;
        }
    }
    return answer;
}