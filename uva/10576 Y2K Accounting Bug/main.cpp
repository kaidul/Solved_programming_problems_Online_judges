#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;


int s, d;
long long best;
vector<int> vals;

void solve() {
    if (vals.size() > 4) {
        int sum = 0;
        // last 5
        for (int i = 0; i < 5; i++) {
            sum += vals[vals.size() - 1 - i];
        }

        if (sum >= 0) {
            return;
        }
    }

    if (vals.size() == 12) {
        int sum = 0;
        for (int i = 0; i < 12; i++) {
            sum += vals[i];
        }
        best = max(best, sum);
        return;
    }

    vals.push_back(s);
    solve();
    vals.pop_back();
    vals.push_back(d);
    solve();
    vals.pop_back();
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (cin >> s >> d) {
        d = -d;
        best = -1;
        solve();

        if (best == -1) {
            cout << "Deficit" << endl;
        } else {
            cout << best << endl;
        }
    }

    return 0;
}
