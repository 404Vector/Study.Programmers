#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    string buf(a, '*');
    for(int i = b; i; i--) cout << buf<< endl;
    return 0;
}