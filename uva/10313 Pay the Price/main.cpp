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
#define println(x) pf("%lld\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)

/* TLE CODE */

/*
#define M 305

typedef long long i64;
int coin[M];
i64 make, dp[M][M];

i64 call(i64 i, i64 amount, i64 limit) {
    if(i >= limit) {   //All coins have been taken
        if(amount == make)
            return 1;
        return 0;
    }
    if(dp[i][amount] != -1)
        return dp[i][amount]; //no need to calculate same state twice
    i64 ret1 = 0, ret2 = 0;
    if(amount + coin[i] <= make)
        ret1 = call(i, amount + coin[i], limit); //try to take coin i
    ret2=call(i + 1,  amount, limit); //dont take coin i
    return dp[i][amount] = ret1 + ret2; //storing and returning.

}

i64 coinChange(int limit) {
    memset(dp, -1, sizeof(dp));
    return call(0, 0, limit);
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    rep(i, M) coin[i] = i + 1;
    i64 i, j, k, tokens;
    char input[M];
    while(gets(input)) {
        tokens = sscanf(input,"%lld %lld %lld", &i, &j, &k);
        make = i;
        if(tokens == 1) println(coinChange(M - 5));
        if(tokens == 2) println(coinChange(j));
        if(tokens == 3) println( coinChange(k) - coinChange(j - 1) );
    }
    return 0;
}
*/

/** another TLE code **/

/*
#define MAX 305
long long int store[MAX + 1];

void preCal() {
    int i, j;
    store[0] = 1;
    for(i = 1; i <= MAX; i++)
        for(j = i; j <= MAX; j++)
            store[j] += store[j - i];
}

long long int count(int sum, int max) {
    long long int hold[sum + 1];

    int i, j, k;
    for(k = 1; k <= sum; k++)
        hold[k] = 0;

    hold[0] = 1;
    for(i = 1; i <= max; i++)
        for(j = i; j <= sum; j++)
            hold[j] += hold[j - i];

    return hold[sum];
}



int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    preCal();
    char line[500];
    int noOfInput;
    int input, in1, in2, in3, l;
    long long int out;

    while(gets(line)) {
        noOfInput = sscanf(line, "%d %d %d", &in1, &in2, &in3);

        if(noOfInput == 1) {
            if(in1 == 0)
                pf("1\n");
            else pf("%lld\n", store[in1]);
        } else if(noOfInput == 2) {
            if(in1 == 0 || in2 == 0)
                pf("1\n");
            else printf("%lld\n", count(in1, in2));
        } else if(noOfInput == 3) {
            if(in1 == 0) pf("1\n");
            else pf("%lld\n", count(in1, in3) - count(in1, in2 - 1));
        }
    }


    return 0;
}
*/
/** another TLE code **/
/*
#define M 305

typedef long long i64;
int coin[M];
i64 make, dp[M][M], cache[M][M];

i64 precalc(i64 i, i64 amount) {
    if(i >= M - 5) {
        if(amount == 0)
            return 1;
        else return 0;
    }
    if(cache[i][amount] != -1)
        return cache[i][amount];

    i64 ret1 = 0, ret2 = 0;

    if(amount - coin[i] >= 0)
        ret1 = precalc(i, amount - coin[i]);

    ret2 = precalc(i + 1, amount);

    return cache[i][amount] = ret1 + ret2;
}

i64 call(i64 i, i64 amount, i64 limit) {
    if(i >= limit) {   //All coins have been taken
        if(amount == make)
            return 1;
        else return 0;
    }
    if(dp[i][amount] != -1)
        return dp[i][amount]; //no need to calculate same state twice
    i64 ret1 = 0, ret2 = 0;
    if(amount + coin[i] <= make)
        ret1 = call(i, amount + coin[i], limit); //try to take coin i
    ret2=call(i + 1,  amount, limit); //dont take coin i
    return dp[i][amount] = ret1 + ret2; //storing and returning.

}

i64 coinChange(int limit) {
    memset(dp, -1, sizeof(dp));
    return call(0, 0, limit);
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    rep(i, M) coin[i] = i + 1;
    i64 i, j, k, tokens;
    char input[100];
    memset(cache, -1, sizeof cache);
    while(gets(input)) {
        tokens = sscanf(input,"%lld %lld %lld", &i, &j, &k);
        make = i;
        if(tokens == 1) println(precalc(0, make));
        if(tokens == 2) println(coinChange(j));
        if(tokens == 3) println(coinChange(k) - coinChange(j - 1) );
    }
    return 0;
}
*/

#define N 300

unsigned long long int sum[N + 5][N + 5], res[N + 5][N + 5];

/**
    * res[i][j] is the number of ways you can pay i dollars using exactly j coins. i.e. res[6][2] = 3, that means 6 can be paid by two coins in 3 ways (2, 4), (3, 3), (5, 1)
    * sum[i][j] is the number of ways you can pay i dollars using j or less coins i.e. sum[6][2] = 4, that means 6 can be paid by two or less than coins in 4 ways (2, 4), (3, 3), (5, 1), 6
 **/
int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int i, j, k, tokens;
    char inp[100];
    mem(res, 0);
    res[0][0] = 1; // 0 amount can be paid by exactly 0 coins in 0 ways :p

    for (int i = 1; i <= N; i++)
        for(int j = i; j <= N; j++)
            for(int k = 1; k <= N; k++)
                res[j][k] += res[j - i][k - 1];

    sum[0][0] = 1; // 0 amount can be paid by 0 or less than 0 (!!) coins in 0 ways
    for (int i = 0; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sum[i][j] = res[i][j] + sum[i][j - 1];

    while(gets(inp)) {
        tokens = sscanf(inp, "%d %d %d", &i, &j, &k);
        if(tokens == 1)
            printf("%llu\n", sum[i][i]);
        else if(tokens == 2)
            printf("%llu\n", sum[i][min(j, i)]); // because there is no gurrenty of j is less than or equal to i
        else if(j <= i)
            printf("%llu\n", sum[i][min(k, i)] - sum[i][j - 1]);
        else puts("0");
    }
    return 0;
}
