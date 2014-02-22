#include <bits/stdc++.h>

using namespace std;

#define MAX_N 505
#define MAX_W 505
int n;
int dp[MAX_N+1][MAX_W+1], memo[MAX_N+1][MAX_W+1];
int weight[MAX_N+1];
int cost[MAX_N+1];
int CAP;
pair<int, int> func(int i, int w) {
    if(i==n+1) return make_pair(0, 0);
    if(dp[i][w]!=-1) {
        return make_pair(dp[i][w], memo[i][w]);
    }
    int weight1 = 0, weight2 = 0, profit1=0,profit2=0;
    if(w+weight[i]<=CAP) {
        pair<int, int> ret = func(i+1,w+weight[i]);
        profit1= cost[i] + ret.first;
        weight1 = ret.second + weight[i];
    }

    pair<int, int> ret2 = func(i+1,w);
    profit2=ret2.first;
    weight2 = ret2.second;
    if(profit1 > profit2) {
        memo[i][w] = weight1;
        dp[i][w]=profit1;
    } else {
        memo[i][w] = weight2;
        dp[i][w]=profit2;
    }
    return make_pair(dp[i][w], memo[i][w]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif

    while(scanf("%d%d",&CAP,&n) == 2) {
        if(CAP == 0 and n == 0) break;
        memset(dp,-1,sizeof(dp));
        memset(memo,0,sizeof(memo));
        for(int i=1; i<=n; i++) {
            scanf("%d%d\n",&weight[i],&cost[i]);
        }
        pair<int, int> ans = func(1,0);
        printf("%d %d\n", ans.second, ans.first);
    }



}
