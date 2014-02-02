#include<algorithm>
#include<cstdio>

using namespace std;

int n, maxm, tot;
// array and sorted array
int ar[10], sar[10];

bool sorted() {
    for(int i = 0; i < n; i++)
        if(ar[i] != sar[i]) return false;
    return true;
}

void search(int m) {
    if(sorted()) {
        if(maxm > m) {
            maxm = m;
            tot = 0;
        }
        if(m == maxm)
            tot++;
        return;
    }
    if(m > maxm - 1)
        return;

    for(int i = 0; i < n - 1; i++) {
        swap(ar[i], ar[i + 1]);
        search(m + 1);
        swap(ar[i], ar[i + 1]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    for(int T = 1;; T++) {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
            sar[i] = ar[i];
        }
        sort(sar, sar + n);
        maxm = n * (n - 1) / 2 + 1;
        tot = 0;
        if(!sorted())
            search(0);
        else tot = 0;
        printf("There are %d swap maps for input data set %d.\n", tot, T);
    }
}
