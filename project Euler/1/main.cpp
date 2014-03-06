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
#define Max 1300000
#define ll long long

int main(){
    int N = 1000;
    int i = 3, j = 5, sum = 0;
    for(int k = 1;k*i < 1000;k++ ){
        sum += i*k;
    }
    for(int k = 1;k*j < 1000;k++ ){
        int mul = j*k;
        if(mul%3 == 0) continue;
        sum += mul;
    }
    cout<< sum;
    return 0;
}
