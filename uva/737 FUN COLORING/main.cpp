#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector <int> v[120];

int Set(int N, int pos){
    return N = N | (1 << pos);
}

bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}


int main(void) {
    freopen("input.txt", "r", stdin);
    int N, M;
    char s[30];
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d %d", &N, &M);
        int mask = (1 << N) - 1;
        getchar();
        for (int i = 0; i < M; i++) {
            v[i].clear();
            gets(s);
            char *ptr = strtok(s, " ");
            do {
                int num;
                sscanf(ptr," %d", &num);
                v[i].push_back( num - 1 );
            } while((ptr = strtok(NULL, " ")) != NULL);
        }
        bool ok = false;

        for(int i = 0; i <= mask and !ok; i++) {
            bool re = false;
            for(int j = 0; j < M and !re; j++) {
                int mk = 0;
                for(int k = 0; k < (int) v[j].size() and mk != 3; k++) {
                    if( Check(i, v[j][k]) )
                        mk |= 1;
                    else
                        mk |= 2;
                }
                if(mk != 3)
                    re = true;
            }
            if(re == false)
                ok = true;
        }

        printf("%c", ok ? 'Y':'N');
    }
    return 0;
}
