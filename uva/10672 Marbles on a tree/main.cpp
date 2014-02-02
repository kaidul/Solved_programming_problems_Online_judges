#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>

#define Max 10001

using namespace std;
vector < int > adj[Max];
int marbles[Max], parent[Max], total_move;
bool processed[Max];
bool color[Max];

void dfs(int u) {
    color[u] = true;
    if(processed[u])
        return;
    for( int i = 0; i < (int) adj[u].size(); i++ ) {
        int v = adj[u][i];
        if( !processed[v] && !color[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
    int move = marbles[u] - 1;
    marbles[u] = 1;
    marbles[parent[u]] += move;
    total_move += abs(move);
    processed[u] = true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N;
    int marble, outdeg, u, v;
    while( scanf("%d", &N) == 1 && N) {

        for( int i = 1; i <= N; i++ ) {
            scanf("%d %d %d", &u, &marble, &outdeg);
            marbles[u] = marble;

            for( int k = 0; k < outdeg; k++ ) {
                scanf("%d", &v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        total_move = 0;
        memset(processed, false, sizeof(processed));
        memset(color, false, sizeof(color));
        parent[1] = 1;
        dfs(1);
        printf("%d\n", total_move);
        for(int i = 1; i <= N; i++ )
            adj[i].clear();
    }
    return 0;
}
