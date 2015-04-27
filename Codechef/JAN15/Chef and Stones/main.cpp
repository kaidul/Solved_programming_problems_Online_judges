#include <bits/stdc++.h>

using namespace std;

#define MAX5 100001
int A[MAX5], B[MAX5];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int T;
    int N, K;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < N; ++i) {
            scanf("%d", &B[i]);
        }
        long long ans = 0, stones;
        for(int i = 0; i < N; ++i) {
            stones = K / A[i];
            ans = max(ans, stones * B[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
