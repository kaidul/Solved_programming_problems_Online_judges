// Program to find maximum sum subarray in a given 2D array
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#define Max 100
using namespace std;
// Implementation of Kadane's algorithm for 1D array. The function returns the
// maximum sum and stores starting and ending indexes of the maximum sum subarray
// at addresses pointed by start and finish pointers respectively.
int ROW, COL;
int kadane(int* arr) {
    // initialize sum, maxSum and start
    int sum = 0, maxSum = INT_MIN, i;
    for (i = 0; i < ROW; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
        } else if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    freopen("in.txt", "r", stdin);
    while(cin >> ROW) {
        COL = ROW;
        int M[ROW + 1][ROW + 1];
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                cin >> M[i][j];

        int maxSum = 0;
        int left, right, i;
        int temp[ROW], sum;
        for (left = 0; left < COL; ++left) {
            memset(temp, 0, sizeof(temp));
            for (right = left; right < COL; ++right) {
                for (i = 0; i < ROW; ++i)
                    temp[i] += M[i][right];
                sum = kadane(temp);
                if (sum > maxSum)
                    maxSum = sum;
            }
        }
        printf("%d\n", maxSum);
    }
    return 0;
}
