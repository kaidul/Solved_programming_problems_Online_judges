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
#define LL unsigned long long
using namespace std;

int main () {
    freopen ("input.txt", "r", stdin);
    int testCase;
    scanf ("%d", &testCase);
    bool space = false;
    getchar ();

    char input [25 + 3] [25 + 3];
    gets (input [0]);

    while ( testCase-- ) {

        int index = 0;

        while ( gets (input [index]) && strlen (input [index]) ) index++;

        int a [25 + 3] [25 + 3];

        for ( int i = 0; i < index; i++ )
            for ( int j = 0; j < index; j++ )
                a [i] [j] = input [i] [j] == '1' ? 1 : 0;

        for ( int i = 1; i < index; i++ )
            for ( int j = 0; j < index; j++ )
                a [i] [j] = a [i] [j] == 1 ? a [i - 1] [j] + 1 : 0;


        int maxi = INT_MIN;

        for ( int i = 0; i < index; i++ ) {
            for ( int j = 0; j < index; j++ ) {
                int cnt = 1;
                for ( int k = j - 1; k >= 0 && a [i] [k] >= a [i] [j]; k-- ) cnt++;
                for ( int k = j + 1; k < index && a [i] [k] >= a [i] [j]; k++ ) cnt++;
                cnt *= a [i] [j];
                if ( maxi < cnt ) maxi = cnt;
            }
        }

        if ( space ) printf ("\n");
        space = true;
        printf ("%d\n", maxi);
    }

    return 0;
}

// I coded it, but doesn't work (WA) :(

/*

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <climits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;
#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)

#define Max 101
using namespace std;

int main () {
    freopen ("input.txt", "r", stdin);
    int testCase;
    scanf ("%d", &testCase);
    bool space = false;
    getchar ();

    char input [25 + 3] [25 + 3];
    gets (input [0]);

    while ( testCase-- ) {

        int index = 0;

        while ( gets (input [index]) && strlen (input [index]) ) index++;

        int a [25 + 3] [25 + 3];
        int k = 0;
        for ( int i = 0; i < index; i++ )
            for ( int j = 0; j < index; j++ ) {
                a [i] [j] = input [i] [j] == '1' ? 1 : 0;
                a[i][j] = a[i][j] == 1 ? k = k + 1 : k = 0;
            }

        int max = INT_MIN, item;
        for (int i = 0; i < index; i++)
            for (int j = 0; j < index; j++)
                if (a[i][j]) {
                    item = a[i][j];
                    if (item > max) max = item;
                    for (int k= i + 1, l = 2; k < index; k++, l++)
                        if (a[k][j]) {
                            if (item > a[k][j]) item = a[k][j];
                            if (item * l > max) max = item * l;
                        } else break;
                }


        if ( space ) printf ("\n");
        space = true;
        printf ("%d\n", max);
    }

    return 0;
}



 */
