#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

vector<string> GetPermutation(string &data, const int &r){
    vector<string> result;
    do{
        string subStr(data.begin(), data.begin()+r);
        result.push_back(subStr);
        reverse(data.begin()+r, data.end());
    }while(next_permutation(data.begin(),data.end()));
    return result;
}
bool IsPrimeNumber(const int &number){
    if(number == 2) return true;
    for(int i = 2; i < floor(sqrt(number))+1; i++){
        //cout<< " - " << i << " v:" << number%i << endl;
        if(number%i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    map<int,int> list;
    for(int i = 1; i < numbers.size()+1; i++){
        auto p = GetPermutation(numbers, i);
        for(string s : p) {
            list[stoi(s)] = 0;
        }
    }
    for(auto pair : list){
        int value = pair.first;
        if(value<2) continue;
        //cout<<value<<endl;
        if(IsPrimeNumber(value)) answer++;
    }
    return answer;
}