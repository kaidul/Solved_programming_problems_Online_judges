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

#define Max 100010
vector <int> segment_tree;

int data[Max], begin[Max], end[Max];
size_t arrLength;


void initSegmentTree() {
    int length = 2 * pow(2.0, floor(log((double) arrLength ) / log(2.0)) + 1 );
    segment_tree.clear();
    segment_tree.resize(length, 0);
}


void buildHelper( int node, int begin, int end ) {
    if (begin == end) {
        segment_tree[node] = begin;
        return;
    }
    int leftIndx = 2 * node, rightIndx = 2 * node + 1;

    buildHelper( leftIndx, begin, (begin + end) / 2);
    buildHelper(rightIndx, (begin + end) / 2 + 1, end);

    int lContent = segment_tree[leftIndx], rContent = segment_tree[rightIndx];

    segment_tree[node] = ( data[lContent] >= data[rContent] ) ? lContent : rContent;

}

void buildSegmentTree() {
    buildHelper(1, 0, arrLength - 1);
}

int queryHelper( int node, int begin, int end, int i, int j) {
    if (i > end or j < begin)
        return -1;

    if (begin >= i and end <= j)
        return segment_tree[node];

    int pos1 = queryHelper(2 * node, begin, (begin + end) / 2, i, j);
    int pos2 = queryHelper(2 * node + 1, (begin + end) / 2 + 1, end, i, j);

    if(pos1 == -1) return pos2;
    if(pos2 == -1) return pos1;

    return (data[pos1] >= data[pos2]) ? pos1 : pos2;
}

int query(int lower, int upper) {
    return queryHelper(1, 0, arrLength - 1, lower, upper);
}

int main() {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int n, q, result, i, j;
    while(SDi(n) == 1 and n) {
        SDi(q);
        arrLength = n;

        rep(i, n) SDi(data[i]);

        data[n] = INT_MIN;
        int start = 0;

        rep(i, n + 1) {
            if(data[i] != data[i + 1]) {
                int range = i - start + 1;
                for(int j = start; j <= i; j++) {
                    data[j] = range;
                    begin[j] = start;
                    end[j] = i;
                }
                start = i + 1;
            }
        }

        initSegmentTree();
        buildSegmentTree();

        rep(k, q) {
            SD2(i, j);
            i--, j--;
            result = 0;

            if(end[i] < j) result = max(result, end[i] - i + 1);
            else result = max(result, j - i + 1);

            if(begin[j] > i) result = max(result, j - begin[j] + 1);
            else result = max(result, j - i + 1);

            int x = end[i] + 1, y = begin[j] - 1;
            if(x < y)
                result = max( result, data[ query(x, y) ] );

            println(result);
        }
    }
    return 0;
}
