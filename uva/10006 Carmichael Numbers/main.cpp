#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX 65000

int Carmichael[MAX];
int prime[MAX];

long long int  bigmod ( long long a, int p, int m ) {
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), 1 is must to be the mod , so return 1

    if ( p % 2 ) { // If power is odd, a ^ 7 = a * a ^ 6
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m; // Multipication      may exceed int range
    } else {
        long long c = bigmod ( a, p / 2, m ); // Multipication may exceed int range
        return ( (c%m) * (c%m) ) % m;
    }
}


void sieve_prime() {


    for(int i = 2; i <= MAX; i++)
        prime[i] = 1;   //assuming all as primes
    int k = 2;
    for(int m = 2; m <= sqrt((double) MAX); m++) {
        for(int j = k + k; j <= MAX; j = j + k) {
            prime[j] = 0;
        }
        k++;
        for(; !prime[k]; k++); //looking for nearest green (prime)
    }
}




void preCalCarmichael() {
    int i, j;

    for(i = 3; i < MAX; i++) { //n
        if(prime[i] == 0) {

            for(j = 2; j < i; j++) { //a

                if(bigmod(j, i, i) == j) {
                    Carmichael[i] = 1;
                } else {
                    Carmichael[i] = 0;
                    break;
                }
            }
        }
    }

}

int main() {
    sieve_prime();
    preCalCarmichael();

    freopen("input.txt", "r", stdin);


    int num;

    while(scanf("%d", &num) && num) {
        if(Carmichael[num])
            printf("The number %d is a Carmichael number.\n", num);
        else printf("%d is normal.\n", num);

    }



    return 0;
}
