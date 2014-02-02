#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <bitset>

using namespace std;

#define Max 10000
const double eps = 1e-10;

struct Interval {
    double st, en;
    Interval() {}
    Interval(double s, double e) {
        st = s, en = e;
    }
    bool operator < (const Interval &i) const {
        return (i.en == en) ? (st < i.st) : (en < i.en);
    }
};
long double x[Max], y[Max];
Interval inter[Max];

//bujhlam na baal
int main(void) {
    int n, d, testcase = 0;
    while(scanf("%d %d", &n, &d) == 2 && !(n == 0 && d == 0)) {
        for(int i = 0; i < n; i++)
            scanf("%Lf %Lf", &x[i], &y[i]);
        int count = 0, ok = true;
        for(int i = 0; i < n; i++) {
            if(d < y[i]) { // if island is out of radar radious
                ok = false; // that means at least one of the islands is not reachable results in -1
                break;
            } else {
                long double sqrtd = sqrt( d * d - y[i] * y[i] );
                inter[i] = Interval(x[i] - sqrtd, x[i] + sqrtd);
            }
        }
        if(!ok) {
            printf("Case %d: %d\n", ++testcase, -1);
            continue;
        }
        sort(inter, inter + n);

        for(int i = 0; i < n;) {
            int j;
            for(j = 0; j < n; j++) {
                if(inter[j].st > inter[i].en)
                    break;
            }
            i = j;
            count++;
        }
        printf("Case %d: %d\n", ++testcase, count);
    }
    return 0;
}
