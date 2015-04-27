#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0
#define MAXN 1025
#define SEG_TREE 0

int n, m;

#if SEG_TREE // Segment tree should yield TLE
vector<int> treeNode;

void init(int a, int b) {
    n = a, m = b;
    const int SIZE = ceil(pow(4, log((double) MAXN * MAXN) / log(4.0) + 1) - 1) / 3;
    treeNode.clear();
    treeNode.resize(SIZE, 0);
}

int query(int node, int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2) {
    if(a1 > x2 or b1 > y2 or a2 < x1 or b2 < y1 or x1 > x2 or y1 > y2) {
        return 0;
    }
    if(a1 <= x1 and a2 >= x2 and b1 <= y1 and b2 >= y2) {
        return treeNode[node];
    }
    int sum = 0;
    sum += query(4 * node - 2, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, a1, b1, a2, b2);
    sum += query(4 * node - 1, (x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2, a1, b1, a2, b2);
    sum += query(4 * node + 0, x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2, a1, b1, a2, b2);
    sum += query(4 * node + 1, (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2, a1, b1, a2, b2);

    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    return query(1, 1, 1, n, m, x1, y1, x2, y2);
}

int update(int node, int x1, int y1, int x2, int y2, int x, int y, int value) {
    if(x1 > x2 or y1 > y2) return 0;
    if(x > x2 or x < x1 or y > y2 or y < y1) return treeNode[node];
    if(x1 == x2 and y1 == y2 and x1 == x and y1 == y) {
        return treeNode[node] = value;
    }
    int sum = 0;
    sum += update(4 * node - 2, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, x, y, value);
    sum += update(4 * node - 1, (x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2, x, y, value);
    sum += update(4 * node + 0, x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2, x, y, value);
    sum += update(4 * node + 1, (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2, x, y, value);
    return treeNode[node] = sum;
}

int update(int x, int y, int value) {
    return update(1, 1, 1, n, m, x, y, value);
}
#else // BIT
int bit2D[MAXN][MAXN];
int data[MAXN][MAXN];

void init(int a, int b) {
    n = a, m = b;
    memset(data, 0, sizeof(data));
    memset(bit2D, 0, sizeof(bit2D));
}

void updateUtils(int x, int y, int val) {
    int y1;
    while(x <= n) {
        y1 = y;
        while(y1 <= m) {
            bit2D[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int read(int x, int y) {
    int sum = 0, y1;
    while(x > 0) {
        y1 = y;
        while(y1 > 0) {
            sum += bit2D[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    int result = read(x2, y2);
    result -= read(x1 - 1, y2);
    result -= read(x2, y1 - 1);
    result += read(x1 - 1, y1 - 1);
    return result;
}

void update(int x, int y, int value) {
    updateUtils(x, y, -data[x][y] + value);
    data[x][y] = value;
}

#endif

int main() {
#if DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    freopen("output.txt", "w", stdout);
#endif // DEBUG
    int tcase;
    int N;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &N);
        init(N, N);
        char cmd[30];
        int x1, x2, y1, y2;
        int x, y, value;
        while(scanf("%s", &cmd)) {
            if(!strcmp(cmd, "SET")) {
                scanf("%d %d %d", &x, &y, &value);
                x++, y++;
                update(x, y, value);
            } else if(!strcmp(cmd, "SUM")) {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                printf("%d\n", query(x1, y1, x2, y2));
            } else {
                break;
            }
        }
        puts("");
    }
    return 0;
}
