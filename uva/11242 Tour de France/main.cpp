#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int front[10], nFront, rear[10], nRear;
double ratio[100];
int ratioI;
double maxSpread;

int main() {
    while (cin >> nFront) {
        if (nFront == 0)
            break;
        cin >> nRear;
        for (int i = 0; i < nFront; ++i)
            cin >> front[i];
        for (int i = 0; i < nRear; ++i)
            cin >> rear[i];

        ratioI = 0;
        for (int i = 0; i < nFront; ++i)
            for (int j = 0; j < nRear; ++j)
                ratio[ratioI++] = 1.0 * rear[j] / front[i];
        sort(&ratio[0], &ratio[ratioI]);

        maxSpread = 0;
        for (int i = 0; i < ratioI - 1; ++i)
            maxSpread = max(maxSpread, ratio[i + 1] / ratio[i]);

        cout << fixed << setprecision(2) << round(maxSpread * 100) / 100 << endl;
    }
    return 0;
}
