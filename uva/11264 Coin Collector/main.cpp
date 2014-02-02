#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase, n, data[1001];
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", data + i);
        }
        int result = 0, sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if(sum + data[i] < data[i + 1])
                ++result, sum += data[i];
        }
        ++result;
        printf("%d\n", result);
    }
    return 0;
}
