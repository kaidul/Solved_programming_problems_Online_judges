#include<iostream>
#include<cstdio>
using namespace std;
int a[120][120], b[120], n, sum, ms;
int main() {
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        ms =- 99999999;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        for(int i = 0; i < n; i++) { //1,2,.....n times following kaj korbe
            /*
            j=ith row theke nicher n porjonto protita row er jonno
            abar z=0....n protita column er jonno  submatrix er sum
            protita row erjonno sum gula b[z] array te store kora thakbe
            at 1st b[1,2,....n] shobgula 0 thakbe .....
            b[z]=b[z]+a[j][z];
            pore b[z] er protita element e a[i][z] er protita element sum hisebe thakbe
            b[z] hobe oi row er jonno sum storing array_sum+=b[z];
            ..... b[z] er protita element
            sum er shathe added hobe....so, sum e thakbe oi row er jonno shobgula element er jogfol
            ar protita row er jonno maximum sum ta ms e store kora hobe
            */
            for(int j = 0; j < n; j++) b[j] = 0;
            for(int j = 0; j < n; j++) {
                for(int x = 0; x < n; x++)
                    b[x] += a[(i + j) % n][x]; //b[z]+=a[j][z];
                for(int x = 0; x < n; x++) {
                    sum = 0;
                    for(int z = 0; z < n; z++) {

                        sum += b[(x + z) % n];//sum+=b[z];
                        ms = max(ms, sum);
                    }
                }
            }
        }
        cout << ms << endl;
    }
    return 0;
}
