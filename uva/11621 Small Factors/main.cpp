#include <bits/stdc++.h>

using namespace std;

#define Max 1000000
#define ui64 unsigned long long

int main (void) {
//    freopen("input.txt", "r", stdin);
    set <ui64> s;
    s.insert(1);

    for (set <ui64> :: iterator it = s.begin(); it != s.end (); it++) {
        if ( (*it) * 2 > (ui64) INT_MAX + 3 )
            break;
        s.insert((*it) * 2);
        s.insert((*it) * 3);
    }

    ui64 n;

    while ( cin >> n and n ) {

        for (set <ui64> :: iterator it = s.begin (); it != s.end (); it++) {
            if ( (*it) >= n ) {
                cout << *it << endl;
                break;
            }
        }
    }

    return 0;
}
