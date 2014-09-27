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
size_t neighbours = sizeof directionX / sizeof directionX[0];
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
        return eval >= other.eval;
    }
};
priority_queue < wrapper > pQueue;

// number Of Misplaced Tiles
int numberOfMisplacedTiles(_2D &grid) {
    int cnt = 0, ret = 0;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) {
            if(grid[i][j] != cnt)
                ++ret;
            ++cnt;
        }
    return ret;
}

// Manahattan distance
map < int, pair<int ,int> > correctTile;

void preprocess(_2D &grid) {
    int cnt = 0;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) {
            correctTile[cnt] = make_pair(i, j);
            cnt++;
        }
}

int manhattanDistance(_2D &grid) {
    int cnt = 0, ret = 0;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) {
            pair<int, int> pos = correctTile[ grid[i][j] ];
            ret += ( abs(pos.first - i) + abs(pos.second - j) );
        }
    return ret;
}

pair<int, int> findEmpty(_2D &grid) {
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            if(grid[i][j] == 0)
                return make_pair(i, j);

    return make_pair(-1, -1);
}

bool isValid(int &x, int &y) {
    return x >= 0 and y >= 0 and x < k and y < k;
}

bool isGoalState(_2D &grid) {
    return numberOfMisplacedTiles(grid) == 0;
    // return manhattanDistance(grid) == 0;
}

void AStar(_2D &grid) {
    preprocess(grid);
    int moves = 0;
    int heuristic1 = numberOfMisplacedTiles(grid);
    int heuristic2 = manhattanDistance(grid);
    int eval = max(heuristic1, heuristic2) + moves;
    string cmd = string("dummy");
    source = make_pair(grid, cmd);
    visited[grid] = true;
    pQueue.push( wrapper(grid, eval, moves, cmd) );

    while(!pQueue.empty()) {
        wrapper top = pQueue.top();
        grid = top.state, cmd = top.command, moves = top.depth;
        pQueue.pop();

        if( isGoalState(grid) ) {
            destination = make_pair(grid, cmd);
            break;
        }

        _pair par = make_pair(grid, cmd);
        pair<int, int> Empty = findEmpty(grid);

        for(int i = 0; i < neighbours; ++i) {
            int x = Empty.first + directionX[i], y = Empty.second + directionY[i];

            if(isValid(x, y)) {
                swap(grid[Empty.first][Empty.second], grid[x][y]);

                if( !visited[grid] ) {
                    visited[grid] = true;
                    parent[make_pair(grid, dir[i])] = par;
                    heuristic1 = numberOfMisplacedTiles(grid);
                    heuristic2 = manhattanDistance(grid);
                    eval = max(heuristic1, heuristic2) + (moves + 1);
                    pQueue.push( wrapper(grid, eval, moves + 1, dir[i]) );
                }

                swap(grid[Empty.first][Empty.second], grid[x][y]);
            }

        }
    }

    _pair curr = destination;
    while(curr != source) {
        solution.push_back(curr.second);
        curr = parent[curr];
    }
    cout << solution.size() << endl;
    for(int i = solution.size() - 1; i >= 0; --i)
        cout << solution[i] << endl;

}

int main(void) {
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
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
