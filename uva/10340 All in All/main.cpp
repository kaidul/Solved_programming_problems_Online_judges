#include <stdio.h>
int main() {
    char s1[2000010], s2[2000010];
    int i, j;
    while(scanf("%s %s", s1, s2) == 2) {
        i = 0;
        for(j = 0; s2[j] && s1[i]; j++)
            if(s2[j] == s1[i])
                i++;
        if(!s1[i])
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
