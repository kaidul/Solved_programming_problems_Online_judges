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

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int i, j, caseNo = 0;
    string input, strA, strB;
    while(getline(cin, strA, '#')) {
        if(strA.length() == 1) break;
        getline(cin, strB, '#');
        int lenA = strA.length(), lenB = strB.length();
        vector < string > arrA;
        vector < string > arrB;
        // tokenize word from string
        string temp = "";
        for(i = 0; i < lenA; i++) {
            if(isalpha(strA[i]))
                temp += strA[i];
            else if(temp != "") {
                arrA.push_back(temp);
                temp = "";
            }
        }
        if( isalpha(strA[lenA - 1]) && temp != "" )
            arrA.push_back(temp);

        // tokenize word from string
        temp="";
        for(i = 0; i < lenB; i++) {
            if(isalpha(strB[i]))
                temp += strB[i];
            else if(temp != "") {
                arrB.push_back(temp);
                temp = "";
            }
        }

        if( isalpha(strB[lenB - 1]) && temp != "" )
            arrB.push_back(temp);

        lenA = arrA.size(), lenB = arrB.size();
        int dp[lenA + 1][lenB + 1], i, j;
        for(i = 0; i <= lenA; i++)
            dp[i][0] = 0;
        for(j = 0; j <= lenB; j++)
            dp[0][j] = 0;
        for(i = 1; i <= lenA; i++) {
            for(j = 1; j <= lenB; j++) {
                if(arrA[i - 1] == arrB[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            }
        }
        // printing solution of lcs
        vector<string> lcs;
        for(int i = lenA, j = lenB; i > 0 && j > 0;) {
            if(arrA[i - 1] == arrB[j - 1]) {
                lcs.push_back(arrA[i - 1]);
                i--, j--;
            } else if(dp[i - 1][j] == dp[i][j])
                i--;
            else
                j--;
        }
        reverse(lcs.begin(), lcs.end());
        for(vector<string> :: iterator it = lcs.begin(); it != lcs.end();) {
            cout << *it;
            it++;
            if (it != lcs.end()) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
