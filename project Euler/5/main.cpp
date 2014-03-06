#include <bits/stdc++.h>

#define Max 20

using namespace std;

int status[(Max / 32) + 2];
vector <int> primeList;

bool Check(int N, int pos) {
    return (bool)( N & (1 << pos) );
}
int Set(int N, int pos) {
    return N = N | (1 << pos);
}

void RSieve(int N) {
    primeList.clear();
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2) {
        if( !Check( status[i >> 5], i & 31 ) ) {
            for( j = i*i; j <= N; j += (i << 1) ) {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }
    primeList.push_back(2);
    for(i=3; i < N; i += 2)
        if( !Check( status[i >> 5], i & 31 ) )
            primeList.push_back(i);
}

//Hints: http://www.mathblog.dk/project-euler-problem-5/
// another way is to calculating LCM of all numbers(1-20)

#define eps 1e-9

int main(void) {
    RSieve(Max);
    int a, result = 1;
    for(int i = 0, n = primeList.size(); i < n; ++i) {
        a = (int) floor( log(Max) / log(primeList[i]) );
        result *= pow(primeList[i], a) + eps;
    }
    cout << result << endl;
    return 0;
}
