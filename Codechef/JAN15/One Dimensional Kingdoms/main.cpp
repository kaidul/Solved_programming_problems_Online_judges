#include <cstdio>
#include <algorithm>
#include <fstream>
#include <utility>

using namespace std;

#define MAX 100001
pair<int, int> kingdoms[MAX];

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.second < rhs.second;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int T, N, L, R;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            scanf("%d %d", &L, &R);
            kingdoms[i] = make_pair(L, R);
        }
        sort(kingdoms, kingdoms + N, cmp);
        int bombs = 1;
        int right = kingdoms[0].second;
        for(int i = 1; i < N; ++i) {
            if(kingdoms[i].first > right) {
                ++bombs;
                right = kingdoms[i].second;
            }
        }
        printf("%d\n", bombs);
    }
    return 0;
}
