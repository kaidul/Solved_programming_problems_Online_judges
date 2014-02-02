#include<stdio.h>
#include<string.h>
int main() {
    freopen("input.txt", "r", stdin);
    int l, i, j, b, k;
    char n[1000];
    while(gets(n)) {
        l = strlen(n);
        b = -1;
        for(i = 0; i <= l; i++) {
            if(n[i] == ' ' || i == l) {
                for(j= i- 1; j > b; j--) printf("%c", n[j]);
                if(n[i] == ' ') b = i, printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
