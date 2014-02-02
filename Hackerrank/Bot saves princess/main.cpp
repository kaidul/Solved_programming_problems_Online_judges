#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
/* Head ends here */
pair <int, int> p, m;
void displayPathtoPrincess(int n, vector <string> grid) {
    string direction[] = {"UP\n", "RIGHT\n", "DOWN\n", "LEFT\n"};
    int botX = p.first, botY = p.second, x = m.first, y = m.second;
    while(botX != x and botY != y) {
        if(x > botX) {
            cout << direction[0];
            ++botX;
        } else if(x < botX) {
            cout << direction[2];
            --botX;
        }
        if(botY < y) {
            cout << direction[3];
            ++botY;
        } else if(botY > y) {
            cout << direction[1];
            --botY;
        }
    }
}
/* Tail starts here */
int main(void) {
    freopen("input.txt", "r", stdin);
    int n;
    vector <string> grid;
    cin >> n;
    string s;
    size_t foundP, foundM;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        foundP = s.find('p');
        if(foundP != string::npos) p = make_pair(i, foundP);
        foundM = s.find('m');
        if(foundM != string::npos) m = make_pair(i, foundM);
        grid.push_back(s);
    }
    displayPathtoPrincess(n, grid);

    return 0;
}
