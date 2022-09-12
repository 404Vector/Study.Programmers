#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

string solution(string s) {
    string buf = "";
    istringstream iss(s);
    int minV, maxV;
    bool initialized = false;
    while (getline(iss, buf, ' ')){
        int v = stoi(buf);
        if(!initialized){
            minV = maxV = v;
            initialized = true;
            continue;
        }
        minV = min(v,minV);
        maxV = max(v,maxV);
    }
    return to_string(minV) + " " + to_string(maxV);
}