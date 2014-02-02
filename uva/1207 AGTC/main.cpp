#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define EDIT_COST (1)

inline
int min(int a, int b) {
    return a < b ? a : b;
}

// Returns Minimum among a, b, c
int Minimum(int a, int b, int c) {
    return min(min(a, b), c);
}

// Strings of size m and n are passed.
// Construct the Table for X[0...m, m+1], Y[0...n, n+1]
int EditDistanceDP(char X[], char Y[], int lenX, int lenY) {

    // T[m][n]
    int T[lenX + 1][lenY + 1];

    for(int i = 0; i <= lenX; i++) T[i][0] = i;
    for(int i = 0; i <= lenY; i++) T[0][i] = i;

    for(int i = 1; i <= lenX; i++) {
        for(int j = 1; j <= lenY; j++) {
            if (X[i - 1] == Y[j - 1])
                T[i][j] = T[i - 1][j - 1];
            else
                T[i][j] = Minimum(T[i - 1][j], T[i][j - 1], T[i - 1][j - 1]) + 1;
        }
    }

    return T[lenX][lenY];
}

int main(void) {
    freopen("input.txt", "r", stdin);
    char X[10000], Y[10000];
    int lenX, lenY;
    while (scanf("%d %s %d %s", &lenX, &X, &lenY, &Y) == 4) {
        printf("%d\n", EditDistanceDP(X, Y, lenX, lenY));
    }
    return 0;
}
