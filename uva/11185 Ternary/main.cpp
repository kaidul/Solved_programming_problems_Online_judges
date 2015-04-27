#include <iostream>
#include <cstdio>

using namespace std;

string ternary(int n) {
    string res = "";
    while(n) {
        if(n % 3 == 0) res = "0" + res;
        else if(n % 3 == 1) res = "1" + res;
        else res = "2" + res;
        n /= 3;
    }

    return res;
}

int main() {
    int n;
    while(scanf("%d", &n) and n >= 0) {
        cout << ternary(n) << endl;
    }
    return 0;
}
