#include <stdio.h>

int main() {
    int N, item, i;
    int flag;
    while(scanf("%d", &N) && N) {
        flag = 0;
        for(i = 0; i < N; i++)
            if(scanf("%d", &item) && item) {
                flag = 1;
                printf("%d", item);
                if(i < N) printf(" ");
            } else continue;

        if(flag == 0) printf("0");

        printf("\n");
    }
    return 0;
}
