#include <bits/stdc++.h>
using namespace std;
/* Head ends here */
#define N 5
#define infinity (1 << 30)
vector < pair<int, int> > dirty;
int start = -1;
int frequency[N][N];

void findAllDirts(int posr, int posc, vector <string> board) {
    int beginX = posr - 1 >= 0 ? posr - 1 : 0;
    int endX = posr + 1 < N ? posr + 1 : N - 1;
    int beginY = posc - 1 >= 0 ? posc - 1 : 0;
    int endY = posc + 1 < N ? posc + 1 : N - 1;
    for(int i = beginX; i <= endX; ++i) {
        for(int j = beginY; j <= endY; ++j) {
            if(board[i][j] == 'd') {
                dirty.push_back( make_pair(i, j) );
            }
        }
    }
}

void nearestDirt(int x, int y) {
    int best = infinity;
    for(int i = 0, n = dirty.size(); i < n; ++i) {
        pair <int, int> d = dirty[i];
        int dist = abs(d.first - x) + abs(d.second - y);
        if( dist < best) {
            best = dist;
            start = i;
        }
    }
}

bool compare(pair <int, int> a, pair <int, int> b) {
    return frequency[a.first][a.second] < frequency[b.first][b.second];
}

void printNextMove(int x, int y) {
    if(dirty.size() > 0) {
        pair<int, int> d = dirty[start];
        int dirtX = d.first;
        int dirtY = d.second;
        if(x == dirtX and y == dirtY) {
            dirty.erase(dirty.begin() + start);
            start = -1;
            cout << "CLEAN";
        } else if(x > dirtX) {
            ++frequency[x - 1][y];
            cout << "UP";
        } else if(y > dirtY) {
            ++frequency[x][y - 1];
            cout << "LEFT";
        } else if(x < dirtX) {
            ++frequency[x + 1][y];
            cout << "DOWN";
        }   else {
            ++frequency[x][y + 1];
            cout << "RIGHT";
        }
    } else {
        vector < pair<int, int> > direction;
        if(x > 0) direction.push_back(make_pair(x - 1, y));
        if(y > 0) direction.push_back(make_pair(x, y - 1));
        if(x < N - 1) direction.push_back(make_pair(x + 1, y));
        if(y < N - 1) direction.push_back(make_pair(x, y + 1));
        sort(direction.begin(), direction.end(), compare);
        pair <int, int> state = direction[0];
        int diffX = state.first - x, diffY = state.second - y;
        ++frequency[state.first][state.second];
        if(diffX > 0) cout << "DOWN";
        else if(diffX < 0) cout << "UP";
        else if(diffY > 0) cout << "RIGHT";
        else if(diffY < 0) cout << "LEFT";
    }
    cout << "\n";
}

void next_move(int posr, int posc, vector <string> board) {
    findAllDirts(posr, posc, board);
    if(start == -1) {
        nearestDirt(posr, posc);
    }
    printNextMove(posr, posc);
}

/* Tail starts here */
int main(void) {
    freopen("input.txt", "r", stdin);
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    memset(frequency, 0, sizeof frequency);
    next_move(pos[0], pos[1], board);
    return 0;
}
