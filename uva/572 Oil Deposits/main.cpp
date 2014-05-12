#include <bits/stdc++.h>

using namespace std;

#define Max 105

int m, n;
char a[Max][Max];

struct point {
    int x, y;
    point(): x(), y() {}
    point(int a, int b): x(a), y(b) {}
};
queue <point> q;

int dirX[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dirY[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool isValid(int x, int y) {
    return x < m and x >= 0 and y < n and y >= 0;
}

void dfs (int x, int y) {
    q.push (point(x, y));
    int posX, posY;
    while (!q.empty()) {
        point cordinate = q.front();
        x = cordinate.x, y = cordinate.y;
        q.pop();
        for(int i = 0, n = sizeof(dirX) / sizeof(dirX[0]); i < n; ++i) {
            posX = x + dirX[i], posY = y + dirY[i];
            if(isValid(posX, posY)) {
                if ( a[posX][posY] == '@' ) {
                    q.push (point(posX, posY));
                    a[posX][posY] = '*';
                }
            }
        }
    }
}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int caseNo = 0;

    while (scanf ("%d %d", &m, &n)) {
        if(!m) break;
        getchar();
        for ( int i = 0; i < m; i++ ) scanf("%s", a[i]);
        int count = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( a[i][j] == '@' ) {
                    dfs (i, j);
                    count++;
                }
            }
        }

        printf ("%d\n", count);
    }

    return 0;
}
