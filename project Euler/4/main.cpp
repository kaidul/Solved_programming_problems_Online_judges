#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    int len = str.length();
    for(int i = 0, j = len - 1; i <= j; ++i, --j) {
        if(str[i] != str[j]) return false;
    }
    return true;
}

int main(void) {
    int low = 100, high = 999, product;
    string str;
    int Max = -1;
    for(int i = low; i <= high; ++i) {
        for(int j = low; j <= high; ++j) {
            product = i * j;
            ostringstream convert;
            convert << product;
            str = convert.str();
            if( isPalindrome(str) ) {
                Max = max(Max, product);
            }
        }
    }
    cout << Max << endl;
    return 0;
}
