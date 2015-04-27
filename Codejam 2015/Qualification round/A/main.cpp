#include <iostream>
#include <cstdio>

using namespace std;

#define DEBUG 0

int main(void) {
#ifdef DEBUG
//    freopen("A-small-attempt0.in", "r", stdin);
//    freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif // DEBUG
    int tcase, caseNo = 0;
    scanf("%d", &tcase);
    char ch;
    int n;
    while(tcase--) {
        scanf("%d", &n);
        int friendsToInvite, audience  = 0, result = 0;
        ch = getchar();
        for(int k = 0; k <= n; ++k) {
            ch = getchar();
            friendsToInvite = k - audience;
            if(friendsToInvite > 0) {
                result += friendsToInvite;
                audience += friendsToInvite;
            }
            audience += ch - '0';
        }
        printf("Case #%d: %d\n", ++caseNo, result);
        ch = getchar();
    }
    return 0;
}
