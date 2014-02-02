#include <cstdio>
#include <iostream>

using namespace std;

int main (void) {
    char A[150][150], buffer [150];
    long M, N, Case=0;
    bool flag = false;
    while ( true ) {

        gets(buffer);
        sscanf(buffer, "%ld%ld", &M, &N);

        if (M == 0 and N == 0)
            break;

        long B[150][150] = {0};

        for (int i = 0; i < M; i++)
            gets (A[i]);

        for (int i = 0; i < M; i++ ) {

            for (int j = 0; j < N; j++) {

                if (A[i][j] == '*') {
                    B[i][j + 1]++;
                    B[i + 1][j + 1]++;
                    B[i + 1][j]++;
                    B[i + 1][j - 1]++;
                    B[i][j - 1]++;
                    B[i - 1][j - 1]++;
                    B[i - 1][j]++;
                    B[i - 1][j + 1]++;
                }
            }

        }

        // output
        if (flag == true)
            printf("\n");
        flag = true;
        printf("Field #%ld:\n", ++Case);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == '*')
                    printf("%c", A[i][j]);
                else
                    printf("%ld", B[i][j]);
            }
            printf("\n");
        }

        //printf("\n");
    }
    return 0;
}
