#include <iostream>
#include <algorithm>
#include <cstdio>
#define sf scanf
using namespace std;

int main() {
    int sum, result, relatives[505], n, tcase;
    sf("%d", &tcase);
    while(tcase--) {
        result = 1 << 30;
        sf("%d", &n);
        for(int i = 0; i < n; i++) sf("%d", &relatives[i]);
        sort(relatives, relatives + n);
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                sum += abs(relatives[i] - relatives[j]);
            }
            result = min(result, sum);
        }
        printf("%d\n", result);
    }
    return 0;
}
