#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;
/*** typedef ***/
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
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
#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;

int binary_to_dec(string const& bin) {
    bitset<8> bit(string(bin.begin(), bin.end()));
    return bit.to_ulong();
}

template<class T> inline T gcd(T a,T b) {
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template<class T> inline T lcm(T a,T b) {
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
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
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
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

double LOG(i64 N,i64 B) {
    return (log10l(N))/(log10l(B));
}
string itoa(long long a) {
    if(a==0) return "0";
    string ret;
    for(long long i=a; i>0; i=i/10) ret.push_back((i%10)+48);
    reverse(ret.begin(),ret.end());
    return ret;
}

vector< string > token( string a, string b ) {
    const char *q = a.c_str();
    while( count( b.begin(), b.end(), *q ) ) q++;
    vector< string >
    oot;
    while( *q ) {
        const char *e = q;
        while( *e && !count( b.begin(), b.end(),
                             *e ) ) e++;
        oot.push_back( string( q, e ) );
        q = e;
        while( count( b.begin(),
                      b.end(), *q ) ) q++;
    }
    return oot;
}
int isvowel(char s) {
    s=tolower(s);
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1;
    return 0;
}
int isupper(char s) {
    if(s>='A' and s<='Z') return 1;
    return 0;
}
template<class T> struct Fraction {
    T a,b;
    Fraction(T a=0,T b=1);
    string toString();
};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b) {
    T d=gcd(a,b);
    a/=d;
    b/=d;
    if (b<0) a=-a,b=-b;
    this->a=a;
    this->b=b;
}
template<class T> string Fraction<T>::toString() {
    ostringstream sout;
    sout<<a<<"/"<<b;
    return sout.str();
}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q) {
    return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);
}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q) {
    return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);
}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q) {
    return Fraction<T>(p.a*q.a,p.b*q.b);
}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q) {
    return Fraction<T>(p.a*q.b,p.b*q.a);
}
//bool operator < ( const node& p ) const {      return dist > p.dist;   }
/** Bitamsk **/
int SET(int N,int pos) {
    return N=N | (1<<pos);
}
int RESET(int N,int pos) {
    return N= N & ~(1<<pos);
}
int check(int N,int pos) {
    return (N & (1<<pos));
}
int toggle(int N,int pos) {
    if(check(N,pos))return N=RESET(N,pos);
    return N=SET(N,pos);
}
void PRINTBIT(int N) {
    printf("(");
    for(int i=6; i>=1; i--)  {
        bool x=check(N,i);
        cout<<x;
    }
    puts(")");
}

const i64 INFFF=1e16;

/** Main Code **/

#define NTeam 70
#define NTable 50
#define Max 200

struct team {
    int id, member_no;
    team() {}; // empty constructor to satisfy bokachoda compiler
    team(int a, int b) {id = a; member_no = b;}
    bool operator < (const team& a) const {
        return member_no < a.member_no;
    }
};

struct table {
    int id, capacity;
    table() {};
    table(int a, int b) {id = a; capacity = b;}
    bool operator < (const table& a) const {
        return capacity > a.capacity;
    }
}t[NTable + 10];

priority_queue <team> q;
map < int, map <int ,int> > track;
int m, n;

bool isPossible() {
    int table_remain = n, member;
    team top;
    table t_obj;
    while(!q.empty()) {
        top = q.top(), q.pop();
        member = top.member_no;
        if(member > table_remain) return false;
        rep(i, member) {
            t_obj = t[i];
            t_obj.capacity -= 1;
            track[top.id][i] = t_obj.id;
            t[i] = t_obj; // restore
            if(!t_obj.capacity) table_remain -= 1;
        }
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        READ("input.txt");
    #endif
    int team_member, capacity, temp[NTeam + 10];
    bool result;
    while(SD2(m, n) && n && m) {
        q = priority_queue <team> ();
        rep(i, m) SDi(team_member), temp[i] = team_member, q.push(team(i, team_member));
        rep(i, n) SDi(capacity), t[i] = table(i, capacity);
        sort(t, t + n);

        result = isPossible();
        println(result);
        if(result) {
            rep(i, m) {
                int arr[Max];
                rep(j, temp[i]) arr[j] = track[i][j] + 1;
                sort(arr, arr + temp[i]);
                rep(j, temp[i]) pf("%d ", arr[j]);
                pf("\n");
            }
        }
    }
    return 0;
}
