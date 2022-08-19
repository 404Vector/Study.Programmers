#include <string>
#include <vector>
#include <unordered_set> 
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int DEPTH_MAX = 8;

int GetNValue(const int &n,const int &count){
    int result = 0;
    for(int i = 0; i < count; i++) result += n * (int)pow(10,i);
    return result;
}

int solution(int N, int number) {
    if(N == number) return 1;
    map<int,unordered_set<int>> plans;
    plans[1].insert(N);
    for(int depth = 2; depth <= DEPTH_MAX; depth++ ){
        plans[depth].insert(GetNValue(N,depth));
        for(int subDepth = 1; subDepth < depth; subDepth++){
            auto A = plans[subDepth];
            auto B = plans[depth-subDepth];
            for(auto a : A){
                for(auto b : B){
                    plans[depth].insert(a+b);
                    if(a-b > -1)
                       plans[depth].insert(a-b);
                    plans[depth].insert(a*b);
                    if(b>0)
                        plans[depth].insert(a/b);
                }
            }
            for(auto val : plans[depth]) if(val == number) return depth;
        }
        
    }
    return -1;
}