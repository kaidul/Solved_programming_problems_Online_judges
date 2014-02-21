#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

i64 largest_prime_factor(i64 n) {
    i64   largest_factor = 1;
    i64   div = n;

    /* remove any factors of 2 first */
    while (div % 2 == 0) {
        largest_factor = 2;
        div /= 2;
    }

    /* now look at odd factors */
    i64   p = 3;
    while (div != 1) {
        while (div % p == 0) {
            largest_factor = p;
            div /= p;
        }
        p += 2;
    }

    return largest_factor;
}

int main(void) {
    i64   factor;
    factor = largest_prime_factor(600851475143);
    cout << factor << endl;
    return 0;
}
