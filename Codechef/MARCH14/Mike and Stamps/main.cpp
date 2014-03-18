/****************************************************
***   Problem       : Mike and Stamps
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

const i64 INFFF = 1e16;

/** Implementation **/
#define M 20
#define Max 20000

int N, m, maxM;
bool flag[M + 1][Max + 1];
bool exclusive[M + 1][M + 1];

int dp[(1 << M) + 1];

bool isOkay(int mask, int i) {
    if(mask & (1 << i)) return false;
    for(int pos = 0, value = 1; pos < m;) {
        if(value & mask) {
            if(exclusive[i][pos])
                return false;
        }
        ++pos;
        value = (1 << pos);
    }
    return true;
}

int solve(int i, int mask) {
    if(i == m) return 0;
    if(mask == maxM) return 0;
    if(dp[mask] != -1) return dp[mask];
    int count1 = 0, count2 = 0;

    if(isOkay(mask, i))
        count1 = 1 + solve(i + 1, mask | (1 << i));

    count2 = solve(i + 1, mask);

    return dp[mask] = max(count1, count2);
}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int k, value;
    SD2(N, m);
    maxM = (1 << m) - 1;
    rep(i, m) {
        SDi(k);
        rep(j, k) {
            SDi(value);
            flag[i][value] = true;
        }
    }
    rep(i, m) {
        FOR(j, i + 1, m - 1) {
            FOR(k, 1, N) {
                if(flag[i][k] and flag[j][k]) {
                    exclusive[i][j] = exclusive[j][i] = true;
                }
            }
        }
    }
    mem(dp, -1);
    int ans = solve(0, 0);
    println(ans);
    return 0;
}
