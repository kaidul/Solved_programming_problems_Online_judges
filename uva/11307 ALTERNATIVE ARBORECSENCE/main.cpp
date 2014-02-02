#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

/**
state:
    dp[i][j] - minimum color sum at node i colored color j
transition:
    dp[i][j] += min(dp[k][l]), for all k is i's child and for all l of 7 colors
and the target state is min(dp[k][i]), for any arbitrary node k as root (I assumed 0 here), and for all i of 8 colors
**/

#define Max 10005
// A tree needs more than 10000 nodes to use the 9th color ('Introduction to chromatic sums' - Kubicka, Schwenk (1989) )
#define required_Color 8
vector <int> adj[Max];
int N, par[Max], in[Max], dp[Max][20];
char input[Max * 2];

void dfs(int node) {
    for(int i = 0; i < (int) adj[node].size(); i++) {
        if(adj[node][i] != par[node]) {
            par[adj[node][i]] = node;
            dfs(adj[node][i]);
        }
    }
    for(int i = 1; i < required_Color; i++) {
        int ret = i;
        for(int j = 0; j < (int) adj[node].size(); j++) {
            if(adj[node][j] != par[node]) {
                int ans = INT_MAX;
                for(int k = 1; k < required_Color; k++)
                    if(dp[ adj[node][j] ][k] != INT_MAX && k != i)
                        ans = min(ans, dp[adj[node][j]][k] );
                if(ans != INT_MAX)
                    ret += ans;
            }
        }
        dp[node][i] = ret;
    }
}

int main() {
    freopen("input.txt","r",stdin);
    while(~scanf(" %d",&N) && N) {
        // reset data-structure
        for(int i = 0; i < N; i++) {
            adj[i].clear();
            in[i] = 0;
            par[i] = -1;
            for(int j = 0; j < 20; j++)
                dp[i][j] = INT_MAX;
        }
        // input
        gets(input);
        int j;
        for(int i = 0; i < N; i++) {
            gets(input);
            char *ptr = strtok(input, " :");
            sscanf(ptr, " %d", &i);
            while( (ptr = strtok(NULL, " :")) != NULL) {
                sscanf(ptr, " %d", &j);
                in[j]++;
                adj[i].push_back(j);
            }
        }
        // persuing root's index
        int root;
        for(int i = 0; i < N; i++) {
            // for considering 0 as root
            if(in[i] == 0) {
                root = i;
                break;
            }
        }
        par[root] = root;
        dfs(root);
        if(N == 1)
            printf("1\n");
        else {
            int ans = INT_MAX;
            // trying with different number of color to get the optimal result
            for(int j = 1; j < required_Color; j++)
                ans = min(ans, dp[root][j]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
