/*
For each step of the route of one of the two characters(let's say the princess), assign the number of this step in the sequence of the prince.

First observation - all the steps not present in the prince's sequence are immediately removed - they can not be part of the common sequence of moves.

Now we have a sequence of numbers representing the index in the sequence of moves of the prince. We should choose an increasing subsequence(increasing because we should visit the cells in the same order as the prince) of maximal length of that sequence.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>



#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod abs
#define pf printf
#define sf scanf

using namespace std;

#define MAXX 251

int tmp, sc[MAXX*MAXX];
int n, p, q;
int pos[MAXX*MAXX];

int LIS() {
    int I[MAXX*MAXX + 1];
    I[0] = -INF;

    FOR(i, 1, q) {
        I[i] = INF;
    }

    int LisLength = 0;
    loop(i, q) {
        int low, high, mid;
        low = 0;
        high = LisLength;

        while(low <= high) {
            mid = (low+high)/2;
            if(I[mid] < sc[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        I[low] = sc[i];
        if(LisLength < low) {
            LisLength = low;
        }
    }
    return LisLength;

}

int main() {
    //freopen("input.txt", "r", stdin);
    int kases, kaseno = 0;
    getint(kases);
    while(kases--) {
        getint(n);
        getint(p);
        getint(q);
        p++;
        q++;

        mem(pos, -1);

        loop(i, p) {
            getint(tmp);
            pos[tmp] = i+1;
        }

        loop(i, q) {
            getint(tmp);
            sc[i] = pos[tmp] - 1;

        }

        //loop (i, q) cout << sc[i] << " ";

        pf("Case %d: %d\n", ++kaseno, LIS() );

    }

    return 0;
}
