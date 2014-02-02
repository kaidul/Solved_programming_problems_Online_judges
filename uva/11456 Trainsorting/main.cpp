/**
1. Erin can choose to start making the train from any point of the arrivals of the cars. So she may have started to make the train from either 1st or n-1st or nth or n/2nd, any point.

2. And from the point in time where she starts this, she checks if the new car is smaller in weight than the last car of her train or higher in weight than the first car or vice versa.

3. So the sorting can start from any point and the optimal choice is at any point.
Ofcourse you have to use LIS, but you also need LDS. Why??
Because suppose she starts from position i. Since she wants to make the train as long as possible so she must make sure the train is optimal from the last till i. Then after i she wants to join the longest possible train using the cars i + 1 to n. So, she wants to join the LIS(1 -> i) with LDS(i + 1 -> n).

In my solution, I subtracted 1 from LIS(i) + LDS(i) because in both the i car is present. So erased it from 1 of them.
**/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define INF (1<<30)
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define SDi(x) sf("%d",&x)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)

#define M 2001

int I[M], N, dp[M], cache[M];
vector <int> data;
void _reset() {
    mem(dp, -1);
}

void LisNlogk() {
    //_reset();
    int i;
    I[0] = -INF;
    for(int i = 1; i <= N + 1; i++) I[i] = INF;

    int trackPosition = 0;
    for(i = 0; i < N; i++ ) {
        int begin, end, mid;
        begin = 0;
        end = trackPosition;
        while( begin <= end ) {
            mid = ( begin + end ) / 2;
            if( I[mid] < data[i] )
                begin = mid + 1;
            else
                end = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // begin > end and we put our item in I[begin]
        I[begin] = data[i];
        dp[i] = begin; // storing the LIS of every position
        if( trackPosition < begin )
            trackPosition = begin;
    }
}

void LdsNlogk() {
    //_reset();
    int i;
    I[0] = INF;
    for(int i = 1; i <= N + 1; i++) I[i] = -INF;

    int trackPosition = 0;
    for(i = 0; i < N; i++ ) {
        int begin, end, mid;
        begin = 0;
        end = trackPosition;
        while( begin <= end ) {
            mid = ( begin + end ) / 2;
            if( I[mid] > data[i] )
                begin = mid + 1;
            else
                end = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // begin > end and we put our item in I[begin]
        I[begin] = data[i];
        cache[i] = begin; // storing the LIS of every position
        if( trackPosition < begin )
            trackPosition = begin;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        READ("input.txt");
    #endif
    int tcase, temp, caseNo = 0, ans;
    SDi(tcase);
    while(tcase--) {
        SDi(N);
        rep(i, N) SDi(temp), data.pb(temp);

        reverse(all(data)); // don't know y
        LisNlogk();
        LdsNlogk();
        ans = 0;
        rep(i, N) ans = max(ans, dp[i] + cache[i] - 1);
        println(ans);
        data.clear();
    }
    return 0;
}
