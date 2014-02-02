#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int getSign(string& s, int &i) {
    if (s[i] == '+') {
        i++;
        return 1;
    }
    if (s[i] == '-') {
        i++;
        return -1;
    }
    return 1;
}

int getNumber(string& s, int& i, bool& got) {
    int result = 0;
    while(s[i] >='0' && s[i] <= '9') {
        result = result*10 + (s[i]-'0');
        i++;
        got = true;
    }
    return result;
}

bool getX(string& s, int& i) {
    return i < s.size() and s[i] == 'x' and ++i;
}

bool sideChange(string& s, int& i) {
    return i < s.size() and s[i] == '=' and ++i;
}


int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    string s;
    cin >> t;
    while(cin >> s) {
        int i = 0, A = 0, B = 0, masterSign = 1;
        while(i<s.size()) {
            int sign = getSign(s, i);
            bool got = false;
            int number = getNumber(s, i, got);
            bool isX = getX(s, i);
            if (isX and !got) number = 1;
            if (isX)
                B += -1*masterSign*sign*number;
            else
                A += masterSign*sign*number;
            if (sideChange(s, i))
                masterSign *= -1;
        }
        if (!A and !B) {
            cout << "IDENTITY" << endl;
        } else if (!B) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << (int) floor( ( (double)A / B) ) << endl;
        }
    }
    return 0;
}
