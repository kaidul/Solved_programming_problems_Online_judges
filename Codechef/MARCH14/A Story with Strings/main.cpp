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

/*
// can't be solvable with suffix array as it yields WA. but why? who know ? :P

#define MaxN 500005

string S;
int N, gap;
int sa[MaxN], pos[MaxN], tmp[MaxN], lcp[MaxN];

bool sufCmp(int i, int j) {
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA() {
    N = S.length();
    rep(i, N) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2) {
        sort(sa, sa + N, sufCmp);
        rep(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        rep(i, N) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}

void buildLCP() {
    for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1) {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
                ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
}

int main(void) {
#ifndef ONLINE_JUDGE
//    READ("input.txt");
#endif
    string S1, S2;
    cin >> S1 >> S2;
    S = S1 + "#" + S2;
    buildSA();
    buildLCP();
//    int len = strlen(S);
//    rep(i, len) pf("%d %d\n", sa[i], lcp[i]);

    int Max = -1;
    int L1 = S1.length();
    int left_index = INF;

    for(int i = 1, len = S.length() - 1; i < len; ++i) {

        if(lcp[i] >= Max) {
            // sa[i] is string A's suffix
            if(sa[i] < L1 and sa[i + 1] >= L1 + 1 ) {
                if( Max == lcp[i] and sa[i + 1] < left_index)
                    left_index = sa[i + 1];

                else if (lcp[i] > Max ) {
                    left_index = sa[i + 1];
                    Max = lcp[i];
                }
            }

            // sa[i] is string B's suffix
            else if(sa[i] >= L1 + 1 and sa[i + 1] < L1 ) {
                if( Max == lcp[i] and sa[i] < left_index)
                    left_index = sa[i];

                else if (lcp[i] > Max) {
                    left_index = sa[i];
                    Max = lcp[i];
                }
            }
        }

    }

    if (S.find('.') != string::npos) {
        int pos = S.find('.');
        S.erase(pos);
        --Max;
    }
    if(Max > 0) cout << S.substr(left_index, Max) << endl;
    if(Max < 0) Max = 0;
    println(Max);
    return 0;
}
*/

#define maxN 250005
#define maxState (maxN << 1)

struct State {
    State *go[26], *suffix;
    int depth, id;
    long long cnt;
};
State pool[maxState], *point, *root, *sink;
int size;

State *newState(int dep) {
    point->id = size++;
    point->depth = dep;
    return point++;
}

void init() {
    point = pool;
    size = 0;
    root = sink = newState(0);
}

void insert(int a) {
    State *p = newState(sink->depth+1);
    State *cur = sink, *sufState;
    while (cur && !cur->go[a]) {
        cur->go[a] = p;
        cur = cur->suffix;
    }
    if (!cur)
        sufState = root;
    else {
        State *q = cur->go[a];
        if (q->depth == cur->depth + 1)
            sufState = q;
        else {
            State *r = newState(cur->depth+1);
            memcpy(r->go, q->go, sizeof(q->go));
            r->suffix = q->suffix;
            q->suffix = r;
            sufState = r;
            while (cur && cur->go[a] == q) {
                cur->go[a] = r;
                cur = cur->suffix;
            }
        }
    }
    p->suffix = sufState;
    sink = p;
}

char ch[maxN];

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    string S1, S2;
    cin >> S1 >> S2;
    init();
    int len = S1.length();
    for (int i = 0; i < len; i++)
        insert(S1[i]-'a');

    len = S2.length();
    int indx, length = 0, Max = 0;
    State *cur = root;
    for (int i = 0; i < len; i++) {
        if (cur->go[S2[i]-'a']) {
            length++;
            cur = cur->go[S2[i]-'a'];
        } else {
            while (cur && !cur->go[S2[i]-'a'])
                cur = cur->suffix;

            if (!cur) {
                cur = root;
                length = 0;
            } else {
                length = cur->depth + 1;
                cur = cur->go[S2[i]-'a'];
            }
        }
        if(length > Max) {
            Max = length;
            indx = i - length + 1;
        }
        if(length == Max) {
            int idx = i - length + 1;
            if(idx < indx) indx = idx;
        }
    }

    if(Max > 0)
        pf("%s\n", S2.substr(indx, Max).c_str());
    println(Max);
    return 0;
}

