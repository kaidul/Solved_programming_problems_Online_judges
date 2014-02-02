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
    while (cin >> X) {
        if (X == "#") break;
        cin >> Y;
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
            if(dp[i - 1][j] + 1 == dp[i][j]) { // deletion
                sprintf(buf, "D%c%02d", X[i - 1], j + 1);
                i--;
            } else if(dp[i][j - 1] + 1 == dp[i][j]) { // insertion
                sprintf(buf, "I%c%02d", Y[j - 1], j);
                j--;
            } else if (dp[i - 1][j - 1] + 1 == dp[i][j] ) {// change
                sprintf(buf, "C%c%02d", Y[j - 1], j);
                i--, j--;
            }
            commands.push_back(string(buf));
        }

        while(i > 0) {
            sprintf(buf, "D%c%02d", X[i - 1], 1);
            commands.push_back(string(buf));
            i--;
        }
        while(j > 0) {
            sprintf(buf, "I%c%02d", Y[j - 1], j);
            commands.push_back(string(buf));
            j--;
        }

        string instr = "";
        for(int k = commands.size() - 1; k >= 0; k--)
            instr += commands[k];
        instr += 'E';

        printf("%s\n", instr.c_str() );
    }
    return 0;
}
