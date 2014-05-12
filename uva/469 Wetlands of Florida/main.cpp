#include <bits/stdc++.h>

using namespace std;

#define Max 105

int m, n, cnt;
char a[Max][Max];
bool visited[Max][Max];

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

void bfs (int x, int y) {
    q.push (point(x, y));
    visited[x][y] = true, ++cnt;
    int posX, posY;
    while (!q.empty()) {
        point cordinate = q.front();
        x = cordinate.x, y = cordinate.y;
        q.pop();
        for(int i = 0, N = sizeof(dirX) / sizeof(dirX[0]); i < N; ++i) {
            posX = x + dirX[i], posY = y + dirY[i];
            if (isValid(posX, posY) and a[posX][posY] == 'W' and !visited[posX][posY]) {
                q.push (point(posX, posY));
                visited[posX][posY] = true;
                ++cnt;
            }
        }
    }
}

void dfs (int r, int c) {
    if (!isValid(r, c) or a[r][c] == 'L' or visited[r][c])
        return;
    visited[r][c] = true;
    ++cnt;

    for(int i = 0, N = sizeof(dirX) / sizeof(dirX[0]); i < N; ++i)
        dfs (r + dirX[i], c + dirY[i]);
}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int tcase, r, c;
    char input[Max];
    scanf("%d", &tcase);
    getchar();
    getchar();
    bool blank = false;
    while(tcase--) {
        if(blank) printf("\n");
        blank = true;
        m = n = 0;
        while(gets(input) and strlen(input) > 0) {
            if(input[0] == 'L' or input[0] == 'W') {
                n = strlen(input);
                strcpy(a[m++], input);
            } else {
                sscanf(input, "%d %d", &r, &c);
                cnt = 0;
                memset(visited, false, sizeof visited);
//                bfs(r - 1, c - 1);
                dfs(r - 1, c - 1);
                printf("%d\n", cnt);
            }
        }
    }

    return 0;
}
