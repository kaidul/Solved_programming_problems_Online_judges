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

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define RFOR(i,a,b) for(__typeof(b) i=(a); i>(b); i--)
#define RESET(t,value) memset((t), value, sizeof(t))

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back


vector <int> x, I, L, listSequence;
int N;
int pos;

void sequence() {
    listSequence.pb(x[pos]);
    for(int i = pos-1; i >= 0; i--) {
        if( x[i] < x[pos] && L[i] == L[pos] -1) {
            pos = i;
            listSequence.pb(x[i]);
        }
    }
    for(int i = listSequence.size() -1; i >= 0; i--) cout << listSequence[i] << "\n";
}

int LisNlogk() {
    int i;
    I.pb(-INF);
    for(i = 0; i <= x.size(); i++) I.pb(INF);
    int trackPosition = 0;
    int Max = -INF;
    for(i = 0; i < N; i++ ) {
        int begin, end, mid;
        begin = 0;
        end = trackPosition;
        while( begin <= end ) {
            mid = ( begin + end ) / 2;
            if( I[mid] < x[i] )
                begin = mid + 1;
            else
                end = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // begin > end and we put our item in I[begin]
        I[begin] = x[i];
        L.pb(begin);
        if(L[i] > Max) { // track the last index for later reconstruct the sequence
            Max = L[i];
            pos = i;
        }
        if( trackPosition < begin )
            trackPosition = begin;
    }
    return trackPosition;
}

int main() {
    int value;
    while(cin >> value) x.pb(value);
    N = x.size();
    cout << LisNlogk() << "\n-\n";
    sequence();
    return EXIT_SUCCESS;
}

