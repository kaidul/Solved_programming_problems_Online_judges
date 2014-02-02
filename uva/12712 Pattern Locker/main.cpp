#include<bits/stdc++.h>

#define ii long long int
#define mod 10000000000007LL

ii cal(ii tot, ii rem, ii ans) {
    if(rem <= 0) return 0;
    ii ret = ( (ans % mod) * (tot % mod) );
    return (ret + cal(tot - 1, rem - 1, ret) % mod) % mod;
}

int L,lo,hi;

int main(void) {
//    freopen("input.txt", "r", stdin);
    int test, cas = 0;
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d %d", &L, &lo, &hi);
        printf("Case %d: ", ++cas);
        ii ans = ( cal((ii)L * L, (ii)hi, 1L) - cal((ii)L * L, (ii)lo - 1L, 1L) ) % mod;
        if(ans < 0) ans += mod;
        printf("%lld\n", ans);
    }
    return 0;
}
