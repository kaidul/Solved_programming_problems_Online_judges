/****************************************************
***   Problem       : The Indian Job
***   Author        : Kaidul Islam
***   E-mail        : ikaidul@yahoo.com
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
// greedy approach. WA in some case. Still don't know why :/
//#define Max 100
//
//int N, G;
//int arr[Max + 1];
//
//int main(void) {
//    int tcase, caseNo = 0;
//#ifndef ONLINE_JUDGE
////    READ("input.txt");
//#endif
//    SDi(tcase);
//    while(tcase--) {
//        SD2(N, G);
//        rep(i, N) SDi(arr[i]);
//        sort(arr, arr + N, greater<int>());
//        bool yes = true;
//        int Min, robber1 = 0, robber2 = 0;
//        for(int i = 0; i < N;) {
//            if(robber1 == 0) robber1 = arr[i++];
//            if(robber2 == 0 and i < N) robber2 = arr[i++];
//            Min = min(robber1, robber2);
//            if(Min <= G) {
//                robber1 -= Min;
//                robber2 -= Min;
//                G -= Min;
//            } else {
//                yes = false;
//                break;
//            }
//        }
//        if(yes and (robber1 or robber2)) {
//            int M = max(robber1, robber2);
//            if(G < M) yes = false;
//        }
//        if(yes) pf("YES\n");
//        else pf("NO\n");
//    }
//    return 0;
//}

#define MAX_N 110
#define MAX_W 10010

int n;
int dp[MAX_N+1][MAX_W+1];
int weight[MAX_N+1];
int cost[MAX_N+1];
int CAP;

int func(int i, int w) {
    if(i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int profit1 = 0, profit2 = 0;
    if(w + weight[i] <= CAP)
        profit1 = cost[i] + func(i + 1, w + weight[i]);

    profit2 = func(i + 1, w);
	dp[i][w] = max(profit1, profit2);
    return dp[i][w];
}

int main() {
//    freopen("in.txt","r",stdin);
    int tcase, G, sum = 0;
    SDi(tcase);
    bool notPossible;
    while(tcase--) {
        SD2(n, G);
        notPossible = false;
        sum = 0;
        rep(i, n) {
            SDi(weight[i]);
            cost[i] = weight[i];
            sum += weight[i];
            if(weight[i] > G) {
                notPossible = true;
            }
        }
        if(notPossible) {
            puts("NO");
            continue;
        }
        mem(dp, -1);
        CAP = G;
        int ret = func(0, 0);
        if(sum - ret <= G)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
