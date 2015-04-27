#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

#define MAX 1000000
#define i64 long long

int primes[(MAX / 32) + 1];

bool isPrime(int n) {
    int sqrtN = int(sqrt(n));
    for(int i = 2; i <= sqrtN; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int sqrtN = int(sqrt(MAX));
    int j = 1;
    primes[j >> 5] |= (1 << (j & 31));
    for(int i = 3; i <= sqrtN; i += 2) {
        if( !(primes[i >> 5] & (1 << (i & 31))) ) {
            for(int j = i * i; j <= MAX; j += (i << 1)) {
                primes[j >> 5] |= (1 << (j & 31));
            }
        }
    }
    int tcase;
    int m, n;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d %d", &m, &n);
        int lower = max(1, m);
        int upper = min(MAX, n);
        if(lower <= upper) {
            if(lower <= 2) printf("2\n");
            lower = (lower & 1) ? lower : lower + 1;
            for(int i = lower; i <= upper; i += 2) {
                if(!(primes[i >> 5] & (1 << (i & 31)))) {
                    printf("%d\n", i);
                }
            }
        }
        for(int i = MAX + 1; i <= n; i += 2) {
            if(isPrime(i)) {
                printf("%d\n", i);
            }
        }
        if(tcase) printf("\n");
    }
    return 0;
}
