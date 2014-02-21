#include <bits/stdc++.h>
#define infinity (1 << 30)
using namespace std;

int n, m, k;
string A, B;

struct couple {
    string x, y;
    couple(string a, string b) : x(a), y(b) {}
    bool operator < (const couple &other) const {
        if(x.compare(other.x) == 0) return y.compare(other.y) < 0;
        return x.compare(other.x) < 0;
    }
};
set <couple> Solution;

bool isGameOver(string &a, string &b, int indx1, int indx2) {
    if(a == A and b == B) return true;
    if(indx1 == n - 1 and indx2 == m - 1) return true;
    return false;
}

int minValue(string &a, string &b, int indx1, int indx2);

int maxValue(string &a, string &b, int indx1, int indx2) {
    if(isGameOver(a, b, indx1, indx2)) return -1;
    int ret, best = -infinity;
    for(int i = indx1 + 1; i < n; ++i) {
        a += A[i];
        ret = minValue(a, b, i, indx2);
        if(ret == -1) Solution.insert( couple(a, b) );
        a.erase(a.length() - 1, 1);
        best = max(best, ret);
    }
    for(int i = indx2 + 1; i < m; ++i) {
        b += B[i];
        ret = minValue(a, b, indx1, i);
        if(ret == -1) Solution.insert( couple(a, b) );
        b.erase(b.length() - 1, 1);
        best = max(best, ret);
    }
    return best;
}

int minValue(string &a, string &b, int indx1, int indx2) {
    if(isGameOver(a, b, indx1, indx2)) return +1;
    int ret, best = infinity;
    for(int i = indx1 + 1; i < n; ++i) {
        a += A[i];
        ret = maxValue(a, b, i, indx2);
        if(ret == 1) Solution.insert( couple(a, b) );
        a.erase(a.length() - 1, 1);
        best = min(best, ret);
    }
    for(int i = indx2 + 1; i < m; ++i) {
        b += B[i];
        ret = maxValue(a, b, indx1, i);
        if(ret == 1) Solution.insert( couple(a, b) );
        b.erase(b.length() - 1, 1);
        best = min(best, ret);
    }
    return best;
}

void minimax(string a, string b) {
    int indx1 = -1, indx2 = -1;
    int ret, best = -infinity;
    for(int i = indx1 + 1; i < n; ++i) {
        a += A[i];
        ret = minValue(a, b, i, indx2);
        if(ret == -1) Solution.insert( couple(a, b) );
        a.erase(a.length() - 1, 1);
        best = max(ret, best);
    }
    for(int i = indx2 + 1; i < m; ++i) {
        b += B[i];
        ret = minValue(a, b, indx1, i);
        if(ret == -1) Solution.insert( couple(a, b) );
        b.erase(b.length() - 1, 1);
        best = max(ret, best);
    }
    if(best == 1) Solution.insert( couple("", "") );
    if(Solution.size() == 0) {
        cout << "no solution" << endl;
        return;
    }
    set <couple>:: iterator it = Solution.begin();
    advance(it, k - 1);
    cout << (*it).x << endl;
    cout << (*it).y << endl;
//    while( it != Solution.end() ) {
//        cout << (*it).x << " " <<  (*it).y << endl;
//        ++it;
//    }
}

int main(void) {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    cin >> A >> B;
    if(A == "" and B == "") {
        cout << "no Solution" << endl;
        return 0;
    }
    minimax("", "");
    return 0;
}
