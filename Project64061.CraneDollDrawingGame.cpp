#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    for(auto &m : moves){
        int n = 0;
        for(int j = 0; j < board.size(); j++){
            if(board[j][m-1] == 0){continue;}
            n = board[j][m-1];
            board[j][m-1] = 0;
            break;
        }
        if(n == 0) {continue;}
        if(!basket.empty() && basket.back() == n){
            basket.pop_back();
            answer += 2;
            continue;
        }
        basket.push_back(n);
    }
    return answer;
}