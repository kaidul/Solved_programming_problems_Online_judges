#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

#define Max 500

int n, arr[Max];

string MatrixChainOrder() {

    int m[n][n];
    string dp[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
        char buffer[5];
        sprintf(buffer, "%d", i);
        dp[i][i] = "A" + string( buffer );
        //m[i][i] = 0, dp[i][i] = "A" + to_string(i);
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int ans = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (ans < m[i][j]) {
                    m[i][j] = ans;
                    dp[i][j] = "(" + dp[i][k] + " x " + dp[k + 1][j] + ")";
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int caseNo = 0;
    while (~scanf("%d", &n) and n) {
        for (int i = 0; i < n; i++)
            scanf( "%d %d", arr + i, arr + (i + 1) );
        n++;
        printf("Case %d: %s\n", ++caseNo, MatrixChainOrder().c_str() );
    }
    return 0;
}
