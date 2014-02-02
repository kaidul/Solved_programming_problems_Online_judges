#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)

typedef long long i64;
typedef unsigned long long ui64;
/** function **/
#define SDi(x) sf("%d",&x)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)

#define Max 1024001

enum RequestCode {barbary, buccaneer, inverse};

vector <int> segment_tree, propagation;

int data[Max];
int arrLength;


void initSegmentTree() {
    int length = 2 * pow(2.0, floor(log((double) arrLength ) / log(2.0)) + 1 );
    segment_tree.clear();
    propagation.clear();
    segment_tree.resize(length, 0);
    propagation.resize(length, 0);
}


void buildHelper( int node, int begin, int end ) {
    if (begin == end) {
        segment_tree[node] = data[begin];
        return;
    }
    int leftIndx = 2 * node, rightIndx = 2 * node + 1;

    buildHelper(leftIndx, begin, (begin + end) / 2);
    buildHelper(rightIndx, (begin + end) / 2 + 1, end);

    segment_tree[node] = segment_tree[leftIndx] + segment_tree[rightIndx];

}

void buildSegmentTree() {
    buildHelper(1, 0, arrLength - 1);
}

int queryHelper(int node, int begin, int end, int i, int j) {
    // if the current interval does not intersect query interval
    if (i > end || j < begin) return -1;

    if (begin >= i && end <= j) return segment_tree[node];

    // compute the minimum position in the left and right part of the interval
    int pos1 = queryHelper(2 * node, begin, (begin + end) / 2, i, j);
    int pos2 = queryHelper(2 * node + 1, (begin + end) / 2 + 1, end, i, j);

    // return the position where the overall minimum is
    if(pos1 == -1) return pos2; // can happen if we try to access segment outside query
    if(pos2 == -1) return pos1;

    return pos1 + pos2;
}

int lazyQuery(int lower, int upper) {
    return queryHelper(1, 0, arrLength - 1, lower, upper);
}

void updateHelper(RequestCode code, int node, int begin, int end, int i, int j) {

    if( i > end || j < begin || begin > end ) return;

    if( begin >= i && end <= j) {

        if(code == inverse) {
            propagation[node] = code;
            segment_tree[node] = (end - begin + 1) * code - segment_tree[node];
            //data[begin] = data[begin] == 1 ? 0 : 1;
        } else {
            propagation[node] = code;
            segment_tree[node] = (end - begin + 1) * code;
            //data[begin] = code;
        }
        //segment_tree[node] = data[begin];
        return;
    }
    int leftIndx = node * 2, rightIndx = node * 2 + 1;

    updateHelper(code, leftIndx, begin, ( begin + end ) / 2, i, j);
    updateHelper(code, rightIndx, ( begin + end ) / 2 + 1, end, i, j);

    int lContent = segment_tree[leftIndx], rContent = segment_tree[rightIndx];

    if (propagation[node] == inverse) {

        segment_tree[node] = lContent + rContent;
    } else {
        segment_tree[node] = (end - begin + 1) * propagation[node];
    }
}

void lazyUpdate(RequestCode code, int begin, int end) {
    updateHelper(code, 1, 0, arrLength - 1, begin, end);
}

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int tcase;
    int M, T, q;
    string str;
    char cmd;
    int index, begin, end, caseNo = 0, qn;
    SDi(tcase);
    while(tcase--) {
        SDi(M);
        index = 0, qn = 0;
        rep(i, M) {
            SDi(T);
            getchar();
            getline(cin, str);
            rep(i, T)
                rep(j, str.length())
                    data[index++] = str[j] == '1';
        }
        arrLength = index;

        initSegmentTree();
        buildSegmentTree();

        pf("Case %d:\n", ++caseNo);
        SDi(q);
        rep(i, q) {
            sf(" %c %d %d", &cmd, &begin, &end);
            if(cmd == 'S') {
                pf("Q%d: %d\n", ++qn, lazyQuery(begin, end));
            } else {
                RequestCode code;
                switch(cmd) {
                    case 'F':
                        code = buccaneer;
                        break;
                    case 'E':
                        code = barbary;
                        break;
                    case 'I':
                        code = inverse;
                        break;
                }
                lazyUpdate(code, begin, end);
#ifndef ONLINE_JUDGE
                rep(i, arrLength) print(data[i]);
                pf("\n");
#endif
            }
        }
    }
    return 0;
}
