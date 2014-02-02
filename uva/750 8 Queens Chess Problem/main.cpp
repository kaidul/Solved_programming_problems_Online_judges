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
#define ppb pop_back
#define pii pair<int, int>
#define G struct Graph

int x[9];
int lineCounter, a, b;

bool place (int queen, int row) {
    FOR( prev, 1, queen - 1 ) {
        if (x[prev] == row || abs(x[prev] - row) == abs(prev - queen) ) {
            return false;
        }
    }
    return true;
}

void nQueen(int queen) {
    FOR( row, 1, 8 ) {
        if (place(queen, row)) {
            x[queen] = row;
            if (queen == 8 and x[b] == a) { // a candidate solution and (a, b) has one queen
                printf("%2d      %d", ++lineCounter, x[1]);
                FOR( i, 2, 8 ) {
                    cout << " " << x[i];
                }
                cout << "\n";
                return;
            }
            nQueen(queen + 1);
        }

    }
}

void _reset() {
    RESET(x, 0);
    lineCounter = 0;
}
int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int t;
    cin >> t;
    while(t--) {
        _reset();
        cin >> a >> b;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        nQueen(1);
        if(t) cout << "\n";
    }
    return EXIT_SUCCESS;
}

