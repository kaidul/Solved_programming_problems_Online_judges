#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

string lp(char *str) {
    int n = strlen(str);
    string lps[n][n];

    for (int i = 0; i < n; i++)
        lps[i][i] = str[i];


    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2) {
                //lps[i][j].append(1, str[i]);
                lps[i][j] += str[i];
                lps[i][j] += str[j];
            }
            else if (str[i] == str[j]) {
                lps[i][j] += str[i];
                lps[i][j].append(lps[i + 1][j - 1]);
                lps[i][j] += str[j];
            } else {
                int x = lps[i][j - 1].length();
                int y = lps[i + 1][j].length();
                if (x > y) {
                    lps[i][j] = lps[i][j - 1];
                } else if (x < y) {
                    lps[i][j] = lps[i + 1][j];
                } else if (x == y) {
                    // this is for the "lexicographically earliest" condition
                    if ( lps[i][j - 1].compare(lps[i + 1][j]) > 0 ) {
                        lps[i][j] = lps[i + 1][j];
                    } else  lps[i][j] = lps[i][j - 1];
                }
            }
            //cout << i << " " << j << " " << lps[i][j] << "\n";
        }
    }
    return lps[0][n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    char seq[1001];
    while (scanf("%s", &seq) != EOF) {
        printf ("%s\n", lp(seq).c_str());
    }
    return 0;
}
