#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
using namespace std;

int main() {
    char first, second, third;
    int B[3], G[3], C[3], smallest, tmp; // bottle
    while(scanf("%d %d %d %d %d %d %d %d %d", &B[0], &G[0], &C[0], &B[1], &G[1], &C[1], &B[2], &G[2], &C[2]) != EOF) {
        smallest = B[1] + B[2] + C[0] + C[2] + G[0] + G[1]; // BCG
        first = 'B';
        second = 'C';
        third = 'G';
        tmp = B[1] + B[2] + G[0] + G[2] + C[0] + C[1]; // BGC
        if(tmp < smallest) {
            smallest = tmp;
            first = 'B';
            second = 'G';
            third = 'C';
        }

        tmp = C[1] + C[2] + B[0] + B[2] + G[0] + G[1]; // CBG
        if(tmp < smallest) {
            smallest = tmp;
            first = 'C';
            second = 'B';
            third = 'G';
        }

        tmp = C[1] + C[2] + G[0] + G[2] + B[0] + B[1]; // CGB
        if(tmp < smallest) {
            smallest = tmp;
            first = 'C';
            second = 'G';
            third = 'B';
        }

        tmp = G[1] + G[2] + B[0] + B[2] + C[0] + C[1]; // GBC
        if(tmp < smallest) {
            smallest = tmp;
            first = 'G';
            second = 'B';
            third = 'C';
        }

        tmp = G[1] + G[2] + C[0] + C[2] + B[0] + B[1]; // GCB
        if(tmp < smallest) {
            smallest = tmp;
            first = 'G';
            second = 'C';
            third = 'B';
        }
        cout << first << second << third << " " << smallest << endl;
    }
    return 0;
}
