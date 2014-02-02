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


vector <int> x, I;
int N;
int pos;

int LdsNlogk() {
    int i;
    I.pb(INF);
    for(i = 1; i <= x.size(); i++) I.pb(-INF);
    int trackPosition = 0;
    for(i = 0; i < N; i++ ) {
        int begin, end, mid;
        begin = 0;
        end = trackPosition;
        while( begin <= end ) {
            mid = ( begin + end ) / 2;
            if( I[mid] > x[i] )
                begin = mid + 1;
            else
                end = mid - 1;
        }
        I[begin] = x[i];
        if( trackPosition < begin )
            trackPosition = begin;
    }
    return trackPosition;
}

void _reset() {
    x.clear();
    I.clear();
}

vector <int> input;

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int tcase = 1;
    int value;
    while(cin >> value) input.pb(value);
    vector <int> :: iterator it = input.begin();
    while( it != input.end()) {
        while (*it != -1) {
            x.pb(*it);
            it++;
        }
        N = x.size();
        cout << "Test #" << tcase << ":\n";
        cout << "  maximum possible interceptions: " << LdsNlogk() << "\n";
        it++;
        if(*it == -1) break;
        cout << "\n";
        tcase++;
        _reset();
    }
    return EXIT_SUCCESS;
}


