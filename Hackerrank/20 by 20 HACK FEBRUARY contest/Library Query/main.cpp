#include <bits/stdc++.h>

using namespace std;

#define Max 10001

int main(void) {
    freopen("input.txt", "r", stdin);
    int tcase;
    int n, q;
    int data[Max];
    int cmd;
    int x, y, k;
    cin >> tcase;
    while(tcase--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> data[i];
        }
        cin >> q;
        while(q--) {
            cin >> cmd;
            if(cmd == 0) {
                cin >> x >> y >> k;
                --x;--k;
                vector <int> v(data + x, data + y);
                sort(v.begin(), v.end());
                cout << v[k] << endl;
            } else {
                cin >> x >> k;
                --x;
                data[x] = k;
            }
        }
    }
    return 0;
}
