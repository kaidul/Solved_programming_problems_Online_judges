#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

#define Max 100
#define Range 32000

int N, target, data[Max];
bool dp[Max][2 * Range + 1];

bool valid(int a) {
        return ( a >= -Range and a <= +Range );
}

bool solve(int indx, int value, string expression) {
    if(indx == N) {
        if(value == target) {
            printf("%d", data[0]);
            for (int i = 0, n = expression.length(); i < n; i++) {
                    printf("%c%d", expression[i], data[i + 1]);
            }
            printf("=%d\n", target);
            return true;
        }
        return 0;
    }
    if( dp[indx][value] )
        return false;
    dp[indx][value] = true;

    if( valid(value + data[indx]) and solve(indx + 1, value + data[indx], expression + '+' ) )
        return true;
    if( valid(value - data[indx]) and solve(indx + 1, value - data[indx], expression + '-' ) )
        return true;
    if( valid(value * data[indx]) and solve(indx + 1, value * data[indx], expression + '*' ) )
        return true;
    if(data[indx] != 0 and value % data[indx] == 0 and valid(value / data[indx]) and solve(indx + 1, value / data[indx], expression+ '/' ) )
        return true;

    return false;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d",&tcase);
    while (tcase--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
        	scanf("%d", data + i);
        }
        scanf("%d", &target);
        memset(dp, false, sizeof dp);
        if( !solve (1, data[0], "") ) {
            printf("NO EXPRESSION\n");
        }
    }
}
