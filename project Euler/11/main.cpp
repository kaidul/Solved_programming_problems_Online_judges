#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int Max = -1;
    int grid[25][25];
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            cin >> grid[i][j];
        }
    }
    int product = 0;
    // roe and column products
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 17; ++j) {
            product = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
            Max = max(Max, product);
            product = grid[j][i] * grid[j + 1][i] * grid[j + 2][i] * grid[j + 3][i];
            Max = max(Max, product);
        }
    }

    // diagonal products
    for(int i = 0; i < 17; ++i) {
        for(int j = 0; j < 17; ++j) {
            product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
            Max = max(Max, product);

        }
    }
    for(int i = 3; i < 20; ++i) {
        for(int j = 0; j < 17; ++j) {
            product = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];
            Max = max(Max, product);
        }
    }
    cout << Max << endl;
    return 0;
}
