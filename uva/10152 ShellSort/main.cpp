/**
Analysis :

Given initial stack and final stack. One operation possible : move any turtle from anywhere in initial stack and place it at top.
Take two pointers, one points to the end of initial stack : ini
and other points to the end of final stack : fin
if ( initial [ini] == final [fin] )
fin– and ini–
// both are same, so we don’t need any movement
if ( initial [ini] != final [fin] )
// we need to move initial [ini]
// but it may not be the right time to place initial [ini] at top
// that is, its sure that, we have to move initial [ini], but we don’t know when to place it at top
// so for now, move the initial [ini] from initial stack
// as we have moved initial [ini], all the turtle before it should fall down one step
// now go back to step 3
at the end, we will reach at the top of initial stack, means ini = -1
at this state u can’t compare, if ( initial [ini] == final [fin] )
now its time to place previously moved turtles in correct order
loop through fin to 0 and print final [fin]
**/
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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;


int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int turtle;
        scanf ("%d", &turtle);
        getchar ();

        char input [100];
        vector <string> initial;
        vector <string> final;

        for ( int i = 0; i < turtle; i++ ) {
            gets (input);
            initial.push_back (input);
        }

        for ( int i = 0; i < turtle; i++ ) {
            gets (input);
            final.push_back (input);
        }

        vector <string>::iterator ini = initial.end () - 1;
        vector <string>::iterator fin = final.end () - 1;
        map <string, bool> reserve;
        vector <string> output;

        while ( fin != final.begin () - 1 ) {
            if ( *fin == *ini ) fin--, ini--;
            else {
                if ( reserve [*fin] == true ) {
                    while ( ini != initial.begin () ) {
                        reserve [*ini] = true;
                        initial.erase (ini);
                        ini--;
                    }
                    reserve [initial [0]] = true;

                    while ( fin != final.begin () ) {
                        output.push_back (*fin);
                        fin--;
                    }

                    output.push_back (final [0]);
                    break;
                }

                else {
                    while ( *ini != *fin ) {
                        reserve [*ini] = true;
                        initial.erase (ini);
                        ini--;
                    }
                }

                fin--;
            }

        }

        for ( size_t i = 0; i < output.size(); i++ )
            cout << output [i] << endl;
        cout << endl;
    }

    return 0;
}
