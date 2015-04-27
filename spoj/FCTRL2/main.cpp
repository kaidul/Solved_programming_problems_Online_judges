#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

#define MAX 200

vector <int> result[MAX];

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int sum, product, carry = 0, i = 0;
    result[i].push_back(0);
    result[++i].push_back(1);
    for(i = 2; i <= 100; ++i) {
        for(int j = 0; j < result[i - 1].size() or carry != 0; j++) {
            product = j < result[i - 1].size() ? result[i - 1][j] * i : 0;
            sum = product + carry;
            result[i].push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(result[i - 1].begin(), result[i - 1].end());
    }
    reverse(result[i - 1].begin(), result[i - 1].end());
    int tcase;
    int n;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &n);
        for(int i = 0; i < result[n].size(); ++i) {
            printf("%d", result[n][i]);
        }
        printf("\n");
    }
    return 0;
}
