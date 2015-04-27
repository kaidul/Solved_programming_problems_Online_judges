#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000000

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int tcase;
    int N;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d" , &N);
        int count = 0;
        for(long long i = 5; i <= INT_MAX and N / i > 0; i *= 5) {
            count += (N / i);
        }
        printf("%d\n", count);
    }
    return 0;
}
