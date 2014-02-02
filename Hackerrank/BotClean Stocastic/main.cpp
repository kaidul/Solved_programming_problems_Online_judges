#include <bits/stdc++.h>
using namespace std;
/* Head ends here */
pair <int, int> distance_to_dirt(int posr, int posc, vector <string> board) {
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            if(board[i][j] == 'd')
                return make_pair(posr - i, posc - j);
}

void nextMove(int posr, int posc, vector <string> board) {
    pair <int, int> d = distance_to_dirt(posr, posc, board);
    int x_dist, y_dist;
    x_dist = d.first, y_dist = d.second;

    if(x_dist == 0 and y_dist == 0) {
        cout << "CLEAN";
    } else if (y_dist == 0) {
        if(x_dist > 0) cout << "UP";
        else cout << "DOWN";
    } else {
        if(y_dist > 0) cout << "LEFT";
        else cout << "RIGHT";
    }

    cout << "\n";
}
/* Tail starts here */
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0; i<5; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    nextMove(pos[0], pos[1], board);
    return 0;
}
