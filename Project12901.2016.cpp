#include <string>
using namespace std;
const int dayForMonth[] = {31,29,31,30,31,30,31,31,30,31,30,31};
const string day[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
string solution(int a, int b) {
    for(int i = 0; i < a-1; i++) {b += dayForMonth[i];}
    return day[(b-1)%7];
}