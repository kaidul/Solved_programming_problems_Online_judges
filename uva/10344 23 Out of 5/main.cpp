#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[5];
char ans[2][12] = { "Impossible", "Possible" };

int find(int sum, int i) {
    if (i == 5)
        return sum == 23;
    return find(sum + a[i], i + 1) || find(sum - a[i], i + 1) || find(sum * a[i], i + 1) ;
}

int main(void) {
    while (~scanf("%d %d %d %d %d", a + 0, a + 1, a + 2, a + 3, a + 4) and a[0] and a[1] and a[2] and a[3] and a[4] ) {
        sort(a, a + 5);
        int found = 0;
        do {
            if ( found |= find(a[0], 1) )
                break;
        } while (next_permutation(a, a + 5));

        cout << ans[found] << endl;
    }
    return 0;
}
