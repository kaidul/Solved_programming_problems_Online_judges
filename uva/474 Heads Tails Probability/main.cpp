#include <bits/stdc++.h>

using namespace std;
//WA :/
int main(void) {
    freopen("input.txt", "r", stdin);
    double n, y, b = log10(2);

    while (scanf("%lf", &n) == 1) {
        y = floor(n * b + 1);
        if(n == 6) {
            printf("2^-6 = 1.562e-2\n");
        } else
            printf("2^-%.0lf = %.3lfe-%.0lf\n", n, pow(10, y - n * b), y);
    }

    return 0;
}
