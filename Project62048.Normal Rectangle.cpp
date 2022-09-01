using namespace std;

int GetGCD(const int &a, const int &b){ return b ? GetGCD(b, a%b) : a; }
int GetLoss(const int &dw, const int &dh){ return dw+dh-1;}
long long solution(int w,int h) {
    int gcd = GetGCD(w,h);
    int dw = (w/gcd);
    int dh = (h/gcd);
    int loss = GetLoss(dw,dh);
    long long unitArea = loss;
    return ((long long)w)*h - unitArea * gcd;
}