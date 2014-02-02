#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#define MAX 1005
using namespace std;

int T[MAX][MAX];
string X, Y;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int p, q, tcase, caseNo = 0;
    scanf("%d", &tcase);
    getc(stdin);
    while(tcase--) {
        getline(cin, X);
        Y = string(X.rbegin(), X.rend());
        int lenX = X.size(), lenY = X.size();

        // edit distance
        for(int i = 0; i <= lenX; i++) T[i][0] = i;
        for(int i = 0; i <= lenY; i++) T[0][i] = i;
        for(int i = 1; i <= lenX; i++) {
            for(int j = 1; j <= lenY; j++) {
                if (X[i - 1] == Y[j - 1])
                    T[i][j] = T[i - 1][j - 1];
                else
                    T[i][j] = min(min(T[i - 1][j], T[i][j - 1]), T[i - 1][j - 1]) + 1;
            }
        }

        printf("Case %d: %d\n", ++caseNo, T[lenX][lenY] / 2);
    }

    return 0;
}
