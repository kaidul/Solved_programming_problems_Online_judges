#include <bits/stdc++.h>
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

#define vi vector<int>

int main () {
    int tcase;
    scanf ("%d", &tcase);
    int input, n;
    vi v, dest;
    map <vi, int> pressCnt;
    map <vi, bool> visited;
    queue < vi > q;

    while ( tcase-- ) {
        for ( int i = 0; i < 4; i++ ) {
            scanf ("%d", &input);
            v.push_back(input);
        }
        pressCnt[v] = 0;
        q.push(v);

        for ( int i = 0; i < 4; i++ ) {
            scanf ("%d", &input);
            dest.push_back(input);
        }
        scanf ("%d", &n);

        for ( int i = 0; i < n; i++ ) {
            v.clear();
            for ( int j = 0; j < 4; j++ ) {
                scanf ("%d", &input);
                v.push_back (input);
            }
            visited [v] = true;
        }

        bool resultFound = false;

        while ( !q.empty () ) {
            v.clear ();
            v = q.front ();
            q.pop ();

            if ( visited [v] == true ) continue;

            visited [v] = true;

            if ( v == dest ) {
                resultFound = true;
                break;
            }

            vector <int> child = v;

            for ( int i = 0; i < 4; i++ ) {
                child [i] += 1;
                child [i] %= 10;
                if(!visited [child]) q.push (child);
                pressCnt [child] = pressCnt [v] + 1;
                child = v;
            }

            for ( int i = 0; i < 4; i++ ) {
                child [i] -= 1;
                if (child[i] == -1) child[i] = 9;
                if(!visited [child]) q.push (child);
                pressCnt [child] = pressCnt [v] + 1;
                child = v;
            }
        }

        if ( resultFound ) printf ("%d\n", pressCnt[dest]);
        else printf ("-1\n");
        pressCnt = map <vi, int> ();
        visited = map <vi, bool> ();
        q = queue < vi > ();
        v.clear();
        dest.clear();
    }

    return 0;
}
