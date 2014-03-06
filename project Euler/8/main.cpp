#include <bits/stdc++.h>
#define Max 1000
using namespace std;

int main(void) {
    freopen("input.txt", "r", stdin);
    char in;
    int data[Max + 10];
    int ans = -1, indx = 0, sum, value;
    while(~scanf("%c", &in)) {
        if(in == '\n') continue;
        value = (int)(in - '0');
        data[indx++] = value;
    }
    for(int i = 0; i < Max - 4; ++i) {
        sum = 1;
        for(int j = i; j < i + 5; ++j) {
            sum *= data[j];
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
