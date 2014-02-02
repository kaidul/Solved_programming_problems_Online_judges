#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
/* Head ends here */
pair <int, int> p, m;

void nextMove(int n, int r, int c, vector <string> grid) {
    string direction[] = {"UP\n", "RIGHT\n", "DOWN\n", "LEFT\n"};
    int botX = p.first, botY = p.second, x = m.first, y = m.second;
    if(x > botX) {
        cout << direction[0];
//        ++botX;
    } else if(x < botX) {
        cout << direction[2];
//        --botX;
    }
    else if(botY < y) {
        cout << direction[3];
//        ++botY;
    } else if(botY > y) {
        cout << direction[1];
//        --botY;
    }
}
/* Tail starts here */
int main(void) {
    freopen("input.txt", "r", stdin);
    int n, r, c;
    vector <string> grid;
    cin >> n;
    cin >> r;
    cin >> c;
    m = make_pair(r, c);
    string s;
    size_t foundP;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        foundP = s.find('p');
        if(foundP != string::npos) p = make_pair(i, foundP);
        grid.push_back(s);
    }
    nextMove(n, r, c, grid);
    return 0;
}
