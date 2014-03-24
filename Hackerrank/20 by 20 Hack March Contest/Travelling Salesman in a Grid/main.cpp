/****************************************************
***   Problem       : Travelling Salesman in a Grid
***   Author        : Kaidul Islam
***   E-mail        : ikaidul@yahoo.com
***   University    : KUET, Dept. of CSE
***   Blog          : http://kaidul.efireit.com
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;
/** function **/
#define SDi(x) sf("%d", &x)
#define SDl(x) sf("%lld", &x)
#define SDs(x) sf("%s", x)
#define SD2(x,y) sf("%d%d", &x, &y)
#define SD3(x,y,z) sf("%d%d%d", &x, &y, &z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const i64 INF64 = (i64)1E18;

template<class T> inline T gcd(T a,T b) {
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template<class T> inline T lcm(T a,T b) {
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a, -b);
    return a*(b/gcd(a,b));
}
template<class T> inline T sqr(T x) {
    return x*x;
}
template<class T> T power(T N,T P) {
    return (P==0)?  1: N*power(N,P-1);
}
template<class T> bool inside(T a,T b,T c) {
    return (b>=a && b<=c);
}
double _dist(double x1,double y1,double x2,double y2) {
    return sqrt(sqr(x1-x2)+sqr(y1-
                               y2));
}
int distsq(int x1,int y1,int x2,int y2) {
    return sqr(x1-x2)+sqr(y1-y2);
}
i64 toInt64(string s) {
    i64 r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}
double Log(i64 N, i64 B) {
    return (log10l(N)) / (log10l(B));
}
string itoa(long long a) {
    if(a==0) return "0";
    string ret;
    for(long long i=a; i>0; i=i/10)
        ret.push_back((i%10)+48);
    reverse(ret.begin(),ret.end());
    return ret;
}
vector< string > token( string a, string b ) {
    const char *q = a.c_str();
    while( count( b.begin(), b.end(), *q ) ) q++;
    vector< string > oot;
    while( *q ) {
        const char *e = q;
        while( *e && !count( b.begin(), b.end(), *e ) )
            e++;
        oot.push_back( string( q, e ) );
        q = e;
        while( count( b.begin(), b.end(), *q ) )
            q++;
    }
    return oot;
}

int isvowel(char s) {
    s=tolower(s);
    if(s=='a' or s=='e' or s=='i' or s=='o' or s=='u')
        return 1;
    return 0;
}
int isupper(char s) {
    if(s>='A' and s<='Z') return 1;
    return 0;
}
template<class T> struct Fraction {
    T a,b;
    Fraction(T a=0,T b=1);
    string
    toString();
};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b) {
    T d=gcd(a,b);
    a/=d;
    b/=d;
    if (b<0) a=-a, b=-b;
    this->a=a;
    this->b=b;
}
template<class T> string Fraction<T>::toString() {
    ostringstream
    sout;
    sout<<a<<"/"<<b;
    return sout.str();
}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q) {
    return
        Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);
}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q) {
    return
        Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);
}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q) {
    return
        Fraction<T>(p.a*q.a,p.b*q.b);
}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q) {
    return
        Fraction<T>(p.a*q.b,p.b*q.a);
}

/** BitMask **/
int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N,int pos) {
    return N = N & ~(1 << pos);
}
int Check(int N, int pos) {
    return (N & (1 << pos));
}
int toggle(int N, int pos) {
    if( Check(N, pos) )
        return N = Reset(N, pos);
    return N = Set(N, pos);
}

const i64 INFFF = 1e16;

#define CITY 200
#define adj 4
#define ENGAGED '1'
#define AVAILABLE '0'

map <int, map<string, bool> > visited;
map <int, map<string, int> > dp;
int weight [CITY] [CITY];
string target;
int origin, N;
int m, n;
int dir[adj];
bool possible = false;

int tspBitmask (int node, string mask) {
    if ( !mask.compare(target) ) {
        visited [node] [mask] = true;
        if(weight[node] [origin] != INF) possible = true;
        return dp [node] [mask] = weight[node] [origin];
    }

    if ( visited [node] [mask] )
        return dp [node] [mask];

    visited [node] [mask] = true;

    int ret, ans = INF, neighbour, cost;

    for(int i = 0; i < adj; ++i) {
        neighbour = node + dir[i];
        if(neighbour >= 0 and neighbour <= N) {
            cost = weight[node][neighbour];
            if(cost != INF) {
                if ( mask[N - neighbour] == AVAILABLE ) {
                    mask[N - neighbour] = ENGAGED;
                    ret = tspBitmask(neighbour, mask);
                    if(ret != INF) ans = min(ans, cost + ret);
                    mask[N - neighbour] = AVAILABLE;
                }
            }
        }
    }

    return dp [node] [mask] = ans;
}

int main (void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int in;
    SD2(m, n);
    dir[0] = -1;
    dir[1] = -n;
    dir[2] = 1;
    dir[3] = n;
    N = m * n;
    rep(i, N) rep(j, N) weight[i][j] = INF;
    int k = 0, x, y;
    rep(i, m) {
        rep(j, n - 1) {
            SDi(in);
            weight[k][k + 1] = weight[k + 1][k] = in;
            ++k;
        }
        ++k;
    }
    k = 0;
    rep(i, m - 1) {
        rep(j, n) {
            SDi(in);
            x = k, y = k + n;
            weight[k][k + n] = weight[k + n][k] = in;
            ++k;
        }
    }
    int ans;
    if((m == 1 and n == 2) or (n == 1 and m == 2)) {
        ans = weight[0][1] + weight[1][0];
        println(ans);
    } else if((m == 1 and n > 2) or (n == 1 and m > 2)) {
        pf("0\n");
    } else {
        string mask = "";
        target = "";
        rep(i, N) mask += AVAILABLE, target += ENGAGED;
        origin = 0;
        --N;
        mask[N] = ENGAGED;
        ans = tspBitmask(origin, mask);
        if(possible) println(ans);
        else pf("0\n");
    }
    return 0;
}
