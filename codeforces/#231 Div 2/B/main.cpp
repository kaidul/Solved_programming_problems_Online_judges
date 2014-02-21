#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <bitset>
#include <complex>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int a[1000010], res[1000010];

void update(int n) {
    for (int i = n-1; i >= 0; i--)
        if (a[i] < res[i]) break;
        else if (a[i] > res[i]) return;
    memcpy(res, a, sizeof(a));
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) res[i] = 10;
    for (int dig = 1; dig <= 9; dig++) {
        a[0] = dig;
        int carry = 0;
        for (int i = 0; i < n-1; i++) {
            a[i + 1] = (a[i] * m + carry) % 10;
            carry = (a[i] * m + carry) / 10;
        }
        if (a[n-1] == 0 or a[n-1]*m+carry != a[0] or a[n-1]*m+carry >= 10)
            continue;
        update(n);
    }
    if (res[0] == 10) cout << "Impossible" << endl;
    else {
        for (int i = n-1; i >= 0; i--) cout << res[i];
        cout << endl;
    }
    return 0;
}
