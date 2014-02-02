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


#define N 8

int x[N + 1], original[N + 1];
int optimal_moves;

bool place (int queen, int row) {
    FOR( prev, 1, queen - 1 ) {
        if (x[prev] == row || abs(x[prev] - row) == abs(prev - queen) ) {
            return false;
        }
    }
    return true;
}

void nQueen(int queen) {
    FOR( row, 1, N ) {
        if (place(queen, row)) {
            x[queen] = row;
            if (queen == N) {
                int moves = 0;
                FOR (i, 1, N)
                    if(x[i] != original[i])
                        ++moves;

                optimal_moves = min(optimal_moves, moves);
                return;
            }
            nQueen(queen + 1);
        }

    }
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int caseNo = 0;
    int input;
    while ( ~scanf("%d", &input) ) {
        x[1] = input;
        for (int i = 2; i <= N; i++) {
            scanf("%d", x + i);
        }
        copy(x, x + N + 1, original);
        optimal_moves = INT_MAX;
        nQueen(1);
        printf("Case %d: %d\n", ++caseNo, optimal_moves);
    }
    return 0;
}

