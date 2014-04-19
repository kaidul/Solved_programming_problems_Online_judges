#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m;
int main() {
    int i,j;
    scanf("%d%d",&n,&m);
    if(n==1&&m==0) {
        printf("1");
        return 0;
    }
    if(n==1) {
        printf("-1");
        return 0;
    }
    if(m<(n/2)) printf("-1");
    else {
        j=m-((n/2)-1);
        printf("%d %d ",j,j*2);
        j=999999999;
        for(i=3; i<=n; i++) {
            printf("%d ",j);
            j--;
        }
    }
    return 0;
}
