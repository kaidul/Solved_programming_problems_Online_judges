#include <iostream>
#include <stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
int e[50][50], v[50][50];
int N, E, a, b;

int dfs(int n) {
    int i, longest_road = 0;
    for (i = 0; i < N; i++)
        if (e[n][i] && !v[n][i]) {
            v[n][i] = v[i][n] = 1;
            longest_road = max(longest_road, dfs(i) + 1);
            v[n][i] = v[i][n] = 0;
        }
    return longest_road;
}

int main() {
    while (scanf("%d %d", &N, &E) != EOF and N and E) {
        memset(v, 0, sizeof v), memset(e, 0, sizeof e);
        int i, longest_road = 0;
        for (i = 0; i < E; i++) {
            scanf("%d %d", &a, &b);
            e[a][b] = e[b][a] = 1;
        }
        for (i = 0; i < N; i++)
            longest_road = max( longest_road, dfs(i) );
        printf("%d\n", longest_road);
    }
    return 0;
}
