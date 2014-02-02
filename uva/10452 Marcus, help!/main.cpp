#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define Max 10

char symbols[] = {'@', 'I', 'E', 'H', 'O', 'V', 'A', '#'};
string path[Max];
int m, n, paths = 7;
char grid[Max][Max];
bool found;

void bktk (int row, int col, int indx) {
    if(grid[row][col] == '#') {
        bool space = false;
        for (int i = 0; i < paths; i++) {
            if(space)
                printf(" ");
            space = true;
            printf("%s", path[i].c_str());
        }
        found = true;
        putchar('\n');
        return;
    }

    if( col + 1 < n and grid[row][col + 1] == symbols[indx + 1] ) {
        path[indx] = "right";
        bktk (row, col + 1, indx + 1);
        if(found) return;
    }
    if( col - 1 >= 0 and grid[row][col - 1] == symbols[indx + 1] ) {
        path[indx] = "left";
        bktk (row, col - 1, indx + 1);
        if(found) return;
    }
    if( row - 1 >= 0 and grid[row - 1][col] == symbols[indx + 1] ) {
        path[indx] = "forth";
        bktk (row - 1, col, indx + 1);
        if(found) return;
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase, x, y;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%s", &grid[i]);

        for (int j = 0; j < n; j++) {
            if(grid[m - 1][j] == '@') {
                y = j;
                break;
            }
        }
        found = false;
        bktk(m - 1, y, 0);
    }
    return 0;
}
