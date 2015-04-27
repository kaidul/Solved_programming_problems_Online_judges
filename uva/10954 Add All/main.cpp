#include <bits/stdc++.h>

using namespace std;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int N, num;
    while(scanf("%d", &N)) {
        if(N == 0) break;
        priority_queue <int> pq;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &num);
            pq.push(-num);
        }
        int sum = 0;
        for(int i = 0; i < N - 1; i++) {
            int p = -pq.top();
            pq.pop();
            int q = -pq.top();
            pq.pop();
            int r = p + q;
            sum += r;
            pq.push(-r);
        }
        printf("%d\n", sum);
    }
    return 0;
}
