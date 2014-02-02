#include<cstdio>
int main() {
    int a[20], i, j, bin, t;
    while(scanf("%d", &t) == 1) {
        for(i = 0; i < t; i++) {
            bin = 0;
            for(j = 0; j < 10; j++)
                scanf("%d", &a[j]);
            if(i == 0)
                printf("Lumberjacks:\n");
            for(j = 1; j < 10; j++) {
                if(a [j - 1] <= a[j]) {
                    if(j == 9) {
                        printf("Ordered\n");
                        bin = 1;
                    }
                } else
                    break;
            }
            if(bin == 0)
                for(j = 1; j < 10; j++) {
                    if(a[j - 1] >= a[j]) {
                        if(j == 9) {
                            printf("Ordered\n");
                            bin = 1;
                        }
                    } else
                        break;
                }
            if(bin == 0)
                printf("Unordered\n");
        }
    }
}
