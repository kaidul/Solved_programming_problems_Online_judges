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

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define RESET(t,value) memset((t), value, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define pii pair<double,double>
#define G struct node
#define Max 400000
#define ll long long

ll dp[Max];

int f(int n){
    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    else{
        dp[n] = f(n-1) + f(n-2);
        return dp[n];
    }
}

int main(){
    int N = 4000000;
    FOR(i, 0, Max) dp[i] = -1;
    int sum = 0;
    for(int i = 1; ;i++){
        int fib = f(i);
        if(fib > N) break;
        if(fib%2 == 0) sum += fib;
    }
    cout<<sum;
    return 0;
}

