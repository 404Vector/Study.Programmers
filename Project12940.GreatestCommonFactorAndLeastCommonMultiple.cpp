#include <vector>
using namespace std;
int GetGCD(int a, int b){return b ? GetGCD(b, a%b) : a;}
vector<int> solution(int n, int m) {
    int k = GetGCD(n,m);
    return vector<int>({k,n*m/k});
}