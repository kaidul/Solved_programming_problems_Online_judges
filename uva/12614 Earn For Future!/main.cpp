#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)

/** function **/
#define SDi(x) sf("%d",&x)
#define sf scanf
#define pf printf
#define READ(f) freopen(f, "r", stdin)

int main() {
    READ("input.txt");
    int tcase, caseNo = 1, card_no, card, amount;
    SDi(tcase);
    while(tcase--) {
        SDi(card_no);
        amount = -1;
        rep(i, card_no) SDi(card), amount = max(amount, card);
        pf("Case %d: %d\n", caseNo, amount);
        caseNo++;
    }
    return 0;
}
