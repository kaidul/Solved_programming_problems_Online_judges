#include <bits/stdc++.h>

using namespace std;

#define Max 30

int dimension;
char a [Max][Max];

struct point {
    int x, y;
    point() {}
    point(int _x, int _y) {
        x = _x, y = _y;
    }
};
queue <point> q;

int dirX[] = {0, -1, -1, -1, 0, 1, 1, 1},
           dirY[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void dfs (int x, int y) {
    q.push (point(x, y));
    int posX, posY;
    while ( !q.empty () ) {
        point cordinate = q.front ();
        x = cordinate.x, y = cordinate.y;
        q.pop ();
        for(int i = 0, n = sizeof(dirX) / sizeof(dirX[0]); i < n; ++i) {
            posX = x + dirX[i], posY = y + dirY[i];
            if ( a[posX][posY] == '1' ) {
                q.push (point(posX, posY));
                a[posX][posY] = '0';
            }
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    int caseNo = 0;

    while ( scanf ("%d", &dimension) != EOF ) {
        getchar();

        for ( int i = 0; i < dimension; i++ )
            scanf("%s", a [i]);

        int count = 0;

        for ( int i = 0; i < dimension; i++ ) {
            for ( int j = 0; j < dimension; j++ ) {
                if ( a [i] [j] == '1' ) {
                    dfs (i, j);
                    count++;
                }
            }
        }

        printf ("Image number %d contains %d war eagles.\n",
                ++caseNo, count);
    }

    return 0;
}
