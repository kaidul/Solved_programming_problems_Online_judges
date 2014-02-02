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
#include <list>
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
/*** typedef ***/
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
/** function **/
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

#define M 7
#define Max 200

int amount, optimal, dp[Max];

/**
 dp[i] = x means total number of x coins is needed to make i
 i.e. given coins {1, 2, 4, 10, 20, 40} = {0, 0, 0, 1, 1, 2} then dp[10] = 1, dp[20] = 1, dp[30] = 2
 dp[90] = 3 (40 + 40 + 10)
 dp[100] = 3 (40 + 40 + 20)
**/

struct coin {
    int value, quantity;
    coin() {}
    coin(int a, int b) {
        value = a, quantity = b;
    }
} coins[M];

int minChange(int n) {
    for(int i = M - 2; i >= 0; i--) {
        if(n >= coins[i].value) {
            return 1 + minChange(n - coins[i].value);
        }
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int coinsValue[] = {1, 2, 4, 10, 20, 40};
    double price;
    int quantity, sum;
    while(true) {
        sum = 0, optimal = INF;
        rep(i, M - 1) SDi(quantity), coins[i] = coin(coinsValue[i], quantity), sum += quantity;
        if(sum == 0) break;
        cin >> price;
        amount = ( price + eps ) * 20;

        rep(i, Max) dp[i] = INF;
        dp[0] = 0;

        rep(i, M - 1) {
            while(coins[i].quantity) {
                for(int j = Max - coins[i].value - 1; j >= 0; j--) {
                    if(dp[j] != INF ) {
                        dp[j + coins[i].value] = min( dp[j] + 1, dp[j + coins[i].value] );
                    }
                }
                coins[i].quantity--;
            }
        }
/*
        // this was my firt try and buggy because it didn't took care of the limited quantity of each coins
        rep(i, M - 1) {
            while(coins[i].quantity) {
                for(int j = coins[i].value; j < Max; j++) {
                    dp[j] = min( dp[j], dp[j - coins[i].value] + 1);
                }
                coins[i].quantity--;
            }
        }
*/

        for(int i = amount; i < Max; i++) {
            optimal = min( optimal, dp[i] + minChange(i - amount) );
        }

        pf("%3d\n", optimal );
    }
    return 0;
}
