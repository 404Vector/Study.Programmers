#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include<algorithm>

using namespace std;

struct User
{
public:
    string name;
    vector<bool> reportedUser;
    int GetReportedUserCount()
    {
        int r = 0;
        for (int i = 0; i < reportedUser.size(); i++)
        {
            if (reportedUser[i]) { r++; }
        }
        return r;
    }
};

void CreateUserList(vector<User>& users, vector<string>& ids)
{
    for (vector<string>::iterator itr = ids.begin(); itr != ids.end(); itr++)
    {
        User u;
        u.name = *itr;
        u.reportedUser = vector<bool>(ids.size(), false);
        users.push_back(u);
    }
}

void CreateIndexMap(vector<User>& users, map<string, int>& indexMap)
{
    for (int i = 0; i < users.size(); i++)
    {
        indexMap.insert(std::pair<string, int>(users[i].name, i));
    }
}

vector<string> SplitString(string& source, char& key)
{
    vector<string> result;
    stringstream ss(source);
    string word;
    while (getline(ss, word, key)) {
        result.push_back(word);
    }
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    char splitWord = ' ';
    vector<int> answer(id_list.size(), 0);
    vector<User> users;
    map<string, int> indexMap;

    CreateUserList(users, id_list);
    CreateIndexMap(users, indexMap);

    for (int i = 0; i < report.size(); i++)
    {
        vector<string> raw = SplitString(report[i], splitWord);
        string source = raw[0];
        string target = raw[1];
        int sourceIdx = indexMap[source];
        int targetIdx = indexMap[target];
        users[targetIdx].reportedUser[sourceIdx] = true;
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].GetReportedUserCount() < k) {
            continue;
        }
        for (int j = 0; j < users.size(); j++)
        {
            if (users[i].reportedUser[j]) {
                answer[j]++;
            }
        }
    }
    return answer;
}