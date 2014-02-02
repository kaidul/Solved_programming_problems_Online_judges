#include <cstdio>
#include <stack>
#define max 10000
using namespace std;

struct matrix {
    int r, c;
} mat[26], res, a, b;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, i, s, sum, flag;
    char temp[max];
    for(scanf("%d",&n); n; n--) {
        scanf("%s",temp);
        scanf("%d %d", &mat[temp[0] - 'A'].r, &mat[temp[0] - 'A'].c );
    }
    while( ~scanf("%s",temp) ) {
        if(temp[1] == 0) {
            printf("0\n");
            continue;
        }
        stack <matrix> S;
        sum = s = 0;
        flag = 1;
        for(i = 0; temp[i]; i++) {
            if(temp[i] >= 'A' and temp[i] <= 'Z')
                S.push(mat[temp[i] - 'A']);
            else if(temp[i] == ')') {
                b = S.top();
                S.pop();
                a = S.top();
                S.pop();
                if(a.c != b.r) {
                    flag = 0;
                    break;
                }
                sum += a.r * a.c * b.c;
                res.r = a.r;
                res.c = b.c;
                S.push(res);
            }
        }
        if(flag==0)
            printf("error\n");
        else
            printf("%d\n",sum);
    }
    return 0;
}
