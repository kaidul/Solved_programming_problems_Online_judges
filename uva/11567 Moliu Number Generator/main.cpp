#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

/**
N = 0 and we need to make it S
bottom up approach would be perilous
rather think reversely, how to make S to 0
continuously divide S by 2, when its even
if you get and odd S, decide what to do with it
either increment it by one, or decrement it

for example, if you get S = 33
you can make it either 32 or 34
lets see which one will make us benefited
32 / 2 = 16 / 2 = 8 / 2 = 4 / 2 = 2 / 2 = 1 and then 0
on the other side
34 / 2 = 17, we get another odd number
so it better to go with 32
its a greedy solution and works fine for S (0 ≤ S ≤ 2^31)
**/

LL choice (LL s) {
    if ( s == 3 ) return 2;
    LL s1 = s + 1;
    LL s2 = s - 1;
    int ret = 0;

    if ( s2 == 0 ) return s2;

    while ( s1 % 2 == 0 && s1 != 0 ) {
        s1 /= 2;
        ret++;
    }

    while ( s2 % 2 == 0 && s2 != 0 ) {
        s2 /= 2;
        ret--;
    }

    if ( ret > 0 ) return s + 1;
    return s - 1;
}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    LL s;

    while ( cin >> s ) {
        int cnt = 0;

        while ( s != 0 ) {
            if ( s % 2 == 0 )
                s /= 2;
            else s = choice(s);
            cnt++;
        }

        printf ("%d\n", cnt);
    }

    return 0;
}
