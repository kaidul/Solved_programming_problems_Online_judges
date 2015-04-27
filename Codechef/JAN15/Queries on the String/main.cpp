#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX3 1000
#define MAX5 100000

/*
int query[MAX3 + 5][MAX3 + 5];
int arr[MAX3 + 5];

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();
    char ch = getchar();
    int idx = 0;
    do {
        arr[++idx] = (int)(ch - '0');
//        printf("%d\n", arr[idx]);
        query[idx][idx] = (arr[idx] % 3 == 0);
        arr[idx] += arr[idx - 1];
        ch = getchar();
    } while(ch != '\n');

    for(int i = N - 1; i > 0; i--) {
        for(int j = i + 1; j <= N; j++) {
            query[i][j] = query[i][j - 1] + query[i + 1][j] - query[i + 1][j - 1];
            query[i][j] += ((arr[j] - arr[i - 1]) % 3 == 0);
        }
    }


//    for(int i = 1; i <= N; ++i) {
//        for(int j = 1; j <= N; ++j) {
//            printf("%d ", query[i][j]);
//        }
//        puts("");
//    }

    int code, x, y;
    int prev, diff;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &code, &x, &y);
        switch(code) {
        case 1:
            prev = arr[x] - arr[x - 1];
            diff = y - prev;
            for(int k = x; k <= N; ++k) {
                arr[k] += diff;
            }
//            query[x][x] = (y % 3 == 0);
            for(int k = x; k > 0; k--) {
                for(int j = x; j <= N; j++) {
//                    printf("%d %d\n", k, j);
                    query[k][j] = query[k][j - 1] + query[k + 1][j] - query[k + 1][j - 1];
                    query[k][j] += ((arr[j] - arr[k - 1]) % 3 == 0);
                }
            }
            break;
        case 2:
            printf("%d\n", query[x][y]);
            break;
        }
    }

    return 0;
}
*/

int arr[MAX5 + 1], found[3], prev_found[3];

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();
    char ch = getchar();
    int idx = 0;
    do {
        arr[++idx] = (int)(ch - '0');
        ch = getchar();
    } while(ch != '\n');
    int code, left, right;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &code, &left, &right);
        switch(code) {
        case 1:
            arr[left] = right;
            break;
        case 2:
            int residue, ans = 0;
            for(int k = left; k <= right; ++k) {
                residue = arr[k] % 3;
                found[(residue + 0) % 3] = prev_found[0] + 1;
                found[(residue + 1) % 3] = prev_found[1];
                found[(residue + 2) % 3] = prev_found[2];
                ans += found[0];
                memcpy(prev_found, found, sizeof found);
            }
            printf("%d\n", ans);
            memset(prev_found, 0, sizeof prev_found);
            break;
        }
    }
    return 0;
}
