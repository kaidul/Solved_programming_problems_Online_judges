#include <bits/stdc++.h>
#define _ ios_base:sync_with_stdio(0);cin.tie(0);
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


struct agency {
    char name[20];
    int totalCost;
    agency() {}
    agency (int a, char* _name) {
        strcpy(name, _name);
        totalCost = a;
    }
    bool operator < (const agency a) const {
        if (totalCost == a.totalCost) return strcmp(a.name, name) > 0;
        return totalCost < a.totalCost;
    }
} agencies[101];

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int tcase, caseNo = 0;
    SDi(tcase);
    int N, M, L;
    char input[50];
    while(tcase--) {
        SD3(N, M, L);
        getchar();
        rep(i, L) {
            gets(input);
            char name[20];
            int j, k;
            for (j = 0; input[j] != ':'; j++) {
                name[j] = input[j];
            }
            name[j] = '\0';
            char temp[10];
            for (j = j + 1, k = 0; input[j] != ','; j++, k++) {
                temp[k] = input[j];
            }
            temp[k] = '\0';
            int A = atoi(temp);
            for (j = j + 1, k = 0; input[j] != '\0'; j++, k++) {
                temp[k] = input[j];
            }
            temp[k] = '\0';
            int B = atoi(temp);

            int tmpN = N;
            int cost = 0;
            while ( tmpN != M ) {
                if ( tmpN / 2 < M ) {
                    cost += (A * (tmpN - M));
                    tmpN = M;
                } else {
                    int diff = tmpN - (tmpN / 2);
                    if ( diff * A > B ) cost += B;
                    else cost += (diff * A);
                    tmpN /= 2;
                }
            }
            agencies[i] = agency(cost, name);
        }
        sort(agencies, agencies + L);
        pf("Case %d\n", ++caseNo);
        rep(i, L) {
            pf("%s %d\n", agencies[i].name, agencies[i].totalCost);
        }
    }
    return 0;
}
