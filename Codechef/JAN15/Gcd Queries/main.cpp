#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

using namespace std;

#define MAX5 100001
int N, A[MAX5]/*, B[MAX5]*/;
int segTree[3 * MAX5];

int suffix[MAX5], prefix[MAX5];

void buildSegTree(int start, int end, int node) {
    // if(start > end) return;
    if(start == end) {
        segTree[node] = A[start];
        return;
    }
    int mid = start + (end - start) / 2;
    int leftIndx = node << 1, rightIndx = leftIndx | 1;
    buildSegTree(start, mid, leftIndx);
    buildSegTree(mid + 1, end, rightIndx);
    segTree[node] = gcd(segTree[leftIndx], segTree[rightIndx]);
}

int querySegTree(int start, int end, int node, int L, int R) {
    if(start > end or start > R or end < L) return -1;
    if(start >= L and end <= R) return segTree[node];
    int mid = start + (end - start) / 2;
    int leftIndx = node << 1, rightIndx = leftIndx | 1;
    int retLeft = querySegTree(start, mid, leftIndx, L, R);
    int retRight = querySegTree(mid + 1, end, rightIndx, L, R);
    if(retLeft == -1) return retRight;
    if(retRight == -1) return retLeft;
    return gcd(retLeft, retRight);
}

int query(int L, int R) {
    int first = querySegTree(0, N - 1, 1, 0, L - 1);
    int second = querySegTree(0, N - 1, 1, R + 1, N - 1);
    if(first == -1) return second;
    if(second == -1) return first;
    return gcd(first, second);
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int T, Q, L, R;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &Q);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        /*
        for(int i = 0; i < Q; ++i) {
            scanf("%d %d", &L, &R);
            if(L == 1 and R == N) {
                printf("0\n");
                continue;
            }
            L--, R--;
            int result, offset;
            if(L == 0) {
                result = A[R + 1];
                offset = R + 2;
            } else {
                result = A[0];
                offset = R + 1;
                for(int j = 1; j < L; ++j) {
                    result = gcd(result, A[j]);
                }
            }
            for(int j = offset; j < N; ++j) {
                result = gcd(result, A[j]);
            }
            printf("%d\n", result);
        }
        */
        /*
        for(int i = 0; i < Q; ++i) {
            scanf("%d %d", &L, &R);
            if(L == 1 and R == N) {
                printf("0\n");
                continue;
            }
            L--, R--;
            int k = 0;
            for(int j = 0; j < L; ++j, ++k) B[k] = A[j];
            for(int j = R + 1; j < N; ++j, ++k) B[k] = A[j];
            sort(B, B + k);
            int result = B[0];
            for(int j = 1; j < k; ++j) {
                result = gcd(result, B[j]);
            }
            printf("%d\n", result);
        }
        */
        /* using segment tree */
        /*
        buildSegTree(0, N - 1, 1);
        for(int i = 0; i < Q; ++i) {
            scanf("%d %d", &L, &R);
            if(L == 1 and R == N) {
                printf("0\n");
                continue;
            }
            L--, R--;
            printf("%d\n", query(L, R));
        }
        */
        prefix[0] = A[0];
        suffix[N - 1] = A[N - 1];
        for(int i = 1; i < N; ++i) {
            prefix[i] = gcd(prefix[i - 1], A[i]);
        }
        for(int i = N - 2; i >= 0; --i) {
            suffix[i] = gcd(suffix[i + 1], A[i]);
        }
        for(int i = 0; i < Q; ++i) {
            scanf("%d %d", &L, &R);
            if(L == 1 and R == N) {
                printf("0\n");
                continue;
            }
            L--, R--;
            printf("%d\n", gcd(prefix[L - 1], suffix[R + 1]));
        }
    }
    return 0;
}
