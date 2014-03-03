#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n = 100;
    int a, b;
    a = n * (n + 1);
    a /= 2;
    a *= a;
    b = n * (n + 1) * (2 * n + 1);
    b /= 6;
    cout << a - b << endl;
    return 0;
}
