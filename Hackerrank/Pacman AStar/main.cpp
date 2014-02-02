#include <bits/stdc++.h>
using namespace std;
/* Head ends here */
#define Max 40
struct point {
    int x, y;
    point() {}
    point(int r, int c) {
        x = r;
        y = c;
    }
    bool operator == (const point& a) const {
        return x == a.x and y == a.y;
    }
} source, destination;

struct wrapper {
    point p;
    int cost;
    wrapper() {}
    wrapper(point x, int y) {
        p = x;
        y = cost;
    }
    bool operator < (const wrapper& other) const {
        return cost < other.cost;
    }
};

int manhattanHeuristic(point current, point target) {
    return abs(current.x - target.x) + abs(current.y - target.y);
}

vector <point> nodeExpand, path;
priority_queue < wrapper > pQueue;
int directionX[] = {-1, 0, 0, 1};
int directionY[] = {0, -1, 1, 0};
int visited[Max][Max];
point parent[Max][Max], nothing = point(-1, -1);
bool found = false;
int row, col, nodeExplored = 0, totalPath = 0;
bool isValid(int x, int y, vector <string> grid) {
    return x >= 0 and y >= 0 and x < row and y < col and grid[x][y] != '%';
}

void AStarHelper(wrapper node, vector <string> grid) {
    if(destination == node.p) {
        found = true;
        return;
    }
    point poped = node.p, neighbour;
    for(int i = 0, n = sizeof(directionX) / sizeof(directionX[0]); i < n; ++i) {
        int x = poped.x + directionX[i], y = poped.y + directionY[i];
        neighbour = point(x, y);
        int cost = 1;
        if( isValid(x, y, grid) and !visited[x][y] ) {
            if(grid[x][y] == '.') cost = 0;
            cost += manhattanHeuristic(neighbour, destination);
            pQueue.push(wrapper(neighbour, node.cost + cost));
            parent[x][y] = poped;
            visited[x][y] = true;
        }
    }
    while( !pQueue.empty() ) {
        wrapper obj = pQueue.top();
        pQueue.pop();
        AStarHelper(obj, grid);
        if(found) return;
    }
}

void AStar( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid) {
    source = point(pacman_r, pacman_c);
    destination = point(food_r, food_c);
    row = r, col = c;
    visited[pacman_r][pacman_c] = true;
    parent[pacman_r][pacman_c] = nothing;
    AStarHelper(wrapper(source, 0), grid);
    point curr = destination;
    while(!(curr == nothing)) {
       ++totalPath;
       path.push_back(curr);
        curr = parent[curr.x][curr.y];
    }
    int distance = totalPath - 1;
    cout << distance << endl;
    for(int i = path.size() - 1; i >= 0; --i) {
        cout << path[i].x << " " << path[i].y << endl;
    }
}
/* Tail starts here */
int main(void) {
    freopen("input.txt", "r", stdin);
    int r,c, pacman_r, pacman_c, food_r, food_c;

    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;

    vector <string> grid;

    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    AStar( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}
