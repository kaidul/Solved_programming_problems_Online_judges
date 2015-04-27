#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
string arr[MAXN];

double stringToDouble(string str) {
    return atof(str.c_str());
}

bool Compare(const string& a, const string& b) {
    double doubleA = stringToDouble(a);
    double doubleB = stringToDouble(b);
    return doubleA < doubleB;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int tcase;
    scanf("%d", &tcase);
    int N;
    string elem;
    while(tcase--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        stable_sort(arr, arr + N, Compare);
        for(int i = 0; i < N - 1; ++i) {
            cout << arr[i] << ",";
        }
        if(N > 0) cout << arr[N - 1] << endl;
    }
    return 0;
}
