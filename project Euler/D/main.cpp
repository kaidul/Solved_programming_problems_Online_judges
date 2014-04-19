#include<cstdio>
#include<cstdlib>
#define MOD 1000000007
using namespace std;
int n,m,f[2100][2100];
bool b[2100][2100];
int dp(int x,int y) {
    if(y==1) return x;
    if(b[x][y]) return f[x][y];
    b[x][y]=true;
    int i;
    for(i=1; i<=x; i++) f[x][y]=(f[x][y]+dp(x/i,y-1))%MOD;
    return f[x][y];
}
int main() {
    scanf("%d%d",&n,&m);
    printf("%d",dp(n,m));
    return 0;
}
