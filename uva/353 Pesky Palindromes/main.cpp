#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

string input;
map <string, bool> unique;
bool isPalindrome (int lower, int upper) {
    string substring = input.substr(lower, upper - lower + 1);
    if (unique[ substring ])
        return false;
    unique[substring] = true;
    for (int i = lower, j = upper; i <= j; i++, j--) {
        if(input[i] != input[j])
            return false;
    }
    return true;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (getline(cin, input)) {
        unique.clear();
        int n = input.size();
        int totalPalindrome = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                totalPalindrome += isPalindrome(i, j);
            }
        }
        printf("The string '%s' contains %d palindromes.\n", input.c_str(), totalPalindrome);
    }
    return 0;
}
