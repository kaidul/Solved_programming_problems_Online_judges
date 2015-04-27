#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 55
int arr[MAX];

int main() {
    int n, caseNo = 0;
    while(scanf("%d", &n)) {
        if(n == 0) break;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        int avg = sum / n;
        int result = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] > avg) result += arr[i] - avg;
        }
        printf("Set #%d\n", ++caseNo);
        printf("The minimum number of moves is %d.\n\n", result);
    }
    return 0;
}
