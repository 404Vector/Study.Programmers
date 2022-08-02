#include <string>
#include <vector>

using namespace std;

#define NUM_COUNT 45
#define NUM_START 1 
#define NUM_SIZE 6

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int knownScore = 0;
    int unknownScore = 0;
    int high;
    int low;
    int sVec[NUM_COUNT] = { 0, };
    int tVec[NUM_COUNT] = { 0, };
    for (auto& i : lottos) {
        if (i > 0) sVec[i - NUM_START] = i;
        else unknownScore++;
    }
    for (auto& i : win_nums) if (i > 0) tVec[i - NUM_START] = i;
    for (auto& i : sVec) if (sVec[i - 1] > 0 && tVec[i - 1] > 0) knownScore++;
    high = NUM_SIZE - knownScore - unknownScore + 1;
    low = knownScore > 0 ? NUM_SIZE - knownScore + 1 : NUM_SIZE;
    answer.push_back(high > NUM_SIZE ? NUM_SIZE : high);
    answer.push_back(low > NUM_SIZE ? NUM_SIZE : low);
    return answer;
}