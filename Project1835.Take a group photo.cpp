#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool IsMatch(const string &pos,const string &condition){
    auto it1 = find(pos.begin(), pos.end(), condition[0]);
    auto it2 = find(pos.begin(), pos.end(), condition[2]);
    int delta = abs(it1 - it2)-1;
    switch(condition[3]){
        case '=':
            if(delta == condition[4]-'0'){return true;}
            break;
        case '>':
            if(delta > condition[4]-'0'){return true;}
            break;
        case '<':
            if(delta < condition[4]-'0'){return true;}
            break;
        default:
            break;
    }
    return false;
}
int solution(int n, vector<string> data) {
    int answer = 0;
    string pos("ACFJMNRT");
    do{
        int score = 0;
        for(auto &s : data){
            if(!IsMatch(pos, s)){break;}
            score++;
        }
        if(score == data.size()){answer++;}
    }while(next_permutation(pos.begin(), pos.end()));
    return answer;
}