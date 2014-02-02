#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

static int WHITE = 0;
static int BLACK = 1;

bitset <110> colored;
int color[110];
vector< vector<int> > adj;
int tc, n, k, ans;
vector<int> result;

void solve(int u) {
    if (u == n) {
        int b = 0, w = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == BLACK)
                b++;
            else
                w++;
        }
        if (b > ans) {
            ans = b;
            result.clear();
            for (int i = 0; i < n; i++) {
                if (color[i] == BLACK)
                    result.push_back(i);
            }
        }
        return;
    }

    bool canBlack = true;

    //check whether any adjacent nodes are black in color or not
    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        if (colored[v] && color[v] == BLACK) {
            canBlack = false;
            break;
        }
    }

    colored.set(u); // visited
    if (canBlack) {
        color[u] = BLACK;
        solve(u + 1);
    }
    color[u] = WHITE;
    solve(u + 1);
    colored.reset(u); // virgin
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int u, v;

    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &k);

        adj.assign(n, vector<int> ()); // allocate n
        colored.reset();
        ans = -1;
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(0);

        printf("%d\n", ans);
        for (int i = 0; i < (int) result.size(); i++) {
            printf("%d", result[i] + 1);
            if (i < (int) result.size() - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
