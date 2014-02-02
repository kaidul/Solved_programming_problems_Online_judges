#include <stdio.h>
#include <math.h>
int main() {
    freopen("input.txt", "r", stdin);
    int t,i,n,j,k,l,found;
    double m;
    scanf("%d", &t);
    for(i = 0 ; i < t ; i++) {
        scanf("%d", &n);
        found = 0;
        for(j = 0 ; j * j <= n ; j++) {
            for (k = 0; k * k <= (n - j * j); k++) {
                l = sqrt(n - k * k - j * j);
                m = sqrt(n - k * k - j * j);
                if(l == m) { found = 1; break; }
            }
            if(found)
                break;
        }
        if(found)
            printf("%d %d %d\n", j , k, l);
        else
            printf("-1\n");
    }
    return 0;
}
