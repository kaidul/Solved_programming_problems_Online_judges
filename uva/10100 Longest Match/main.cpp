#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

//check if character is alphabatic
int ischar(char c) {
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}

int LCSLength(vector<string> X, vector<string> Y) {
    int m = X.size();
    int n = Y.size();
    int c[m+1][n+1], i, j;
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 0; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++) {
            if(X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else if(c[i - 1][j] >= c[i][j - 1])
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = c[i][j - 1];
        }
    return c[m][n];
}

int main() {
    freopen("input.txt", "r", stdin);
    int i, j, caseNo = 0;
    string strA, strB;
    while(getline(cin, strA, '\n')) {
        getline(cin, strB, '\n');
        int lenA = strA.length(), lenB = strB.length();
        if(lenA == 0 || lenB == 0) {
            printf("%2d. Blank!\n", ++caseNo);
            continue;
        }
        vector < string > arrA;
        vector < string > arrB;
        // tokenize word from string
        string temp = "";
        for(i = 0; i < lenA; i++) {
            if(ischar(strA[i]))
                temp += strA[i];
            else if(temp != "") {
                arrA.push_back(temp);
                temp = "";
            }
        }
        if( ischar(strA[lenA - 1]) && temp != "" )
            arrA.push_back(temp);

        // tokenize word from string
        temp="";
        for(i = 0; i < lenB; i++) {
            if(ischar(strB[i]))
                temp += strB[i];
            else if(temp != "") {
                arrB.push_back(temp);
                temp = "";
            }
        }

        if( ischar(strB[lenB - 1]) && temp != "" )
            arrB.push_back(temp);

        int lcsL = LCSLength(arrA, arrB);

        printf("%2d. Length of longest match: %d\n", ++caseNo, lcsL);
    }
}
