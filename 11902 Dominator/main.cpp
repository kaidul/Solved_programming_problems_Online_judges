#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>

using namespace std;

#define MAXN 101

vector<int> parent[MAXN];
int adjMatrix[MAXN][MAXN];
char result[MAXN][MAXN];
int N;

void dfs(int u) {
    for(int i = 0; i < N; ++i) {
        if(adjMatrix[u][i]) {
            parent[i].push_back(u);
            dfs(i);
        }
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int tcase, caseNo = 0;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            parent[i].clear();
            for(int j = 0; j < N; ++j) {
                result[i][j] = 'N';
            }
            result[i][i] = 'Y';
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", &adjMatrix[i][j]);
            }
        }
        dfs(0);
        for(int i = 0; i < N; ++i) {
            if(parent[i].size() == 1) {
                result[parent[i][0]][i] = 'Y';
            }
        }
        printf("Case %d:\n", ++caseNo);
        for(int i = 0; i < N; ++i) {
            printf("+");
            for(int j = 1; j < 2 * N; ++j) {
                printf("-");
            }
            printf("+\n");
            for(int j = 0; j < N; ++j) {
                printf("|");
                printf("%c", result[i][j]);
            }
            printf("|\n");
        }
        printf("+");
        for(int j = 1; j < 2 * N; ++j) {
            printf("-");
        }
        printf("+\n");
    }
    return 0;
}
