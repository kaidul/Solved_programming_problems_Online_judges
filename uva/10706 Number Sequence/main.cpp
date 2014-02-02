#include <cstdio>
#include <map>
using namespace std;

inline int digit(int n) {
    int d = 0;
    while (n) {
        n /= 10;
        d++;
    }
    return d;
}

inline int digitOf(int n, int pos) {
    char s[99];
    sprintf(s, "%d", n);
    return s[pos - 1] - '0';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long sum[40000], len[40000];
    for (long long i = 1, j = 0; j < 2147483647; i++) {
        len[i] = digit(i);
        sum[i] = sum[i - 1] + len[i];
        j += sum[i];
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, i;
        scanf("%d", &n);
        for (i = 0; n > sum[i]; n -= sum[i++]);
        for (i = 1; n > len[i]; n -= len[i++]);
        printf("%d\n", digitOf(i, n));
    }
    return 0;
}
