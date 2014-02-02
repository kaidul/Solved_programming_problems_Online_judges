#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define INF 1 << 30
#define Max 100

int data[] = {21, 2, 7, 3, 4, 5, 1, 6, 9, 32, 11, 13, 23, 17, 8};
const size_t arrLength = sizeof data / sizeof(data[0]);


/*  Top Down Approach  */
int cache[Max][Max];

int RMQ(int begin, int end) {
    if(cache[begin][end] != -1) return cache[begin][end];
    if(begin == end) return cache[begin][end] = begin;
    if(begin > end) return -1;
    return cache[begin][end] = (data[RMQ(begin, end - 1)] < data[end]) ? RMQ(begin, end - 1) : end;
}


/*  Bottom up Approach  */
int dp[Max][Max];

void RMQ() {
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < arrLength; i++) {
        for (int j = i; j < arrLength; j++) {
            if(i == j) dp[i][j] = i;
            else dp[i][j] = (data[dp[i][j - 1]] < data[j]) ? dp[i][j - 1] : j;
        }
    }
}

void update(int index, int item) {
    data[index] = item;
}

int main() {
    memset(cache, -1, sizeof cache);
    cout << RMQ(0, 8) << "\n";

    RMQ();
    cout << dp[0][8] << "\n";

    update(6, 100);
    RMQ();
    cout << dp[0][8];

    return 0;
}
