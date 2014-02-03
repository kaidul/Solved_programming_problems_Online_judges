#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    unsigned long long S, M;
    S = 1000000000;
    M = 4294967296;

    unsigned long long fact[35];
    fact[0] = 1;

    unsigned long long i, temp;

    for( i=1; i<35; i++) {
        temp = fact[i-1] * i;
        temp = temp % M;
        fact[i] = temp;
    }

    int caseNo, T;
    cin >> T;

    unsigned long long n;

    for( caseNo = 1; caseNo <= T; caseNo++) {
        cin >> n;

        if ( n < 35) temp = fact[n];
        else temp = 0;

        cout << "Case " << caseNo << ": " << temp << endl;
    }
    return 0;
}
