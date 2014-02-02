#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <climits>
#include <math.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int height[10010] = {0};
    int left, right, buildingHeight, y = INT_MIN;

    while (scanf("%d %d %d", &left, &buildingHeight, &right) != EOF) {
        if(right > y) y = right;
        for (int i = left; i < right; ++i) {
            if (buildingHeight > height[i])
                height[i] = buildingHeight;
        }
    }

    bool notFirst = false;
    int currentHeight = 0;
    for (int pos = 0; pos <= y + 1; ++pos) {
        if (height[pos] != currentHeight) {
            if (notFirst) printf(" ");
            else notFirst = true;
            printf("%d %d", pos, height[pos]);
            currentHeight = height[pos];
        }
    }
    printf("\n");
    return 0;

}
