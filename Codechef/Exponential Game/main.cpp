#include <bits/stdc++.h>

using namespace std;
#define MAX 1000000
int moves[] = {1 , 4 , 27, 256, 3125, 46656};
int grundy[MAX + 1];
int calcGrundy(int n) {
    if(n == 0) return 0;
    if(grundy[n] != - 1) return grundy[n];
    unordered_set<int> S;
    for(int i = 0; i < 6; ++i) {
        if(n - moves[i] >= 0) {
            S.insert(calcGrundy(n - moves[i]));
        }
    }
    int ans = 0;
    while(S.find(ans) != S.end()) ans++;
    return grundy[n] = ans;
}

int main() {
    int T, N;
    memset(grundy, -1, sizeof grundy);
    scanf("%d", &T);
    int elem;
    for(int i = 0; i < T; ++i) {
        scanf("%d", &N);
        int XOR = 0;
        for(int j = 0; j < N; ++j) {
            scanf("%d", &elem);
            XOR ^= calcGrundy(elem);
        }
        if(XOR) puts("Little Chef");
        else puts("Head Chef");
    }
    return 0;
}
