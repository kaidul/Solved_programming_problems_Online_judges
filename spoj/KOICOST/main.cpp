#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAXN 100001
#define MAXM MAXN
#define MOD 1000000000

vector< pair<int, pair<int, int> > > edges;
int parent[MAXN];
long long setSize[MAXN];
long long cumSum[MAXM];

void initSet(int N) {
    for(int i = 1; i <= N; ++i) {
        parent[i] = i;
        setSize[i] = 1;
    }
}

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int N, M;
    int u, v, w;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    if(M > 0) cumSum[0] = edges[0].first;
    for(int i = 1; i < M; ++i) {
        cumSum[i] = edges[i].first + cumSum[i - 1];
    }
    initSet(N);
    long long result = 0LL;
    for(int i = M - 1; i >= 0; --i) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int setU = findSet(u);
        int setV = findSet(v);
        if(setU != setV) {
            long long cntU = setSize[setU], cntV = setSize[setV];
            result += (cntU * cntV) * cumSum[i];
            if(result > MOD) result %= MOD;
            parent[setU] = setV;
//            setSize[findSet(u)] = setSize[findSet(v)] = cntU + cntV;
            setSize[setV] = cntU + cntV;
        }
    }
    printf("%lld\n", result);
    return 0;
}
