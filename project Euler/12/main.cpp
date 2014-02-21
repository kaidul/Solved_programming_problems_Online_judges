#include <bits/stdc++.h>

#define Max 13000

using namespace std;

int status[(Max / 32) + 2];
vector <int> primeList;
map <int, int> primeFactor;

bool Check(int N, int pos) {
    return (bool)( N & (1 << pos) );
}
int Set(int N, int pos) {
    return N = N | (1 << pos);
}

void RSieve(int N) {
    primeList.clear();
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2) {
        if( !Check( status[i >> 5], i & 31 ) ) {
            for( j = i*i; j <= N; j += (i << 1) ) {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }
    primeList.push_back(2);
    for(i=3; i < N; i += 2)
        if( !Check( status[i >> 5], i & 31 ) )
            primeList.push_back(i);
}

int d(int n) {
    primeFactor.clear();
    for(int i = 0; i < primeList.size(); ++i) {
        int p = primeList[i];
        if(p > n) break;
        while(n % p == 0) {
            n /= p;
            primeFactor[p]++;
        }
    }
    int result = 1;
    for(int i = 0; i < primeFactor.size(); ++i) {
        int r = primeFactor[i];
        result *= (r + 1);
    }
    return result;
}

int main() {
    int divisors, x, dp[Max];
    memset(dp, -1, sizeof dp);
    RSieve(Max);
    for(int i= 500; ; i++) {
        if(i % 2 == 0) {
            if(dp[i / 2] == -1) dp[i / 2] = d(i / 2);
            if(dp[i + 1] == -1) dp[i + 1] = d(i + 1);
            divisors = dp[i / 2] * dp[i + 1];
        } else {
            if(dp[i] == -1) dp[i] = d(i);
            if(dp[(i + 1) / 2] == -1) dp[(i + 1) / 2] = d((i + 1) / 2);
            divisors = dp[i] * dp[(i + 1) / 2];
        }
        if(divisors > 500) {
            x = ( i * (i + 1) ) / 2;
            cout << x;
            break;
        }
    }
    return 0;
}
