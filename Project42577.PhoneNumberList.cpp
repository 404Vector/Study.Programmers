#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsIncluded(string& source, string& target) {
    return source == target.substr(0, source.size());
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (IsIncluded(phone_book[i], phone_book[i + 1])) return false;
    }
    return true;
}