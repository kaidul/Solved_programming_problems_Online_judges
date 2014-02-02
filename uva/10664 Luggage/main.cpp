#include <cstdio>
#include <cstring>
#include <iostream>
#define mem(x,y) memset(x,y,sizeof(x))
#define SDi(x) sf("%d",&x)
#define pf printf
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)

int weight[21], totalWeight, N;
int cache[21][201];
bool visited[21][201];
int knapsack(int i, int w) {
    if(i == N + 1) {
        if(totalWeight - w == w)
            return 1;
        return 0;
    }
    if(visited[i][w] != false)
        return cache[i][w];

    int ret1 = 0, ret2 = 0;
    if(w + weight[i] <= (totalWeight / 2))
        ret1 = knapsack(i + 1, w + weight[i]);
    ret2 = knapsack(i + 1, w);
    visited[i][w] = true;
    return cache[i][w] = ret1 | ret2;
}

int main() {
    #ifndef ONLINE_JUDGE
        READ("input.txt");
    #endif
    int tcase, indx, value;
    char input[1000];
    SDi(tcase);
    getchar();
    while(tcase--) {
        mem(visited, false);
        gets(input);
        indx = value = totalWeight = 0;
        for(int i = 0; input[i]; i++) {
            if(input[i] != ' ') {
                value = value * 10 + (input[i] - '0');
            } else {
                weight[indx++] = value;
                totalWeight += value;
                value = 0;
            }
        }
        weight[indx] = value, totalWeight += value, N = indx;
        if(knapsack(0, 0) == 1) {
            pf("YES\n");
        } else pf("NO\n");
    }
    return 0;
}
