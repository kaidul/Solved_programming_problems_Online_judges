#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> nlist;
vector< vector<int> > finlist;
bool used[20];
map< vector<int>, bool > mp;

/*
Possible optimizations: Used a map to check if a set was generated before, it takes more time than checking if the numbers were used more than they appeared in input
*/

void btracking(int t, int sum, vector<int> temp, int k) {

    if (sum == t) {
        if ( !mp[temp] ) {
            finlist.push_back(temp);
            mp[temp] = true;
        }
        return;
    }

    for (int n = nlist.size(); k < n; k++) {
        if ( !used[k] ) {
            if ( sum + nlist[k] <= t ) {
                temp.push_back(nlist[k]);
                used[k] = true;
                btracking(t, sum + nlist[k], temp, k);
                used[k] = false;
                temp.pop_back();
            }
        }
    }
}

int main( void ) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t, n, x;

    while ( scanf("%d %d",&t, &n) and n ) {

        printf("Sums of %d:\n", t);

        nlist.clear();
        for (int i = 0 ; i < n ; i++) {
            scanf("%d", &x);
            nlist.push_back(x);
            used[i] = false;
        }

        finlist.clear();
        vector<int> temp;
        mp.clear();
        btracking(t, 0, temp, 0);

        if ( !finlist.size() ) {
            printf("NONE\n");
        }

        for (int i = 0 ; i < finlist.size() ; i++) {
            for (int j = 0 ; j < (int) finlist[i].size() ; j++) {
                if (!j) printf("%d", finlist[i][j]);
                else printf("+%d", finlist[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}
