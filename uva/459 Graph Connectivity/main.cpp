#include <bits/stdc++.h>

using namespace std;

int parent[26], rank[26];

void initSet(int N) {
    for(int i = 0; i < N; ++i) parent[i] = i, rank[i] = 0;
}

int findSet(int x) {
    return parent[x] == x ? x : parent[x] = findSet(parent[x]);
}

int Union(int &x, int &y) {
    int PX = findSet(x), PY = findSet(y);
    if(rank[PX] > rank[PY])
        parent[PY] = PX;
    else {
        parent[PX] = PY;
        if(rank[PX] == rank[PY])
            rank[PY]++;
    }
}

bool isSameSet(int &x, int &y) {
    return findSet(x) == findSet(y);
}

int main() {
//    freopen("input.txt", "r", stdin);
    int tcase, n, x, y, ans;
    char c;
    string input;

    scanf("%d\n\n", &tcase);

    while(tcase--) {
        getline(cin, input);
        n = input[0] - 'A' + 1;
        ans = n;
        initSet(n);

        while(true) {
            if(!getline(cin, input) or input.empty()) break;

            x = input[0] - 'A';
            y = input[1] - 'A';

            if( !isSameSet(x, y) ) {
                Union(x, y);
                ans--;
            }
        }
        printf("%d\n", ans);
        if(tcase) printf("\n");
    }

    return 0;
}
