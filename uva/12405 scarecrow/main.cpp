#include <cstdio>

using namespace std;

/*
This is a greedy problem, you simply have to scan from left to right and every time you find a ‘.’ in a square, put a scarecrow in the square to its right. (I thought it was minimum vertex cover problem :p )
*/

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T, N;
    char s[100];

    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        scanf("%d %s", &N, s);
        int ans = 0;
        for(int i = 0; i < N;) {
            if(s[i] == '#') ++i;
            else {
                ++ans;
                i += 3;
            }
        }
        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
