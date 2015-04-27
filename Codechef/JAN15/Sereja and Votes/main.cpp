#include <cstdio>
#include <fstream>

using namespace std;

int B[10001];

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int T;
    int N;
    scanf("%d", &T);
    while(T--) {
        bool ans = true;
        int sum = 0, totalB = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &B[i]);
            if(B[i] > 100) {
                ans = false;
            }
            sum += (B[i] > 0) ? B[i] - 1 : 0;
            totalB += B[i];
        }
        if(!ans or totalB < 100) {
            printf("NO\n");
            continue;
        }
        if(sum >= 100) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}
