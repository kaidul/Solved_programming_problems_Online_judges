#include <stdio.h>
#include <string.h>

int matrix [5] [5];
int arr [10];

void bktk (int at, int cnt) {
    arr [cnt] = at;

    if ( cnt == 8 ) {
        for ( int i = 0; i < 9; i++ )
            printf ("%d", arr [i] + 1);
        printf ("\n");
        return;
    }

    for ( int i = 0; i < 5; i++ ) {
        if ( matrix [at] [i] ) {
            matrix [at] [i] = matrix [i] [at] = 0;
            bktk (i, cnt + 1);
            matrix [at] [i] = matrix [i] [at] = 1;
        }
    }

}

int main () {
    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            matrix [i] [j] = 0;
        }
    }

    matrix [0] [1] = matrix [0] [2] = matrix [0] [4] = 1;
    matrix [1] [0] = matrix [1] [2] = matrix [1] [4] = 1;
    matrix [2] [0] = matrix [2] [1] = matrix [2] [3] = matrix [2] [4]= 1;
    matrix [3] [2] = matrix [3] [4] = 1;
    matrix [4] [0] = matrix [4] [1] = matrix [4] [2] = matrix [4] [3]= 1;

    bktk (0, 0);
    return 0;
}
