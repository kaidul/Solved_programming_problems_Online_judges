#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int c, n, m, t, pos;
    int T[1440], ans;

    scanf("%d", &c);

    for(int tc = 0; tc < c; tc++) {
        scanf("%d %d %d", &n, &t, &m);

        for(int i = 0; i < m; i++) scanf("%d", &T[i]);
        //sort(T,T+m);

        ans = pos = 0;

        if(m % n) {
            ans = T[m % n - 1] + 2 * t;
            pos = m % n;
        } else {
            ans = T[n - 1] + 2 * t;
            pos = n;
        }

        for(; pos < m; pos += n) {
            if(ans >= T[pos + n - 1]) ans += 2*t;
            else ans = T[pos + n - 1] + 2 * t;
        }

        ans -= t;

        printf("%d %d\n", ans, (m + n - 1) / n);
    }

    return 0;
}
