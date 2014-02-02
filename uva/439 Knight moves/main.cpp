#include <bits/stdc++.h>

using namespace std;

#define Max 9

int cost[Max][Max];
bool visited[Max][Max];

int dirX[]= {-2, -1, 1, 2, 2, 1, -1, -2};
int dirY[]= {-1,-2, -2, -1, 1, 2, 2, 1};

string source, dest;

struct point {
    int x, y;
    point() {}
    point(int _x, int _y) {
        x = _x, y = _y;
    }
    bool operator == (const point& A) const {
        return x == A.x and y == A.y;
    }
};

bool isValid(int x, int y) {
    return x >= 1 and x <= 8 and y >= 1 and y <= 8;
}

void bfs(point src, point des) {
    queue <point> q;
    memset(visited, false, sizeof visited);
    q.push(src);
    cost[src.x][src.y] = 0;
    visited[src.x][src.y] = true;
    int posX, posY;
    point pop;
    while( !q.empty() ) {
        pop = q.front();
        q.pop();
        if(pop == des) {
            cout<<"To get from " << source
                << " to " << dest
                << " takes " << cost[pop.x][pop.y] << " knight moves.\n";
            return;
        }
        for(int i = 0; i < 8; i++) {
            posX = pop.x + dirX[i];
            posY = pop.y + dirY[i];
            if(isValid(posX, posY) and !visited[posX][posY]) {
                visited[posX][posY] = true;
                cost[posX][posY] = cost[pop.x][pop.y] + 1;
                q.push( point(posX, posY) );
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while(cin >> source >> dest) {
        bfs( point(source[0] - 96, source[1] - '0'), point(dest[0] - 96, dest[1] - '0'));
    }
    return 0;
}
