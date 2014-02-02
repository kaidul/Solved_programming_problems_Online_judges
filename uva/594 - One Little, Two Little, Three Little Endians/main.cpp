/*
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
union {
    int value;
    char ch[4];
} input, result;

int main() {
    freopen("in.txt", "r", stdin);
    long int N;
    while(cin >> input.value) {
        for(int i = 0, j = 3; i < 4; i++, j--) result.ch[i] = input.ch[j];
        cout << input.value << " converts to " << result.value << "\n";
    }
    return 0;
}

*/
#include <cstdio>
#include <iostream>
#include<fstream>
using namespace std;
#define SWAP(a,b) a= a^b, b=a^b, a=a^b

int main() {
    freopen("in.txt", "r", stdin);
    int input, reverse;
    while (cin >> input) {
        reverse = input;
        char * bits = (char*) &reverse;
        SWAP(bits[0], bits[3]), SWAP(bits[1], bits[2]);
        printf("%d converts to %d\n", input, reverse);
    }
    return 0;
}
