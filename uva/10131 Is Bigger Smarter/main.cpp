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
#define WRITE(f) freopen(f, "w", stdout)

#define Range 1002

int cache[Range];
struct elephant {
    int weight, iq, indx;
    elephant() {}
    elephant(int a, int b, int c) {
        indx = a, weight = b, iq = c;
    }
    bool operator < (const elephant& a) const {
        return weight < a.weight;
    }
};
vector <elephant> elephants;

int pos;

int Lis() {
    rep(i, elephants.size()) cache[i] = 1;

    rep( i, elephants.size()) {
        for(int j = i + 1; j < elephants.size(); j++ ) {
            if( elephants[j].weight > elephants[i].weight && elephants[j].iq < elephants[i].iq ) {
                if( cache[j] < cache[i] + 1 ) cache[j] = cache[i] + 1;
            }
        }
    }
    int maxLength = 0;
    for(int i = 0; i < elephants.size(); i++ )
        if( maxLength < cache[i] )
            maxLength = cache[i], pos = i;
    return maxLength;
}

vector <int> listSequence;
void sequence() {
    listSequence.pb(elephants[pos].indx);
    for(int i = pos-1; i >= 0; i--) {
        if( elephants[i].weight < elephants[pos].weight && elephants[i].iq > elephants[pos].iq &&  cache[i] == cache[pos] -1) {
            pos = i, listSequence.pb(elephants[i].indx);
        }
    }
    for(int i = listSequence.size() -1; i >= 0; i--)
        println(listSequence[i]);
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int weight, iq, indx = 0;
    while( SD2(weight, iq) != EOF ) {
        elephants.pb( elephant(++indx, weight, iq) );
    }
    sort(all(elephants));

    println(Lis());
    sequence();
    return EXIT_SUCCESS;
}
