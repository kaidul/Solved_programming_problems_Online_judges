#include <bits/stdc++.h>

using namespace std;
/**
can be also solvable by TSP
The salesman(bot) has to visit ('clean') some towns('dirty areas') travelling minimum distance (minimum moves)
**/

/* Head ends here */
#define N 5
#define infinity (1 << 30)
vector < pair<int, int> > dirty;
int start = -1;
bool dp = false;

void findAllDirts(vector <string> board) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
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

void printNextMove(int x, int y) {
    pair<int, int> d = dirty[start];
    int dirtX = d.first;
    int dirtY = d.second;
    if(x == dirtX and y == dirtY) {
        dirty.erase(dirty.begin() + start);
        start = -1;
        cout << "CLEAN";
    } else if(x > dirtX) {
        cout << "UP";
    } else if(y > dirtY) {
        cout << "LEFT";
    } else if(x < dirtX) {
        cout << "DOWN";
    }   else cout << "RIGHT";
    cout << "\n";
}

void next_move(int posr, int posc, vector <string> board) {
    if( !dp ) {
        findAllDirts(board);
        dp = true;
    }
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
    next_move(pos[0], pos[1], board);
    return 0;
}
