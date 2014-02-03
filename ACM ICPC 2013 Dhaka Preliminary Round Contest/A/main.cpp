#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int Set(int N, int pos){
    return N = N | (1 << pos);
}
int reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

#define Max 12
vector < int > adj[Max];
int N, M;
int co[Max], wl[Max];
int dp[Max][1 << (Max - 1)][1 << (Max - 1)];

int tsp(int u, int mask, int mask2) {
    if(dp[u][mask][mask2] != -1)
        return dp[u][mask][mask2];
    int ans = 0;
    for(int k = 0; k < (int)adj[u].size(); k++) {
        int v = adj[u][k];
        if(wl[v] <= 0)
            continue;
        bool x = Check(mask, v);
        bool y = Check(mask2, v);
        if(wl[v] == 2) {
            if( x and y ) {
                continue;
            } else if( x and !y ) {
                ans = max(ans, tsp(v, mask, Set(mask2,v)));
            } else {
                ans = max(ans, tsp(v, Set(mask, v), mask2) + co[v]);
            }
        } else {
            if( !x ) {
                ans  = max(ans, tsp(v, Set(mask, v), mask2) + co[v]);
            }

        }

    }
    return dp[u][mask][mask2] = ans;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int u, v;
    int mask, mask2;
    int tcase, caseNo = 0;
    scanf("%d", &tcase);
    while( tcase-- ) {
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++ )
            scanf("%d", &wl[i]);
        for(int i = 1; i <= N; i++ )
            scanf("%d", &co[i]);
        for(int i = 1; i <= M; i++ ) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ret = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= N; i++) {
            mask = mask2 = 0;
            if( wl[i] > 0) {
                ret = max(ret, tsp(i, Set(mask, i), mask2) + co[i]);
            }
        }
        printf("Case %d: %d\n", ++caseNo, ret);
        for(int i  = 0; i < Max; i++)
            adj[i].clear();
    }
    return 0;
}
