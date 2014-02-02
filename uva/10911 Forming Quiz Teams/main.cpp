#include <bits/stdc++.h>
#define _ ios_base:sync_with_stdio(0);cin.tie(0);
using namespace std;

#define Max 8

struct student {
    string name;
    int x;
    int y;
};

int n, maxN;
student students[16];
bool taken[16];
double result;
double current_result;

double mydistance(int a, int b) {
    return sqrt((students[a].x - students[b].x) * (students[a].x - students[b].x) + (students[a].y - students[b].y) * (students[a].y - students[b].y));
}
/**
 classical approach
**/
void solve(int depth) {
    if (depth == n) {
        if (current_result < result)
            result = current_result;
        return;
    }

    int member1;

    // grab any available student
    for (int i = 0, size = 2 * n; i < size; i++) {
        if (taken[i] == false) {
            member1 = i;
            taken[i] = true;
            break;
        }
    }

    // go over all available pairs for selected student
    for (int i = 0, size = 2 * n; i < size; i++) {
        if (taken[i] == false) {
            double d = mydistance(member1, i);
            // if current_result exceeds result
            if (current_result + d < result) {
                //printf("%d %d\n", member1 + 1, i + 1);
                current_result += d;
                taken[i] = true;
                // recursion
                solve(depth + 1);
                // backtrack
                current_result -= d;
                taken[i] = false;
            }
        }
    }

    taken[member1] = false;
}

double dp[(1 << (Max * 2)) + 1];

int Set(int N, int pos) {
    return N = N | (1 << pos);
}

bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}
/**
  Bitmask - trying 2 ^ 16 combination
**/
double pairup(int mask) {
    if (mask == maxN)
        return 0;
    if (dp[mask] != 0)
        return dp[mask];

    double ans = INT_MAX;
    int p1, p2;

    for (p1 = 0; p1 < 2* n; p1++) {
        if ( !Check(mask, p1) )
            break;
    }
    for (p2 = p1 + 1; p2 < 2 * n; p2++) {
        if ( !Check(mask, p2) ) {
            printf("%d %d\n", p1, p2);
            ans = min(ans, mydistance(p1, p2) + pairup( Set(Set(mask, p1), p2) ) );
        }
    }

    return dp[mask] = ans;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int cases = 0;

    while (cin >> n) {
        if (n == 0)
            break;
        cases++;
        current_result = 0;
        result = INT_MAX;

        //memset(taken, false, sizeof taken);
        memset(dp, 0, sizeof dp);

        for (int i = 0, size = 2 * n; i < size; i++) {
            cin >> students[i].name >> students[i].x >> students[i].y;
        }

        //solve(0);
        maxN = (1 << (2 * n)) - 1;
        cout << "Case " << cases << ": " << fixed << setprecision(2) << pairup(0) << endl;
    }

    return 0;
}
