#include <bits/stdc++.h>
using namespace std;

#define Max 7

int k;
int indx[Max][Max];
#define _2D vector <vector <int> >
struct tripple {
    _2D state;
    int eval;
    string command;
    tripple() {}
    tripple(_2D grid, int cost, string cmd) {
        state = grid;
        eval = cost;
        command = cmd;
    }
    bool operator < (const tripple &other) const {
        return eval > other.eval;
    }
};
priority_queue < tripple > pQueue;
map < _2D, bool > visited;
vector <string> solution;

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

int directionX[] = {0, -1, 0, 1};
int directionY[] = {-1, 0, 1, 0};
string dir[] = {"LEFT", "UP", "RIGHT", "DOWN"};

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
pair < _2D, string > source, destination;
bool found = false;
map < pair<_2D, string>, pair<_2D, string> > parent;
void AStarHelper(_2D &grid, string cmd, int depth) {
    if( isGoalState(grid) ) {
        destination = make_pair(grid, cmd);
        found = true;
        return;
    }
    pair<int, int> empty = findEmpty(grid);
    int x, y, eval;
    _2D backup = grid;
    for(int i = 0; i < 4; ++i) {
        x = empty.first + directionX[i], y = empty.second + directionY[i];
        if(isValid(x, y)) {
            swap(grid[empty.first][empty.second], grid[x][y]);
            if( !visited[grid] ) {
                eval = depth + heuristic(grid);
                visited[grid] = true;
                parent[make_pair(grid, dir[i])] = make_pair(backup, cmd);
                pQueue.push(tripple(grid, eval, dir[i]));
//                cout << eval << endl;
            }
            swap(grid[empty.first][empty.second], grid[x][y]);
        }
    }
    while(!pQueue.empty()) {
        tripple poped = pQueue.top();
        pQueue.pop();
        AStarHelper(poped.state, poped.command, depth + 1);
        if(found) return;
    }

}

void printSolution() {
    pair < _2D, string > curr = destination;
    while(curr != source) {
        solution.push_back(curr.second);
        curr = parent[curr];
    }
    for(int i = solution.size() - 1; i >= 0; --i)
        cout << solution[i] << endl;
}

void AStar(_2D &grid) {
    visited[grid] = true;
    int depth = 0;
    int eval = depth + heuristic(grid);
    source = make_pair(grid, string(""));
    AStarHelper(grid, string(""), depth + 1);
    printSolution();
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector < vector<int> > grid(Max);
    cin >> k;
    int input;
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            cin >> input;
            grid[i].push_back(input);
        }
    }
    AStar(grid);
    return 0;
}
