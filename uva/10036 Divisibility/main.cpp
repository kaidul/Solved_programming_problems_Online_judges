#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 101

bool dp[Max];
int n, k;

/**
Looks simple but if you use brute force (count all possible values of +/- for N numbers) then determine whether it is divisible by K or not, then your solutions possibly get Time Limit Exceeded.

Use mathematical properties + Dynamic Programming

Let d[1],...,d[N] be sequence of N integers and t[I,J] (2 dimensional array, but after some considerations, we'll find out that we only need 2 linear array of size J) be true iff we can place +/- operators in the sequence of first I integers so that result = J (mod K).

We can use DP to calculate t[I,J] for all [I,J]:

for i=1
t[1,j] = true for t[1,j] where j=abs(d[1]) mod K

This means: You divide one integer (the first integer from N integers) with K, get the remainder, t[1,remainder] is set to be true.

for i>1
if t[i-1,j] true then
  t[i,(j+abs(d[i]) mod K] = true // add
  t[i,(j+K-abs(d[i]) mod K] = true // subtract

This means: For the 2nd integer up to Nth integer, you either add it with previous remainder modulo K or substract it with previous remainder modulo K, to get another remainders in the range [0..K] that can be reached using combination of i integers.

Answer should be Divisible iff t[N,0], which means, you can arrange +/- operators in the sequence of N integers, with remainder 0 / divisible.
**/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d", &tcase);
    int X;
    vector <int> prev;

    while(tcase--) {
        memset(dp, false, sizeof dp);
        scanf("%d %d", &n, &k);
        scanf("%d", &X);
        dp[ abs(X) % k ] = true;

        for (int i = 1; i < n; i++) {
            scanf("%d", &X);
            prev.clear();

           for (int i = 0; i < k; i++) {
                if( dp[i] ) {
                    prev.push_back(i);
                    dp[i] = false;
                }
            }

            for (int j = 0, length = (int) prev.size(); j < length; j++) {
                dp[ (prev[j] + abs(X) % k) % k ] = true;
                dp[ (prev[j] + k - abs(X) % k) % k ] = true;
            }

        }

        if(dp[0]) {
            printf("Divisible\n");
        } else {
            printf("Not divisible\n");
        }


    }

    return 0;
}
