#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <map>

using namespace std;

struct User {
public:
    string id;
    string name;
};

vector<string> SplitRecord(string& record) {
    istringstream ss(record);
    vector<string> result;
    string temp;
    while (getline(ss, temp, ' ')) {
        result.push_back(temp);
    }
    return result;
}

map<string, User> GetUserInfos(vector<string>& record) {
    map<string, User> result;
    for (string r : record) {
        vector<string> tokens = SplitRecord(r);
        if (tokens[0][0] == 'E')
        {
            User u;
            u.id = tokens[1];
            u.name = tokens[2];
            if (result.count(tokens[1]) == 0)
                result.insert(pair<string, User>(tokens[1], u));
            else
                result[tokens[1]].name = tokens[2];
        }
        else if (tokens[0][0] == 'C')
        {
            result[tokens[1]].name = tokens[2];
        }
    }
    return result;
}

vector<string> RenderRecord(vector<string>& record, map<string, User>& users) {
    vector<string> result;
    for (string r : record) {
        vector<string> tokens = SplitRecord(r);
        if (tokens[0][0] == 'E')
            result.push_back(users[tokens[1]].name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        else if (tokens[0][0] == 'L')
            result.push_back(users[tokens[1]].name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        else continue;
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> logs = SplitRecord(record[0]);
    map<string, User> users = GetUserInfos(record);
    answer = RenderRecord(record, users);
    return answer;
}