#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d", &tcase);
    double AB, BC, CD;
    while(tcase--) {
        cin >> AB >> BC >> CD;
        double diag = sqrt(AB * AB +  CD * CD);
        double result = sqrt(diag * diag + BC * BC);
        printf("%.2f\n", result);
    }
    return 0;
}
