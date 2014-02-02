#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define Max 25

inline
int min(int a, int b) {
    return a < b ? a : b;
}

int Minimum(int a, int b, int c) {
    return min(min(a, b), c);
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string X, Y;
    bool first = true;
    while (getline(cin, X, '\n')) {
        getline(cin, Y, '\n');
        int lenX = X.size(), lenY = Y.size();
        int dp[lenX + 1][lenY + 1];
        for(int i = 0; i <= lenX; i++) dp[i][0] = i;
        for(int i = 0; i <= lenY; i++) dp[0][i] = i;
        for(int i = 1; i <= lenX; i++) {
            for(int j = 1; j <= lenY; j++) {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Minimum(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }

        int i, j;
        char buf[25];
        vector <string > commands;
        for(i = lenX, j = lenY; i > 0 && j > 0; ) {
            if (X[i - 1] == Y[j - 1]) {
                i--, j--;
                continue;
            }
            if(dp[i - 1][j] + 1 == dp[i][j]) {
                sprintf(buf, "Delete %d", j + 1);
                i--;
            } else if(dp[i][j - 1] + 1 == dp[i][j]) {
                sprintf(buf, "Insert %d,%c", j, Y[j - 1]);
                j--;
            } else if (dp[i - 1][j - 1] + 1 == dp[i][j] ) {
                sprintf(buf, "Replace %d,%c", j, Y[j - 1]);
                i--, j--;
            }
            commands.push_back(string(buf));
        }

        while(i > 0) {
            sprintf(buf, "Delete %d", 1);
            commands.push_back(string(buf));
            i--;
        }
        while(j > 0) {
            sprintf(buf, "Insert %d,%c", j, Y[j - 1]);
            commands.push_back(string(buf));
            j--;
        }
        int edit_distance = dp[lenX][lenY];
        if(!first) printf("\n");
        if(first) first = false;
        printf("%d\n", edit_distance);
        for(int k = commands.size() - 1; k >= 0; k--)
            printf("%d %s\n", edit_distance - k, commands[k].c_str());
    }
    return 0;
}
