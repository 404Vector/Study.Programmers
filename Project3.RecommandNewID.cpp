#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    for (auto& c : new_id) c = ::tolower(c); // stage1

    string new_id_s2 = "";    // stage2
    for (auto& c : new_id)
        if (('0' <= c && '9' >= c) || ('a' <= c && 'z' >= c) || c == '-' || c == '_' || c == '.')
            new_id_s2.push_back(c);

    string new_id_s3 = ""; // stage3
    for (auto& c : new_id_s2)
        if (c == '.')
        {
            if (new_id_s3.back() != c) new_id_s3.push_back(c);
        }
        else
            new_id_s3.push_back(c);

    string new_id_s4 = ""; // stage 4
    new_id_s4 = new_id_s3[0] == '.' ? new_id_s3.substr(1) : new_id_s3;
    new_id_s4 = new_id_s4.back() == '.' ? new_id_s4.substr(0, new_id_s4.size() - 1) : new_id_s4;

    string new_id_s5; // stage 5
    new_id_s5 = new_id_s4.size() == 0 ? "a" : new_id_s4;

    string new_id_s6; // stage 6
    if (new_id_s5.size() > 15)
    {
        new_id_s6 = new_id_s5.substr(0, 15);
        if (new_id_s6.back() == '.')
            new_id_s6 = new_id_s6.substr(0, 14);
    }
    else
    {
        new_id_s6 = new_id_s5;
    }

    string new_id_s7; // stage 7
    new_id_s7 = new_id_s6;
    while (new_id_s7.size() < 3) {
        new_id_s7 += new_id_s6.back();
    }
    string answer = new_id_s7;
    return answer;
}