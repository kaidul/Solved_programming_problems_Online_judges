#include <stdio.h>
using namespace std;
int R, W, combination[10];
char word[105][305], rule[1005][305], length;

void generate(int r, int w, int index) {
    if (index == length) {
        for (int c = 0, i = 0; rule[r][i]; i++) {
            if (rule[r][i] == '0')
                printf("%c", '0' + combination[c++]);
            else
                printf("%s", word[w]);
        }
        putchar('\n');
        return;
    }
    for (int i = 0; i < 10; i++) {
        combination[index] = i;
        generate(r, w, index + 1);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &W) != EOF) {
        for (int i = 0; i < W; i++)
            scanf("%s", word[i]);
        scanf("%d", &R);
        for (int i = 0; i < R; i++) {
            scanf("%s", rule[i]);
            length = 0;
            for (int j = 0; rule[i][j]; j++)
                length += (rule[i][j] == '0');
            printf("--\n");
            for (int j = 0; j < W; j++)
                generate(i, j, 0);
        }
    }
    return 0;
}
