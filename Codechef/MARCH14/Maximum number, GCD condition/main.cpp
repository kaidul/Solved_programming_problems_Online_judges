/****************************************************
***   Problem       : Maximum number, GCD condition
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

/** Implementation **/
/* TLE baal marka code
#define Max 100000
struct data {
    int value, freq;
    data() {}
    data(int a, int b) : value(a), freq(b) {}
    bool operator == (const data &other) const {
        return (value == other.value and freq == other.freq);
    }
};
vector <data> segment_tree;
int arr[Max + 1];
int G, N, M;
data dummy = data(-2, -2);
data minusOne = data(-1, -1);


void initSegmentTree() {
    int length = 2 * pow(2.0, floor(log((double) N ) / log(2.0)) + 1 );
    segment_tree.clear();
    data empty = data(0, 0);
    segment_tree.resize(length, empty);
}

void buildHelper(int node, int begin, int end ) {
    if (begin == end) {
        if(gcd(G, arr[begin]) > 1) {
            segment_tree[node] = data(arr[begin], 1);
        } else {
            segment_tree[node] = minusOne;
        }
        return;
    }
    int leftIndx = 2 * node, rightIndx = 2 * node + 1;

    buildHelper(leftIndx, begin, (begin + end) / 2);
    buildHelper(rightIndx, (begin + end) / 2 + 1, end);

    data lContent = segment_tree[leftIndx], rContent = segment_tree[rightIndx];
    int y, x;
    if(lContent == minusOne and rContent == minusOne) {
        segment_tree[node] = minusOne;
    } else if(lContent.value == rContent.value) {
        x = lContent.value;
        y = lContent.freq + rContent.freq;
        segment_tree[node] = data(x, y);
    } else {
        if(lContent.value > rContent.value) x = lContent.value, y = lContent.freq;
        else x = rContent.value, y = rContent.freq;
        segment_tree[node] = data(x, y);
    }
}

void buildSegmentTree() {
    buildHelper(1, 0, N - 1);
}

data queryHelper(int node, int begin, int end, int i, int j) {
    if (i > end or j < begin) return dummy;

    if (begin >= i and end <= j) return segment_tree[node];

    data pos1 = queryHelper(2 * node, begin, (begin + end) / 2, i, j);
    data pos2 = queryHelper(2 * node + 1, (begin + end) / 2 + 1, end, i, j);

    if(pos1 == dummy) return pos2;
    if(pos2 == dummy) return pos1;

    return (pos1.value >= pos2.value) ? pos1 : pos2;
}

data query(int lower, int upper) {
    return queryHelper(1, 0, N - 1, lower, upper);
}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif // ONLINE_JUDGE
    int x, y;
    data ans;
    SD2(N, M);
    rep(i, N) SDi(arr[i]);
    initSegmentTree();
    rep(i, M) {
        SDi(G);
        buildSegmentTree();
        SD2(x, y);
        --x, --y;
        ans = query(x, y);
        pf("%d %d\n", ans.value, ans.freq);
    }
    return 0;
}
*/

#define Max 100000
#define Iterator vector<pair<int, int> >::iterator

vector <int> indx[Max + 1];
vector < pair <int, int> > data[Max + 1];
vector <int> factors, vG[Max + 1], vGX[Max + 1], vGY[Max + 1], vFactors;
int N, M, G, X[Max + 1], Y[Max + 1];
int ans[Max + 1], segment_tree[4 * Max + 4];

void clearSegmentTree(int n) {
    int length = 2 * pow(2.0, floor(log((double) n ) / log(2.0)) + 1 );
    memset(segment_tree, 0, length);
}


int query(int node, int l, int r, int i, int j) {
    if(r < i or j < l)
        return -1;

    if(i <= l and r <= j)
        return segment_tree[node];

    int mid = (l + r) >> 1;
    int lContent = query((node << 1), l, mid, i, j);
    int rContent = query((node << 1) | 1, mid + 1, r, i, j);

    return max(lContent, rContent);
}

void buildSegmentTree(int node, int l, int r, int idx) {
    if(r == l) {
        segment_tree[node] = data[idx][r - 1].second;
        return;
    }
    int mid = (l + r) >> 1, leftIndx = (node << 1);
    int rightIndx = leftIndx | 1;

    buildSegmentTree(leftIndx, l, mid, idx);
    buildSegmentTree(rightIndx, mid + 1, r, idx);

    segment_tree[node] = max(segment_tree[leftIndx], segment_tree[rightIndx]);
}

Iterator Lower_bound(Iterator start, Iterator end, const int &val) {
    Iterator it;
    int step, count = distance(start, end);
    while (count > 0) {
        it = start;
        step = count / 2;
        advance(it, step);
        if ( (*it).first < val) {
            start = ++it;
            count -= step + 1;
        } else count = step;
    }
    return start;
}

Iterator Upper_bound(Iterator start, Iterator end, const int &val) {
    Iterator it;
    int step, count = distance(start, end);
    while (count > 0) {
        it = start;
        step = count / 2;
        advance(it, step);
        if (!(val < (*it).first) ) {
            start = ++it;
            count -= step + 1;
        } else count = step;
    }
    return start;
}


int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif // ONLINE_JUDGE
    int value, val, x, y;
    SD2(N, M);
    FOR(i, 1, N) {
        SDi(value);
        if(value <= 1)
            continue;
        indx[value].pb(i);
        val = value;
        for(int j = 2, n = sqrt(value); j <= n; ++j) {
            if(value % j == 0) {
                data[j].pb( make_pair(i, val) );
                while(value % j == 0) {
                    value /= j;
                }
            }
        }
        if(value > 1) data[value].pb( make_pair(i, val) );
    }

    vector<int>:: iterator low, up;
    Iterator Low, Up, it;

    for(int im = 0; im < M; ++im) {
        SDi(G);
        SD2(x, y);

        X[im] = x;
        Y[im] = y;
        ans[im] = -1;

        // calculating the prime factors of G
        for(int i = 2, n = sqrt(G); i <= n; ++i) {
            if(G % i == 0) {
                factors.push_back(i);
                while(G % i == 0) {
                    G /= i;
                }
            }
        }
        if(G > 1) factors.push_back(G);

        for(int i = 0, n = factors.size(); i < n; ++i) {
            if(data[ factors[i] ].size() == 0) continue;

            Low = Lower_bound(data[ factors[i] ].begin(), data[ factors[i] ].end(), x);
            Up = Upper_bound(data[ factors[i] ].begin(), data[ factors[i] ].end(), y);

            vFactors.push_back(factors[i]);
            vG[ factors[i] ].push_back(im);
            vGX[ factors[i] ].push_back(Low - data[ factors[i] ].begin());
            vGY[ factors[i] ].push_back(Up - 1 - data[ factors[i] ].begin());
        }
        factors.clear();
    }

    sort(all(vFactors));
    vFactors.erase( unique(all(vFactors)), vFactors.end());

    int k, n, im, ret;
    for(int i = 0; i < vFactors.size(); ++i) {
        k = vFactors[i];
        n = data[k].size();

        buildSegmentTree(1, 1, n, k);

        for(int j = 0; j < vG[k].size(); ++j) {
            im = vG[k][j];
            ret  = query(1, 1, n, vGX[k][j] + 1, vGY[k][j] + 1);
            ans[im] = max(ans[im], ret);
        }

        clearSegmentTree(n);
    }

    for(im = 0; im < M; ++im) {
        k = ans[im];
        if(k == -1) {
            pf("-1 -1\n");
        } else {
            low = lower_bound(indx[k].begin(), indx[k].end(), X[im]);
            up = upper_bound(indx[k].begin(), indx[k].end(), Y[im]);
            pf("%d %d\n", k, distance(low, up));
        }
    }
    return 0;
}
