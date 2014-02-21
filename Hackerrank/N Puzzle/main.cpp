#include <bits/stdc++.h>
using namespace std;

#define Max 10
#define _2D vector <vector <int> >
#define _pair pair < _2D, string>

int k;
map < _2D, bool > visited;
vector <string> solution;
_pair source, destination;
bool found = false;
map < _pair, _pair > parent;
int directionX[] = {0, -1, 0, 1};
int directionY[] = {-1, 0, 1, 0};
string dir[] = {"LEFT", "UP", "RIGHT", "DOWN"};
struct wrapper {
    _2D state;
    int eval;
    int depth;
    string command;
    wrapper() {}
    wrapper(_2D grid, int cost, int d, string cmd) {
        state = grid, eval = cost, depth = d, command = cmd;
    }
    bool operator < (const wrapper &other) const {
        if(eval == other.eval) return depth > other.depth;
        return eval > other.eval;
    }
};
priority_queue < wrapper > pQueue;

// number Of Misplaced Tiles
int heuristic(_2D &grid) {
    int cnt = 0, ret = 0;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) {
            if(grid[i][j] != cnt) ++ret;
            ++cnt;
        }
    return ret;
}

pair<int ,int> findEmpty(_2D &grid) {
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            if(grid[i][j] == 0) return make_pair(i, j);
}

bool isValid(int x, int y) {
    return x >= 0 and y >= 0 and x < k and y < k;
}

bool isGoalState(_2D &grid) {
    return heuristic(grid) == 0;
}

void printGrid(_2D &grid) {
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void AStarHelper(_2D &grid, string cmd, int depth) {
    if( isGoalState(grid) ) {
        destination = make_pair(grid, cmd);
//        printGrid(grid);
        found = true;
        return;
    }
    pair<int, int> empty = findEmpty(grid);
    int x, y, eval;
    _pair par = make_pair(grid, cmd);
    for(int i = 0; i < 4; ++i) {
        x = empty.first + directionX[i], y = empty.second + directionY[i];
        if(isValid(x, y)) {
            swap(grid[empty.first][empty.second], grid[x][y]);
            if( !visited[grid] ) {
                eval = heuristic(grid) + depth + 1;
                visited[grid] = true;
                parent[make_pair(grid, dir[i])] = par;
//                printGrid(poped.state);
                pQueue.push( wrapper(grid, eval, depth + 1, dir[i]) );
            }
            swap(grid[empty.first][empty.second], grid[x][y]);
        }
    }
    while(!pQueue.empty()) {
        wrapper poped = pQueue.top();
        pQueue.pop();
        cout << poped.depth << endl;
        printGrid(poped.state);
        AStarHelper(poped.state, poped.command, poped.depth);
        if(found) return;
    }

}

void printSolution() {
    _pair curr = destination;
    while(curr != source) {
        solution.push_back(curr.second);
        curr = parent[curr];
    }
    cout << solution.size() << endl;
    for(int i = solution.size() - 1; i >= 0; --i)
        cout << solution[i] << endl;
}

void AStar(_2D &grid) {
    visited[grid] = true;
    int depth = 0;
    int eval = depth + heuristic(grid);
    source = make_pair(grid, string(""));
    AStarHelper(grid, string(""), depth);
    printSolution();
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    _2D grid(Max);
    cin >> k;
    int input;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) {
            cin >> input;
            grid[i].push_back(input);
        }

    AStar(grid);
    return 0;
}
