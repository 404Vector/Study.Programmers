#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    return "김서방은 " + to_string((find(begin(seoul), end(seoul), "Kim") - seoul.begin())) + "에 있다";
}