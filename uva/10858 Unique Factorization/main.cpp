#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
using namespace std;
#define READ(f) freopen(f, "r", stdin)


vector< deque<int> > result;
deque<int> q;

void solve(int n, int div) {
    for (int i = div; i * i <= n; i++) {
        if (n % i == 0) {
            q.push_back(i);
            solve(n / i, i);
            q.pop_back();
        }
    }
    q.push_back(n);
    result.push_back(q);
    q.pop_back();
}


int main(void) {
    READ("input.txt");
    int n;

    while (cin >> n) {

        if (n == 0)
            break;

        result.clear();
        q.clear();

        solve(n, 2);

        cout << result.size() - 1 << endl;
        for (int i = 0, sz = result.size() - 1; i < sz; i++) {
            for (int j = 0, sz2 = result[i].size(); j < sz2; j++) {
                if (j > 0)
                    cout << " ";
                cout << result[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
