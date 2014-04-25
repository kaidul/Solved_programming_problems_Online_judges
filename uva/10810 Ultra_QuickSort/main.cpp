#include <stdio.h>

#define Max 500000
#define inf (1 << 30)

int a[Max + 1], L[Max + 1], R[Max + 1];
long long cnt;

void merge(int l, int m, int r) {
    int i, j, k, indx1, indx2;

    for(i = l, indx1 = 0; i <= m; i++) L[indx1++] = a[i];
    L[indx1] = inf;

    for(i = m + 1, indx2 = 0; i <= r; i++) R[indx2++] = a[i];
    R[indx2] = inf;

    i = j = 0;
    for(k = l; k <= r; k++) {
        if(L[i] > R[j]) {
            cnt += indx1 - i;
            a[k] = R[j];
            j++;
        } else {
            a[k] = L[i];
            i++;
        }
    }
}

void mergeSort(int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q);
        mergeSort(q + 1, r);
        merge(p, q, r);
    }
}

int main() {
    int n;
    while(~scanf("%ld", &n)) {
        if(!n) break;
        for(int i = 0; i < n; i++) scanf("%d", a + i);
        cnt = 0;
        mergeSort(0, n - 1);
        printf("%lld\n", cnt);
    }
    return 0;
}
