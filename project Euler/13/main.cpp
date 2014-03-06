#include <bits/stdc++.h>

using namespace std;

int data[100][50];
int result[200];

int main(void) {
    freopen("input.txt", "r", stdin);
    char in;
    int value, row = 0, indx = 0;
    while(~scanf("%c", &in)) {
        if(in == '\n') {
            ++row;
            indx = 0;
            continue;
        }
        value = (int)(in - '0');
        data[row][indx++] = value;
    }
    int sum = 0, carry = 0;
    indx = 0;
    for(int i = 50 - 1; i >= 0; --i) {
        sum = carry;
        for(int j = 0; j < 100; ++j) {
            sum += data[j][i];
        }
        result[indx++] = sum % 10;
        carry = sum / 10;
    }
    while(carry > 0) {
        result[indx++] = carry % 10;
        carry /= 10;
    }
    for(int i = indx - 1; i > indx - 1 - 10; --i) cout << result[i];
    return 0;
}
