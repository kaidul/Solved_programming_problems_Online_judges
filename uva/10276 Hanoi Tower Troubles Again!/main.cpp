#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

/*
Process
I would categorize this problem as a simulation one. It can be solved easily by writing a method that follows the rules and fills the tower. Basically, you go in order through the balls starting at 1, 2, 3… and try to place them such that the ball and the one under sum to a perfect square. If no rod has a ball on the top such that this condition can be met, place the ball on an empty rod. If no empty rods exist and no rod can fulfill the condition, the simulation is over. It should be apparent then that the case mentioned in the problem (-1 if infinite balls can be placed), is not possible and so you should not bother figuring that out. Also you need only keep track of the last ball on the stack
*/
int T, N, total;
int peg[100];

void simul(int indx, int p) {
    if(p == N) return;
    if(peg[p] == 0) {
        peg[p] = indx;
        total++;
        simul(indx + 1, p);
        return;
    }

    for(int i = 0; i <= p; i++) {
        int root = (int) sqrt(peg[i] + indx);
        if(root * root == peg[i] + indx) {
            peg[i] = indx;
            total++;
            simul(indx + 1, p);
            return;
        }
    }

    simul(indx, p + 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        memset(peg, 0, sizeof peg);
        total = 0;
        simul(1, 0);
        printf("%d\n", total);
    }
}
