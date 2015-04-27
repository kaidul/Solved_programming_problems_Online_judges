#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
/** function **/
#define SDi(x) sf("%d",&x)
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define pf printf
#define sf scanf
#define pb push_back
#define READ(f) freopen(f, "r", stdin)

#define Max 1000000
#define Mod 1000000007

i64 status[(Max/32) + 10];
vector <i64> primeList;
map <i64, i64> primeFactor;

bool Check(i64 N, i64 pos) {
    return (bool)(N & (1<<pos));
}
int Set(i64 N, i64 pos) {
    return N=N | (1<<pos);
}

void RSieve(i64 N) {
    primeList.clear();
    i64 i, j, sqrtN;
    sqrtN = i64( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 ) {
        if( Check(status[i >> 5], i & 31) == 0) {
            for( j = i * i; j <= N; j += (i << 1) ) {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }
    primeList.pb(2);
    for(i = 3; i <= N; i += 2)
        if( !Check(status[i >> 5], i & 31))
            primeList.pb(i);
}

i64 d(int n, bool code) {
    if(code) {
        rep(i, primeList.size()) {
            int p = primeList[i];
            if(p > n) break;
            while(n % p == 0) {
                n = n / p;
                primeFactor[p] += 1;
            }
        }
    } else {
        rep(i, primeList.size()) {
            int p = primeList[i];
            if(p > n) break;
            while(n % p == 0) {
                n = n / p;
                primeFactor[p] -= 1;
            }
        }
    }
    i64 result = 1;
    rep(i, primeFactor.size()) {
        i64 r = primeFactor[i];
        result = result % Mod * (r + 1) % Mod;
    }
    return result;
}


int main() {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif // ONLINE_JUDGE
    int tcase, caseNo = 1;
    int factor, result, n;

    RSieve(Max);

    SDi(tcase);
    while(tcase--) {
        primeFactor.clear();
        result = 0;
        SDi(n);
        rep(i, n) {
            SDi(factor);
            result += d(abs(factor), (factor > 0)) % Mod;
        }
        pf("Case %d: %d\n", caseNo, result % Mod);
        caseNo++;
    }
    return 0;
}
