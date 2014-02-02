#include <bits/stdc++.h>

using namespace std;

int getGCD(int a, int b) {
    return b == 0 ? a : getGCD(b, a % b);
}

bool isCoprime(int a, int b) {
    return getGCD(a, b) == 1;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int caseNo = 0;
    int sqrtn, lower, m, p, q, temp, phi, n, e, d;
    while( cin >> n >> e >> d ) {
        if(n == 0 and e == 0 and d == 0)
            break;
        temp = e * d;
//        lower = temp / n;
        for(int i = 1; ; i++) {
            if(temp % i == 1) {
                phi = (temp - 1) / i ;
                if( isCoprime(phi, e) and phi < n)
                    break;
            }
        }
        m = (n - phi + 1) / 2;
        sqrtn = sqrt(pow(m, 2) - n);
        p = m - sqrtn, q = m + sqrtn;
        printf("Case #%d: %d %d\n", ++caseNo, p, q);
    }
    return 0;
}
