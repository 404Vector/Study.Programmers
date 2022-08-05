#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int bgLoad = 0;
    int index = 0;
    int progress = 0;
    int nTruck = 0;
    queue<int> bgQueue;
    for (int i = 0; i < bridge_length; i++) bgQueue.push(0);
    while (progress < truck_weights.size()) {
        int out = bgQueue.front();
        bgQueue.pop();
        if (out > 0) {
            bgLoad -= out;
            nTruck--;
            progress++;
        }
        int in = index < truck_weights.size() ? truck_weights[index] : 0;
        if (bgLoad + in > weight || nTruck == bridge_length) {
            in = 0;
        }
        else {
            bgLoad += in;
            index++;
            nTruck++;
        }
        bgQueue.push(in);
        answer++;
    }
    return answer;
}