#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <string>

using namespace std;

#define MAX 5005
int parent[MAX];
int setLength[MAX];
int C, R;
unordered_map <string, int> Hash;

void initSet() {
    for(int i = 1; i <= C; ++i) {
        parent[i] = i;
        setLength[i] = 1;
    }
    Hash = unordered_map<string, int> ();
}

int findSet(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if(x == y) return;

    if(setLength[y] > setLength[x]) swap(x, y);

    parent[y] = x;
    setLength[x] += setLength[y];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    while(scanf("%d %d", &C, &R)) {
        if(C == 0 and R == 0) break;
        initSet();
        string creature1, creature2;
        int cnt = 0;
        for(int i = 0; i < C; ++i) {
            cin >> creature1;
            Hash[creature1] = ++cnt;
        }
        for(int i = 0; i < R; ++i) {
            cin >> creature1 >> creature2;
            unionSet(Hash[creature1], Hash[creature2]);
        }
        int result = INT_MIN;
        for(int i = 1; i <= C; ++i) {
            result = max(result, setLength[i]);
        }
        printf("%d\n", result);
    }
    return 0;
}
