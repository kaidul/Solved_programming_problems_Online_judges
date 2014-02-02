#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;


int main() {

    freopen("input.txt","r",stdin);
    //freopen("514_out.txt","w+",stdout);

    int n, i, val;
    bool found;
    while (scanf("%d",&n) && n) {
        while (1) {
            scanf("%d",&val);
            if (!val) {
                printf("\n");
                break;
            }

            stack<int> b;
            stack<int> s;
            b.push(val);
            for (i=1 ; i<n ; i++) {
                scanf("%d",&val);
                b.push(val);
            }

            for (i=n, found=true ; i>=1 && found ; i--) {
                if (!s.empty() && i==s.top()) {
                    s.pop();
                    continue;
                }
                while (1) {
                    if (!b.empty() && i!=b.top()) {
                        val = b.top();
                        s.push(val);
                        b.pop();
                        found=false;
                    } else if (!b.empty() && i==b.top()) {
                        b.pop();
                        found=true;
                        break;
                    } else {
                        found=false;
                        break;
                    }
                }
            }

            if (found) printf("Yes\n");
            else printf("No\n");
        }

    }
    return 0;

}
