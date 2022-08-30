#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Word{
    public:
    string word;
    char sortTarget;
    Word(string w, int t){
        word = w;
        sortTarget = w[t];
    }
};
bool Comp(const Word& a, const Word& b){
    return a.sortTarget != b.sortTarget ? a.sortTarget < b.sortTarget : a.word < b.word;
}
vector<string> solution(vector<string> strings, int n) {
    vector<Word> words;
    vector<string> answer;
    for(auto& s : strings) words.push_back(Word(s,n));
    sort(words.begin(), words.end(), Comp);
    for(auto& w : words) answer.push_back(w.word);
    return answer;
}