#include <cstdio>
#include <set>
#include <utility>
#include <cmath>
#include <iostream>
using namespace std;

bool alldiff(int n, int m) {
    if (n > 99999)
        return false;

    int c, mask = 0;
    // n
    for (int i = 0; i < 5; i++) {
        c = (int) ( n / pow(10, i) ) % 10;
        // bujhini
        if ((mask >> c) % 2)
            return false;
        mask |= 1 << c;
        //
    }
    // m
    for (int i = 0; i < 5; i++) {
        c = (int) (m / pow(10, i)) % 10;
        if ((mask >> c) % 2)
            return false;
        mask |= 1 << c;
    }

    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
    #endif
    int n, count = 0;
    while (scanf("%d", &n), n) {
        int num, denum;
        bool found = false;
        count++;
        if (count > 1)
            printf("\n");

        for (denum = 1234; denum < 50000; denum++) {
            num = denum * n;
            if (alldiff(num, denum)) {
                printf("%05d / %05d = %d\n", num, denum, n);
                found = true;
            }
        }
        if (!found)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
