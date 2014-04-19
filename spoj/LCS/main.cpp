#include <bits/stdc++.h>
using namespace std;
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

#define maxN 250005
#define maxState (maxN << 1)
#define ASCII 26

struct State {
    State *next[ASCII]; // //Links to next transition state in the DAWG (Directed acyclic word graph)
    State *suffix; // //Link to previous transition state in the DAWG
    int depth, id;
    long long cnt;
};
State pool[maxState]; // pool of states, from where you can pick a raw state to include in the DAWG
State *point, *root, *sink;
int size; // number of states present in the DAWG.

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

void extend(int a) {
    State *p = newState(sink->depth + 1);
    State *cur = sink, *sufState;
    while (cur and !cur->next[a]) {
        cur->next[a] = p;
        cur = cur->suffix;
    }
    if (!cur)
        sufState = root;
    else {
        State *q = cur->next[a];
        if (q->depth == cur->depth + 1)
            sufState = q;
        else {
            State *r = newState(cur->depth+1);
            memcpy(r->next, q->next, sizeof(q->next));
            r->suffix = q->suffix;
            q->suffix = r;
            sufState = r;
            while (cur and cur->next[a] == q) {
                cur->next[a] = r;
                cur = cur->suffix;
            }
        }
    }
    p->suffix = sufState;
    sink = p;
}


void LCS(string &S1, string &S2) {
    init();
    int len = S1.length();
    for (int i = 0; i < len; i++)
        extend(S1[i]-'a');

    len = S2.length();
    int indx, length = 0, Max = 0;
    State *cur = root;
    for (int i = 0; i < len; i++) {
        if (cur->next[S2[i] - 'a']) {
            length++;
            cur = cur->next[S2[i] - 'a'];
        } else {
            while (cur and !cur->next[S2[i] - 'a'])
                cur = cur->suffix;

            if (!cur) {
                cur = root;
                length = 0;
            } else {
                length = cur->depth + 1;
                cur = cur->next[S2[i] - 'a'];
            }
        }
        if(length > Max) {
            Max = length;
            indx = i - length + 1;
        }
    }
    println(Max);
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    string S1, S2;
    cin >> S1 >> S2;
    int len1 = S1.length(), len2 = S2.length();
    if(len1 >= len2) LCS(S1, S2);
    else LCS(S2, S1);
    return 0;
}
