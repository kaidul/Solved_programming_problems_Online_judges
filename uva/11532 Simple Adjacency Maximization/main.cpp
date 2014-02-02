/**
    Language : C++
    Time: 0.022 sec
    Author: Kaidul Islam, KUET
**/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define ui64 unsigned long long

using namespace std;

void binaryToDecimal(string s) {
    ui64 ret = 0;
    reverse (s.begin (), s.end ());
    for ( size_t i = 0; i < s.length (); i++ ) {
        ret += (pow(2, i) * (s.at (i) - '0'));
    }

    printf("%lld\n", ret);
}

int main () {
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int p, q;
        scanf ("%d %d", &p, &q);

        string str = "";

        while ( p >= 2 && q >= 1 ) {
            str += "101";
            p -= 2, q--;
        }

        if ( p == 1 && q >= 1 ) {
            str = "01" + str;
            p--, q--;
        }
        for ( int i = 0; i < p; i++ )
            str += "1";

        // this is madness
        for ( int i = 0; i < q; i++ )
            str = "0" + str;

        binaryToDecimal(str);
    }

    return 0;
}
