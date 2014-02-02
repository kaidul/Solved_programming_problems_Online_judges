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
int binToDec(char* s) {
    int n = 0;
    for(int i=0; s[i]!='\0'; i++) {
        n = n*2 + s[i]-'0';
    }
    return n;
}
/** Disjoint Set **/
vector < int > pset(100);
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

#define Max 12
int result;

map <int, int> m;
int var;

int pebbleSolitaire(int n) {
    if ( m [n] )
        return m [n];
    int backup = n;

    for ( int i = 0; i < Max - 1; i++ ) {
        if(check(n, i) && check(n, i + 1)) {
            if(i + 2 < Max && !check(n, i + 2)) {
                n = SET(n, i + 2);
                n = RESET(n, i);
                n = RESET(n, i + 1);
                m[n] = pebbleSolitaire(n);
                n = backup;
            }
            if(i - 1 >= 0 && !check(n, i - 1)) {
                n = SET(n, i - 1);
                n = RESET(n, i);
                n = RESET(n, i + 1);
                m[n] = pebbleSolitaire(n);
                n = backup;
            }
        }
    }

    int parity = 0;

    for ( int i = 0; i < Max; i++ ) {
        if (check(n, i)) parity++;
    }

    if ( parity < result )
        result = parity;

    return result;
}

int main () {
    READ("in.txt");
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        string input;
        cin >> input;
        var = 0;
        for ( int i = 0; i < Max; i++ ) {
            if (input.at(i) == 'o') var = SET(var, i);
        }

        result = INF;

        printf ("%d\n", pebbleSolitaire(var));
    }

    return 0;
}


/*

map <string, int> m;
string s;

int pebbleSolitaire(string s) {
    if ( m [s] )
        return m [s];
    string t = s;

    for ( int i = 0; i < Max - 1; i++ ) {
        if ( s.at (i) == 'o' && s.at (i + 1) == 'o' ) {
            if ( i + 2 < Max && s.at (i + 2) == '-' ) {
                s.at (i + 2) = 'o';
                s.at (i) = s.at (i + 1) = '-';
                m [s] = pebbleSolitaire(s);
                s = t;
            }
            if ( i - 1 >= 0 && s.at (i - 1) == '-' ) {
                s.at (i - 1) = 'o';
                s.at (i) = s.at (i + 1) = '-';
                m [s] = pebbleSolitaire(s);
                s = t;
            }
        }
    }

    int c = 0;

    for ( int i = 0; i < Max; i++ ) {
        if ( s.at (i) == 'o' ) c++;
    }

    if ( c < result )
        result = c;

    return result;
}

int main () {
    READ("in.txt");
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        string input;
        cin >> input;

        result = INF;

        printf ("%d\n", pebbleSolitaire(input));
    }

    return 0;
}


queue <string> q;
map <string, bool> visited;

bool generateState (string s) {
    string t = s;
    bool haveChild = false;

    for ( int i = 0; i < Max - 1; i++ ) {
        if ( s.at (i) == 'o' && s.at (i + 1) == 'o' ) {
            if ( i + 2 < Max && s.at (i + 2) == '-' ) {
                s.at (i + 2) = 'o';
                s.at (i) = s.at (i + 1) = '-';
                if ( !visited [s] ) {
                    visited [s] = true;
                    q.push (s);
                }
                haveChild = true;
                s = t;
            }
            if ( i - 1 >= 0 && s.at (i - 1) == '-' ) {
                s.at (i - 1) = 'o';
                s.at (i) = s.at (i + 1) = '-';
                if ( !visited [s] ) {
                    visited [s] = true;
                    q.push (s);
                }
                haveChild = true;
                s = t;
            }
        }
    }

    return haveChild;

}

int countPebble (string p) {
    int c = 0;

    for ( size_t i = 0; i < p.size (); i++ ) {
        if ( p.at (i) == 'o' )
            c++;
    }

    return c;
}
int main () {
    READ("in.txt");
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        string input;
        cin >> input;

        result = INF;
        q.push (input);
        visited [input] = true;

        while ( !q.empty () ) {
            string pop = q.front ();
            q.pop ();

            if ( !generateState (pop) ) {
                int t = countPebble (pop);
                if ( t < result )
                    result = t;
            }
        }

        printf ("%d\n", result);

    }

    return 0;
}

void show(char a[]) {
    for ( int i = 0; i < Max; i++ ) {
        cout << a[i];
    }
    cout << "\n";
}

void pebbleSolitaire(char a []) {
    char backup[Max + 3];
    strcpy (backup, a);

    // check till 11 instead of 12 because we have to deal with i + 1
    for ( int i = 0; i < Max - 1; i++ ) {
        // where a cut would be possible
        if ( a [i] == 'o' && a [i + 1] == 'o' ) {
            // if it doesn't overflow the cavities, then right shift
            if ( i + 2 < Max && a [i + 2] == '-' ) {
                a [i + 2] = 'o';
                a [i] = a [i + 1] = '-';
                pebbleSolitaire(a);
                //cout << "1   ";
                //show(a);
                strcpy (a, backup);
                //show(a);
            }
            // if it doesn't underflow the cavities, then left shift
            if ( i - 1 >= 0 && a [i - 1] == '-' ) {
                a [i - 1] = 'o';
                a [i] = a [i + 1] = '-';
                pebbleSolitaire(a);
                //cout << "2   ";
                //show(a);
                strcpy (a, backup);
                //show(a);
            }
        }
    }
    // check the optimal in each result
    int c = 0;

    for ( int i = 0; i < Max; i++ ) {
        if ( a [i] == 'o' ) c++;
    }

    if ( c < result )
        result = c;
}

int main () {
    READ("in.txt");
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        char input [Max + 3];
        scanf ("%s", input);

        result = INF;
        pebbleSolitaire(input);

        printf ("%d\n", result);
    }

    return 0;
}
*/




