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
#define WRITE(f) freopen(f, "w", stdout)

/* this problem is more likely coin change than knapsack. (sum of subset problem) */
#define MAX_N 1121
#define Max_k 15
#define Prime_N 189
int k;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129};

// top down (verdict - AC)
/*
int N;
int dp[Max_k][Prime_N][MAX_N];

int knapsack(int taken, int i, int n) {
    if(primes[i] > N) {
        if(n == 0 && taken == 0) return 1;
        return 0;
    }
    if(dp[taken][i][n] != -1) return dp[taken][i][n];
    int ret1 = 0, ret2 = 0;
    if(n - primes[i] >= 0 && taken > 0)
        ret1 = knapsack(taken - 1, i + 1, n - primes[i]);

    ret2 = knapsack(taken, i + 1, n);
    return dp[taken][i][n] = ret1 + ret2;
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    mem(dp, -1);
    while(scanf("%d %d", &N, &k) != EOF) {
        if(N == 0 && k == 0) break;
        println(knapsack(k, 0, N));
    }
}
*/
int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    // nWays[i][j] = x means i can be made by exactly j prime numbers in total x ways
    int nWays[1121][15], i, j, k;
    mem(nWays, 0);
    nWays[0][0] = 1;

    for(i = 0; i <= 187; i++) // 187 = total # of primes
        for(j = 1120; j >= primes[i]; j--)
            for(k = 1; k < 15; k++)
                nWays[j][k] += nWays[j - primes[i]][k - 1];

    while(sf("%d %d", &i, &j) != EOF) {
        if(!i && !j) break;
        println(nWays[i][j]);
    }
    return 0;
}
