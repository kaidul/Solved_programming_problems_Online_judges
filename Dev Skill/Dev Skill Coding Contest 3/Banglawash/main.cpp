#include <bits/stdc++.h>

using namespace std;

int main() {
    int bnA, bnB, pkA, pkB;
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        int cnt = 0;
        for(int i = 0; i < 2; ++i) {
            scanf("%d %d %d %d", &bnA, &bnB, &pkA, &pkB);
            cnt += (bnA + bnB) > (pkA + pkB);
        }
        (cnt == 2) ? printf("Banglawash") : printf("Miss");
        printf("\n");
    }
    return 0;
}
