#include <bits/stdc++.h>

using namespace std;

int main(void) {
//    freopen("input.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    map <char, int> freqA, freqB;
    for(int i = 0, n = a.length(); i < n; ++i) {
        ++freqA[a[i]];
    }
    for(int i = 0, n = b.length(); i < n; ++i) {
        ++freqB[b[i]];
    }
    char c;
    int cnt = 0;
    for(int i = 97; i <= 122; ++i) {
        c = (char) i;
        cnt += abs(freqA[c] - freqB[c]);
    }
    cout << cnt << endl;
    return 0;
}
