#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define i64 long long
using namespace std;

#define Max 10001

i64 T[Max], Q[Max], M[Max];


int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; i++) {
            scanf("%lld", M + i);
            M[i] += M[i - 1];
        }

        memset(T, 0, sizeof(i64) * n);

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n - i; j++)
                Q[j] = M[j + i] - M[j] - min(T[j], T[j + 1]);

            swap(T, Q); // array swaping
        }
        printf("%lld\n", T[0]);
    }

}
