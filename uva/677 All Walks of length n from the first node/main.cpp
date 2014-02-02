#include<cstdio>

using namespace std;

#define Max 50

int m, n, num_paths;
int adj[Max][Max], path[Max];
bool visited[Max];

/* modified dfs which is able to backtrack */
void dfs(int node, int v) {
    path[v] = node;

    if(v == n) {
        ++num_paths;
        printf("(");
        for(int i = 0; i < v + 1; i++) {
            printf("%d", path[i] + 1);
            if(i < v) printf(",");
        }
        printf(")\n");
        return;
    }

    for(int i = 0; i < m; i++) {
        if(adj[node][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(i, v + 1);
            visited[i] = false;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (true) {
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++)
                scanf("%d", &adj[i][j]);
            visited[i] = false;
        }
        num_paths = 0;
        visited[0] = true;
        dfs(0, 0);
        if(num_paths == 0)
            printf("no walk of length %d\n", n);

        if(scanf("%d", &m) == -1)
            break;
        else printf("\n");
    }
}
