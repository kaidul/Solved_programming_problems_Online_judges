#include <bits/stdc++.h>
using namespace std;

#define Max 4001
map <int, bool> rest;
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    int a, b, c, d;
    vector <int> A, B, C, D;
    while( ~scanf("%d", &n) ) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            A.push_back(a);
            B.push_back(b);
            C.push_back(c);
            D.push_back(d);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                rest[ A[i] + B[j] ] = true;
            }
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if( rest[-(C[i] + D[j])] )
                    ++count;
            }
        }
        printf("%d\n", count);
        A.clear();
        B.clear();
        C.clear();
        D.clear();
        rest = map <int, bool> ();
    }
    return 0;
}
