#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;

int MAX_NODE;

int BS(int node, int balls) {
    int left = node * 2, right = left + 1;
    if (left <= MAX_NODE && right <= MAX_NODE) {
        if (balls % 2 == 0) BS(right, balls / 2); // if balls were even then the sate of the current node is T, balls/2 balls pass the right node
        else BS(left, balls / 2 + 1); // if balls were odd then the state of the current node is F, balls/2 + 1 balls passed the left node
    } else return node; // return the node that has no children "leaf"
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
#endif
    int T, D, I;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &D, &I);
        MAX_NODE = pow(2.0, D) - 1;
        printf("%d\n", BS(1, I));
    }
    return 0;
}
