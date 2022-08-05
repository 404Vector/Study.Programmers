#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Work {
public:
    int id = -1;
    int progress = 0;
    int speed = 0;
    bool isDone = false;
    bool isPublished = false;
    bool Processing() {
        if (isDone) return isDone;
        progress += speed;
        isDone = progress >= 100;
        return isDone;
    }
    bool TryPublish(Work& prevWork) {
        if (prevWork.id != id)
            if (!prevWork.isPublished) return false;
        if (isPublished) return false;
        isPublished = isDone;
        return isPublished;
    }
    Work(int _id, int _progress, int _speed) {
        id = _id;
        progress = _progress;
        speed = _speed;
    }
};
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<Work> works;
    int size = progresses.size();
    for (int i = 0; i < size; i++) {
        works.push_back(Work(i, progresses[i], speeds[i]));
    }

    int nPublish = 0;
    while (nPublish < size) {
        int pScore = 0;
        for (int i = 0; i < works.size(); i++) {
            if (!works[i].Processing()) continue;
            Work prev = i == 0 ? works[i] : works[i - 1];
            if (works[i].TryPublish(prev)) pScore++;
        }
        if (pScore > 0) {
            answer.push_back(pScore);
            nPublish += pScore;
        }
    }
    return answer;
}