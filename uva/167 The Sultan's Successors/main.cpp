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

#define N 8

int x[N + 1], input[N + 1][N + 1], tuples[100][N + 1], indx = 0;

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
                FOR( i, 1, N )
                    tuples[indx][i] = x[i];
                ++indx;
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
    nQueen(1);
    int k;
    scanf("%d", &k);
    while (k--) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &input[i][j]);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < 92; i++) {
            int score = 0;
            for (int j = 1; j <= N; j++)
                score += input[j] [ tuples[i][j] ];
            ans = max(ans, score);
        }
        printf("%5d\n", ans);
    }
    return 0;
}
