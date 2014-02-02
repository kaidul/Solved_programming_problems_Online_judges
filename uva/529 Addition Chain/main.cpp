#include<stdio.h>
#include<cstring>
#include<cmath>
#include<string>
#include<ctime>
#include<vector>
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define DBG 0
using namespace std;

#define Max 10001

int N,CM;
int cnt[Max];
bool has[Max];
vector <int> mv, cv;
void print() {
    bool ll=0;
    rep(i,mv.size()) {
        if(ll)printf(" ");
        ll=1;
        printf("%d",mv[i]);
    }
    printf("\n");
}
bool DFS(int cur) {
    if(cur==N) {
        mv=cv;
        return 1;
    } else {
        int c,bc,k,j;
        has[cur]=1;
        rep(i,cv.size()) {
            c=cur+cv[i];
            for(k=c,j=cv.size()+2; j<CM+1; k*=2,j++);
            if(k<N)continue;
            if(c<=N&&!has[c]&&cv.size()+1<=cnt[c]) {
                cnt[c]=cv.size()+1;
                cv.push_back(c);
                if(DFS(c))return 1;
                cv.pop_back();
            }
        }
        has[cur]=0;
        return 0;
    }

}

int getNum(int a) {
    return int(ceil(log(a)/log(2)));
}
void ans() {

    print();
}
int main(void) {
    int a;
    memset(cnt, 0x7f, sizeof cnt);
    while(scanf("%d", &N) == 1) {
        if(N == 0)
            break;
        memset(has,0,sizeof(has));
        cv.clear(),cv.push_back(1),CM=18,has[0]=1;
        if(DBG)printf("cur %d\n",N);
        int n=getNum(N);
        REP(i,n,19) {
            mv.clear(),CM=i;
            DFS(1);
            if(mv.size())break;
        }
    }
}

