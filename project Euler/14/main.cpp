#include <bits/stdc++.h>

using namespace std;

#define Max 1000000
int dp[Max + 10];

int main(void) {
    int sequenceLength = 0;
    int startingNumber = 0;
    long long sequence;

    for (int i = 0; i < Max; i++) dp[i] = -1;
    dp[1] = 1;

    for (int i = 2; i < Max; i++) {
        sequence = i;
        int k = 0;
        while (sequence != 1 and sequence >= i) {
            k++;
            if ((sequence % 2) == 0) {
                sequence = sequence / 2;
            } else {
                sequence = sequence * 3 + 1;
            }
        }
        dp[i] = k + dp[sequence];
        if (dp[i] > sequenceLength) {
            sequenceLength = dp[i];
            startingNumber = i;
        }
    }
    cout << startingNumber << endl;
    return 0;
}
