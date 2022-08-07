#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
public:
    int requestTime;
    int processingTime;
    Job(int reqTime, int procTime) {
        requestTime = reqTime;
        processingTime = procTime;
    }
    bool operator < (const Job& j) const {
        return this->processingTime < j.processingTime;
    }
    bool operator > (const Job& j) const {
        return this->processingTime > j.processingTime;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int progressIdx = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<Job, vector<Job>, greater<Job>> pq;
    while ((progressIdx < jobs.size()) || (!pq.empty())) {
        if ((progressIdx < jobs.size()) && (jobs[progressIdx][0] <= time)) {
            pq.push(Job(jobs[progressIdx][0], jobs[progressIdx][1]));
            progressIdx++;
            continue;
        }
        if (pq.empty() && (progressIdx < jobs.size())) {
            time = jobs[progressIdx][0];
        }
        else if (!pq.empty()) {
            Job j = pq.top(); pq.pop();
            time += j.processingTime;
            answer += time - j.requestTime;
        }
    }
    return answer / jobs.size();
}