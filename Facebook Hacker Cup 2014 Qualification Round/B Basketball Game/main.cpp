#include <bits\stdc++.h>

using namespace std;
#define DEBUG 1
#define Max 31
#define N 21
struct playerInfo {
    string name;
    int shot, height;
    playerInfo() {}
    playerInfo(string a, int b, int c) : name(a), shot(b), height(c) {}
    bool operator < (playerInfo const& other) const {
        if(shot == other.shot) return height > other.height;
        return shot > other.shot;
    }
} player[Max];

int main(void) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("basketball_game.txt", "w", stdout);
#endif
    int tcase, caseNo = 0;
    scanf("%d", &tcase);
    int n, m, p;
    char name[N];
    int shot, height;
    while (tcase--) {
        queue < string > teamA, teamB, waitingA, waitingB;
        priority_queue < string, vector<string>, greater<string> > result;
        scanf("%d %d %d", &n, &m, &p);
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", &name, &shot, &height);
            player[i] = playerInfo(string(name), shot, height);
        }
        printf("Case #%d: ", ++caseNo);
        if(2 * p == n) {
            for (int i = 0; i < n; i++) {
                result.push(player[i].name);
            }
            while (!result.empty()) {
                printf("%s ", result.top().c_str() );
                result.pop();
            }
            putchar('\n');
            continue;
        }
        sort(player, player + n);
        for (int i = 2 * p - 1; i >= 0; i--) {
            if(i & 1) teamB.push( player[i].name );
            else teamA.push( player[i].name );
        }
        for (int i = 2 * p; i < n; i++) {
            if(i & 1) waitingB.push( player[i].name );
            else waitingA.push( player[i].name );
        }
        string out, in;
        while (m--) {
            out = teamA.front();
            teamA.pop();
            in = waitingA.front();
            waitingA.pop();
            teamA.push(in);
            waitingA.push(out);

            out = teamB.front();
            teamB.pop();
            in = waitingB.front();
            waitingB.pop();
            teamB.push(in);
            waitingB.push(out);
        }
        while ( !teamA.empty() ) {
            result.push( teamA.front() );
            teamA.pop();
        }
        while ( !teamB.empty() ) {
            result.push( teamB.front() );
            teamB.pop();
        }
        while ( !result.empty() ) {
            printf("%s ", result.top().c_str());
            result.pop();
        }
        putchar('\n');
    }
    return 0;
}
