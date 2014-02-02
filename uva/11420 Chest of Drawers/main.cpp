#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long int64;

using namespace std;

enum State {UnLocked, Locked, SecureLocked};

int64 dp [65 + 3] [3 + 2] [65 + 3];
int n, s;

int64 recur (int indx, State state, int secure) {
    if ( indx == n )
        return secure == s ? 1 : 0;

    if ( dp [indx] [state] [secure] != -1 )
        return dp [indx] [state] [secure];

    int64 ret = 0;

    if ( state == UnLocked ) {
        ret += recur (indx + 1, UnLocked, secure);
        ret += recur (indx + 1, Locked, secure);
    } else if ( state == Locked ) {
        ret += recur (indx + 1, UnLocked, secure);
        ret += recur (indx + 1, SecureLocked, secure + 1);
    } else {
        ret += recur (indx + 1, UnLocked, secure);
        ret += recur (indx + 1, SecureLocked, secure + 1);
    }

    return dp [indx] [state] [secure] = ret;
}

int main () {
    freopen("input.txt", "r", stdin);
    while ( scanf ("%d %d", &n, &s) ) {
        if ( n < 0 and s < 0 ) break;

        memset (dp, -1, sizeof dp);

        printf ("%lld\n", recur (0, Locked, 0));
    }

    return 0;
}
