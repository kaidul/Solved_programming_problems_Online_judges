#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define Max 100

/* program to check parity */

bool Check(int n, int pos) {
    return (bool)(n & (1 << pos));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int parity = 0;
        // maximum # of bits required to represent n = ceil ( log2( n ) )
        int bits = ceil( log(n) / log(2) );
        for(int i = 0; i <= bits; i++) {
            if (Check(n, i ))
                ++parity;
        }
        printf("The parity of ");
        bool flag = false;
        for( int i = bits; i >= 0; i-- ) {
            bool bit = Check(n, i);
            if (flag)
                printf("%d", bit);
            if(!flag && bit) {
                printf("%d", bit);
                flag = true;
            }
        }
        printf(" is %d (mod 2).\n", parity);
    }
    return 0;
}
