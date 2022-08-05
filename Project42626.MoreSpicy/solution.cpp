#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int Dequeue(priority_queue<int, vector<int>, greater<int>>& q) {
    int r = q.top();
    q.pop();
    return r;
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> foods;
    for (int f : scoville) foods.push(f);
    while (foods.top() < K) {
        if (foods.top() < K && foods.size() == 1) return -1;
        else foods.push(Dequeue(foods) + Dequeue(foods) * 2);
        answer++;
    }
    return answer;
}