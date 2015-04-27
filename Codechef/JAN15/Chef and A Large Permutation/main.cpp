#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
typedef long long ll;

const int maxn = 100000 + 5;

int n;
ll a[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int i, j, k;
    ll sum = 0, sumN = 0;
    int m, ntest;

    scanf("%d", &ntest);
    for(int itest = 1; itest <= ntest; ++itest) {
        scanf("%d %d", &n, &m);

        sumN = 1LL * n * (n + 1) / 2;
        sum = 0;
        for(i = 0; i < m; ++i) {
            scanf("%lld", a + i);
//            sum += a[i];
        }

        sort(a, a + m);

        ll res = 0;
        sum = 0;
        for(i = 0; i < m; ++i) {
            ll x = a[i] - 1;
            x = x * (x + 1) / 2;
            x -= sum;

            if(x < a[i]) {
                res = a[i];
                break;
            }
            sum += a[i];
        }
        if(res == 0) res = sumN - sum + 1;
        if(res & 1)
            puts("Chef");
        else
            puts("Mom");
    }

    return 0;
}
/*
#include <cstdio>
#include <fstream>
#include <cstring>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define MAX 100001
#define MIN 101
bool dropped[MIN];
int N;
vector <int> missings;
int dp[MIN][MIN * MIN];

int solve(int i, int amount) {
    if(i > N) {
        if(amount == 0) return 1;
        return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];
    int ret1 = 0, ret2 = 0;
    if(!dropped[i]) {
        if(amount - i >= 0) ret1 = solve(i + 1, amount - i);
    }
    ret2 = solve(i + 1, amount);
    return dp[i][amount] = ret1 | ret2;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    int K, indx;
    while(T--) {
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &N, &K);
        for(int i = 0; i < K; ++i) {
            scanf("%d", &indx);
            dropped[indx] = true;
            missings.push_back(indx);
        }
        bool found = false;
        for(int i = 0; i < missings.size(); ++i) {
            int ret = solve(1, missings[i]);
            if(!ret) {
                if(missings[i] & 1) printf("Chef\n");
                else printf("Mom\n");
                found = true;
                break;
            }
        }
        if(!found) {
            for(int i = N + 1;; ++i) {
                int ret = solve(1, i);
                if(!ret) {
                    if(i & 1) printf("Chef\n");
                    else printf("Mom\n");
                    break;
                }
            }
        }
        missings.clear();
        memset(dropped, false, sizeof dropped);
    }
    return 0;
}
*/
