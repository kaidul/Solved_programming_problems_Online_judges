#include <bits/stdc++.h>
using namespace std;

int const N = 101000;
int const M = 1001000;
int n;
struct edges {
    int u, next;
} e[M];
int p[N], deg[N], idx;
void addedge(int u, int v) {
    e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
    ++deg[v];
}
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}

char s[111][111];
char ans[111];
int cnt;
int st[111], top;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", s[i]);
    }
    init();
    for (int i = 0; i < n - 1; ++i) {
        int len = strlen(s[i]);
        int nLen = strlen(s[i + 1]);
        bool found = 0;
        for (int j = 0; j < len && j < nLen; ++j) {
            if (s[i][j] != s[i + 1][j]) {
                found = 1;
                addedge(s[i][j] - 'a', s[i + 1][j] - 'a');
                break;
            }
        }
        if (!found && len > nLen) {
            puts("Impossible");
            return 0;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (deg[i] == 0) {
            st[++top] = i;
            deg[i] = -1;
        }
    }
    while (top > 0) {
        int u = st[top--];
        ans[cnt++] = 'a' + u;
        for (int i = p[u]; ~i; i = e[i].next) {
            int v = e[i].u;
            --deg[v];
            if (deg[v] == 0) {
                deg[v] = -1;
                st[++top] = v;
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (deg[i] >= 0) {
            puts("Impossible");
            return 0;
        }
    }
    ans[cnt] = 0;
    puts(ans);
    return 0;
}
