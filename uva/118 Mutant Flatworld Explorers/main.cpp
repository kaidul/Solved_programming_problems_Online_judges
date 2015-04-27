#include <cstring>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX 55
int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};
char dir[] = {'N', 'E', 'S', 'W'};
bool bad[MAX][MAX];
int m, n, x0, y0;
char d0;

bool nextState(int& x1, int& y1, char& d1, int i, string cmd) {
    if (i >= cmd.size()) return false;
    if (cmd[i] != 'F') d1 = (d1 + (cmd[i] == 'R' ? 1 : 3)) % 4;
    if (cmd[i] == 'F') {
        int x2 = x1 + dx[d1], y2 = y1 + dy[d1];
        if (x2 >= 0 && x2 <= n && y2 >= 0 && y2 <= m) x1 = x2, y1 = y2;
        else if(!bad[x1][y1]) return bad[x1][y1] = true;
    }
    return nextState(x1, y1, d1, i + 1, cmd);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    unordered_map<char, int> Map;
    Map['N'] = 0;
    Map['E'] = 1;
    Map['S'] = 2;
    Map['W'] = 3;
    memset(bad, false, sizeof bad);
    cin >> n >> m;
    string cmd;
    while (cin >> x0 >> y0 >> d0 >> cmd) {
        d0 = Map[d0];
        bool lost = nextState(x0, y0, d0, 0, cmd);
        printf("%d %d %c", x0, y0, dir[d0]);
        cout << (lost ? " LOST" : "") << endl;
    }
    return 0;
}
