#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define RESET(t,value) memset((t), value, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define pii pair<double,double>
#define G struct node

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }


vector < int > pset;
void initSet(int _size){ pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

#define Max 124800
G{
    int u, v;
    double cost;
    bool operator < (const G& a) const {
        return cost < a.cost;
    }
}g[Max];

int s, p;
double D;

double kruskal(int a) {
    D = -1;
    int q = p - s; // number of posts without satellite
    REP( i, a ) {
      if(!isSameSet(g[i].u, g[i].v)) {
          if(g[i].cost > D) D = g[i].cost;
          unionSet(g[i].u, g[i].v);
          q--;
      }
      if(!q) break;
    }
    return D;
}

int main() {
//    READ("input.txt");
    int t;
    int x[550], y[550], cost, edge_no, k;
    scanf("%d", &t);
    while (t--) {
      	scanf("%d%d", &s, &p);
      	FOR( i, 1, p ) {
      	  scanf("%d %d",&x[i], &y[i]);
      	}
      	k = 0;
      	FOR( i, 1, p ) {
      	  FOR( j, i+1, p ) {
      	    g[k].u = i;
      	    g[k].v = j;
      	    g[k].cost = sqrt( pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2) );
      	    k++;
      	  }
      	}
      	edge_no = (p * (p-1)) / 2;
      	initSet(p + 10);
      	sort(g, g+edge_no);
      	printf("%.2lf\n",kruskal(edge_no));
    }

    return 0;
}
