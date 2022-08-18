#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const string TEMPLATE = "AEIOU";
void MakeWords(const string &refWord, vector<string>&subWord, string word, int depth){
    if(depth > 5) return;
    subWord.push_back(word);
    for(int i = 0; i<refWord.size(); i++){
        MakeWords(refWord, subWord, word + refWord[i], depth+1);
    }
}
int solution(string word) {
    vector<string> subWord;
    map<string, int> wordIdxDic;
    for(int i = 0; i < TEMPLATE.size(); i++){
        string s({TEMPLATE[i]});
        MakeWords(TEMPLATE, subWord, s, 1);
    }
    for(int i = 0; i < subWord.size(); i++){
        wordIdxDic[subWord[i]] = i+1;
    }
    return wordIdxDic[word];
}