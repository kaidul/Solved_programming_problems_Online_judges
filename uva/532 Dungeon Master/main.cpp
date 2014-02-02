#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define Max 50

char graph[Max][Max][Max];
int dist[Max][Max][Max];
bool visited[Max][Max][Max];
//char color[Max][Max][Max];

int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
int dl[] = {0, 0, 0, 0, 1, -1};

int l, r, c;
int startL, startR, startC;
int endL, endR, endC;

bool isValid(int level, int row, int col) {
    return level >= 0 and level < l and row >= 0 and row < r and col >= 0 and col < c;
}

void bfs() {
    int i, j, k, _l, _r, _c;
    int level, row, col;

    for (i = 0; i < l; ++i) {
        for (j = 0; j < r; ++j) {
            for (k = 0; k < c; ++k) {
                dist[i][j][k] = INF;
                visited[i][j][k] = false;
//                color[i][j][k] = 'w';
            }
        }
    }
//    memset(dist, INF, sizeof dist);
//    memset(visited, false, sizeof visited);

//    color[startL][startR][startC] = 'g';
    visited[startL][startR][startC] = true;
    dist[startL][startR][startC] = 0;

    queue <int> q;
    q.push(startL);
    q.push(startR);
    q.push(startC);

    while (!q.empty()) {
        _l = q.front();
        q.pop();
        _r = q.front();
        q.pop();
        _c = q.front();
        q.pop();

        for (j = 0; j < 6; ++j) {
            level = _l + dl[j];
            row = _r + dr[j];
            col = _c + dc[j];

            if (isValid(level, row, col)) {
                if (!visited[level][row][col] and graph[level][row][col] != '#') {
//                if (color[level][row][col] == 'w' and graph[level][row][col] != '#') {
                    visited[level][row][col] = true;
//                    color[level][row][col] = 'g';
                    dist[level][row][col] = dist[_l][_r][_c] + 1;
                    q.push(level);
                    q.push(row);
                    q.push(col);
                }
            }
        }
//        color[_l][_r][_c] = 'b';
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    while (cin >> l >> r >> c) {
        if (!l and !r and !c) break;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    cin >> graph[i][j][k];
                    if (graph[i][j][k] == 'S')
                        startL = i, startR = j, startC = k;
                    if (graph[i][j][k] == 'E')
                        endL = i, endR = j, endC = k;
                }
            }
        }
        bfs();
        if (dist[endL][endR][endC] == INF)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << dist[endL][endR][endC] << " minute(s)." << endl;
    }
    return 0;
}
