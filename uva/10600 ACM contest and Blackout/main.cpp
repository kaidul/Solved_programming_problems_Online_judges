#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<utility>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<iterator>
#include <bitset>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define pii pair<double,double>
#define G struct node

vector < int > pset(1000);
void initSet(int _size) {
    pset.resize(_size);
    FOR(i,0,_size-1) pset[i]=i;
}
int findSet(int i) {
    return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));
}
void unionSet(int i,int j) {
    pset[findSet(i)]=findSet(j);
}
bool isSameSet(int i,int j) {
    return findSet(i)==findSet(j);
}

G {
    int u, v;
    double cost;
    bool operator <(const G& a) const{
        return cost < a.cost;
    }
} g[220];

int n, e;
vector< int > data;

int BMST2(int p) {
    initSet(n + 3);
    int mstlen = 0;
    int sum2 = 0;
    for(int i = 0; i < e; i++) {
        if(i == p)
            continue;
        else if(!isSameSet(g[i].u, g[i].v)) {
            mstlen++;
            sum2 += g[i].cost;
            unionSet(g[i].u, g[i].v);
        }
    }
    if(mstlen < n-1) return -1;
    return sum2;
}

int main() {
    READ("input.txt");
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d %d", &n, &e);
        REP(i, e) {
            int x, y, cost;
            scanf("%d %d %d", &x, &y, &cost);
            g[i].u = x, g[i].v = y, g[i].cost = cost;
        }

        initSet(n + 3);

        sort(g, g + e);

        int sum = 0;
        for(int i = 0; i < e; i++) {
            if(!isSameSet(g[i].u, g[i].v)) {
                data.pb(i), sum += g[i].cost;
                unionSet(g[i].u, g[i].v);
            }
        }

        if(e == 1) {
            printf("%d %d\n", sum, sum);
        } else {
            int in, best = INF, indx = 0;
            REP(i, data.size()) {
                indx = data[i], in = BMST2(indx);
                if(in < best) best = in;
            }
            printf("%d %d\n", sum, best);
        }
        data.clear();
    }
    return 0;
}
