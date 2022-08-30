#include <math.h>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long sn = sqrt(n);
    return (n != sn * sn) ? -1 : (sn+1)*(sn+1);
}