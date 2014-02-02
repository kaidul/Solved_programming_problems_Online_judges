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
vector <point> nodeExpand, path;
stack < point > Stack;
int directionX[] = {-1, 0, 0, 1};
int directionY[] = {0, -1, 1, 0};
int visited[Max][Max];
point parent[Max][Max], nothing = point(-1, -1);
bool found = false;
int row, col, nodeExplored = 0, totalPath = 0;
bool isValid(int x, int y, vector <string> grid) {
    return x >= 0 and y >= 0 and x < row and y < col and grid[x][y] != '%';
}

void dfsHelper(point node, vector <string> grid) {
    ++nodeExplored;
    nodeExpand.push_back(node);
    if(destination == node) {
        found = true;
        return;
    }
    point poped = node, neighbour;
    for(int i = 0, n = sizeof(directionX) / sizeof(directionX[0]); i < n; ++i) {
        int x = node.x + directionX[i], y = node.y + directionY[i];
        neighbour = point(x, y);
        if( isValid(x, y, grid) and !visited[x][y] ) {
            Stack.push(neighbour);
            parent[x][y] = node;
            visited[x][y] = true;
        }
    }
    while( !Stack.empty() ) {
        poped = Stack.top();
        Stack.pop();
        dfsHelper(poped, grid);
        if(found) return;
    }
}

void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid) {
    source = point(pacman_r, pacman_c);
    destination = point(food_r, food_c);
    row = r, col = c;
    visited[pacman_r][pacman_c] = true;
    parent[pacman_r][pacman_c] = nothing;
    dfsHelper(source, grid);
    cout << nodeExplored << endl;
    for(int i = 0, n = nodeExpand.size(); i < n; ++i) {
        cout << nodeExpand[i].x << " " << nodeExpand[i].y << endl;
    }

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

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}
