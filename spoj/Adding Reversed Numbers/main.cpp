#include <bits/stdc++.h>

using namespace std;

int reverseNumber(int num) {
    int ret = 0;
    while(num) {
        ret = ret * 10 + (num % 10);
        num /= 10;
    }
    return ret;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int n;
    int var1, var2, sum;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &var1, &var2);
        var1 = reverseNumber(var1);
        var2 = reverseNumber(var2);
        sum = var1 + var2;
        sum = reverseNumber(sum);
        printf("%d\n", sum);
    }
    return 0;
}
