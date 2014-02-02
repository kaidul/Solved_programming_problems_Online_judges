#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define Max 10
int n;
char s[Max + 1];

void knuths_permutation(int i, char* t) {
    if (i == n) {
        t[n] = '\0';
        printf("%s\n", t);
        return;
    }
    char u[n + 1];
    u[0] = s[i];
    memcpy(&u[1], t, i); // t[0]...t[i] will be copied into u[1]...u[i + 1]
    knuths_permutation(i + 1, u);
    for (int j = 0; j < i; j++) {
        swap(u[j], u[j + 1]);
        knuths_permutation(i + 1, u);
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    bool printed = false;
    char t[Max + 1];
    while (scanf("%s", s) != EOF) {
        n = strlen(s);
        if (printed)
            putchar('\n');
        else
            printed = true;
        knuths_permutation(0, t);
    }
    return 0;
}
