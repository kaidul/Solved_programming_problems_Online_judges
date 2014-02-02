#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    map <char, char> reverse;
    reverse['A'] = 'A';
    reverse['E'] = '3';
    reverse['H'] = 'H';
    reverse['I'] = 'I';
    reverse['J'] = 'L';
    reverse['L'] = 'J';
    reverse['M'] = 'M';
    reverse['O'] = 'O';
    reverse['S'] = '2';
    reverse['T'] = 'T';
    reverse['U'] = 'U';
    reverse['V'] = 'V';
    reverse['W'] = 'W';
    reverse['X'] = 'X';
    reverse['Y'] = 'Y';
    reverse['Z'] = '5';
    reverse['1'] = '1';
    reverse['2'] = 'S';
    reverse['3'] = 'E';
    reverse['5'] = 'Z';
    reverse['8'] = '8';
    string input;
    while (getline(cin, input)) {
        bool isPalindrome = true, isMirror = true;
        for (int i = 0, n = input.size(), j = n - 1; i <= j; i++, j--) {
            if(input[i] != input[j])
                isPalindrome = false;
            if(reverse[ input[i] ] != input[j])
                isMirror = false;
            if (!isMirror and !isPalindrome)
                break;
        }
        if (isPalindrome and isMirror) {
            printf("%s -- is a mirrored palindrome.", input.c_str());
        } else if (isPalindrome) {
            printf("%s -- is a regular palindrome.", input.c_str());
        } else if (isMirror) {
            printf("%s -- is a mirrored string.", input.c_str());
        } else {
            printf("%s -- is not a palindrome.", input.c_str());
        }
        printf("\n\n");
    }
    return 0;
}
