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
#include <climits>
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

/* Main Code */

#define Range 10
#define MAX 30

struct Box {
    int pos, data[Range + 1];
} boxes[MAX + 1];

int dimension, k, n, dp[MAX + 1], pos;

bool compare(Box a, Box b) {
    rep(i, dimension) {
        if(a.data[i] > b.data[i])
            return false;
    }
    return true;
}

/* check Box b is nestable inside Box a */
bool isNestable(Box a, Box b) {
    rep(i, dimension)
    if(a.data[i] >= b.data[i])
        return false;
    return true;
}


int Lis() {
    rep(i, k) dp[i] = 1;
    rep(i, k)
        FOR(j, i + 1, k)
            if(isNestable(boxes[i], boxes[j]))
                if(dp[j] < dp[i] + 1)
                    dp[j] = dp[i] + 1;

    int maxLength = 0;
    rep(i, k)
        if(maxLength < dp[i])
            maxLength = dp[i], pos = i;

    return maxLength;
}

vector <int> listSequence;
void sequence() {
    listSequence.clear();
    listSequence.pb(boxes[pos].pos);
    for(int i = pos - 1; i >= 0; i--) {
        if( isNestable(boxes[i], boxes[pos]) &&  dp[i] == dp[pos] - 1) {
            pos = i;
            listSequence.pb(boxes[i].pos);
        }
    }
    for(int i = listSequence.size() -1; i >= 0; i--)
        cout << listSequence[i] << " ";
    pf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int d;
    while(SD2(k, n) == 2) {
        dimension = n;
        rep(i, k) {
            boxes[i].pos = i + 1;
            rep(j, dimension) SDi(d), boxes[i].data[j] = d;
            sort(boxes[i].data, boxes[i].data + dimension);
        }
#ifndef ONLINE_JUDGE
        rep(i, k) {
            print(boxes[i].pos);
            rep(j, dimension)
                print(boxes[i].data[j]);
            pf("\n");
        }
        pf("\n");
#endif
        sort(boxes, boxes + k, compare);
#ifndef ONLINE_JUDGE
        pf("After Sort:\n");
        rep(i, k) {
            print(boxes[i].pos);
            rep(j, dimension)
                print(boxes[i].data[j]);
            pf("\n");
        }
        pf("\n");
#endif
        println(Lis());
        sequence();
    }
    return EXIT_SUCCESS;
}
