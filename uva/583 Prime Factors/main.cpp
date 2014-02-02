#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define pb push_back
using namespace std;
typedef long long i64;

#define Max 6000

i64 status[( Max / 32 ) + 2];
vector <i64> primeList;
map <i64, i64> primeFactor;

bool Check(i64 N, i64 pos) {
    return(bool)( N & ( 1 << pos) );
}
void Set(i64 N, i64 pos) {
    N = N |(1 << pos);
}

void RSieve(i64 N) {
    primeList.clear();
    i64 i, j, sqrtN;
    sqrtN = i64( sqrt( N ));
    for( i = 3; i <= sqrtN; i += 2) {
        if( Check( status[i >> 5 ], i & 31 ) == 0) {
            for( j = i * i; j <= N; j += (i << 1)) {
                Set(status[j >> 5], j & 31);
            }
        }
    }
    primeList.pb(2);
    for(i = 3; i <= N; i += 2)
        if( Check(status[i >> 5], i & 31))
            primeList.pb(i);
}

int main() {
    int N = 46500;
    RSieve(N);
    cout << primeList.size();
    return 0;
}
