#include <iostream>

using namespace std;

#define Max 105

int n, arr[Max];


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    }
    return 0;
}
