#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100001

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int pos, value, data[N];
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < n; ++i) {
        cin >> value;
        pos = (i + k) % n;
        data[pos] = value;
    }
    int query;
    while(q--) {
        cin >> query;
        cout << data[query] << endl;
    }
    return 0;
}
