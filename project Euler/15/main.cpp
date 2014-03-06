#include <iostream>

using namespace std;

// http://www.mathblog.dk/project-euler-15/
int main() {
    const int gridSize = 20;
    long long paths = 1;

    for (int i = 0; i < gridSize; i++) {
        paths *= (2 * gridSize) - i;
        paths /= i + 1;
    }
    cout << paths << endl;
    return 0;
}
