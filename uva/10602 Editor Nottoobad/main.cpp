#include <limits>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int n_max = 100;

struct word {
    char letters[n_max + 1];
    int common_letters; // number of common letters with the first word
} words[n_max];

bool compare_word(const word& i, const word& j) {
    if (i.common_letters > j.common_letters)
        return true;
    else if (i.common_letters < j.common_letters)
        return false;
    else
        return strcmp(i.letters + i.common_letters,
                      j.letters + j.common_letters) < 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int n;
        scanf("%d\n", &n);

        for (int i = 0; i < n; i++)
            gets(words[i].letters);

        for (int i = 1; i < n; i++) {
            const char *p = words[0].letters, *q = words[i].letters;
            for ( ; *p && *q; p++, q++)
                if (*p != *q)
                    break;
            words[i].common_letters = p - words[0].letters;
        }

        sort(words + 1, words + n, compare_word);
        int pressed = strlen(words[0].letters);

        for (int i = 1; i < n; i++) {
            const char *p = words[i - 1].letters, *q = words[i].letters;
            for ( ; *p && *q; p++, q++)
                if (*p != *q)
                    break;
            pressed += words[i].letters + strlen(words[i].letters) - q;
        }

        printf("%d\n", pressed);
        for (int i = 0; i < n; i++)
            printf("%s\n", words[i].letters);
    }
    return 0;
}
