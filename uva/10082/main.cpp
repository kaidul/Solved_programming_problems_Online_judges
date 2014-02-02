#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    string rep = "QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.`1234567890-";
    string ori = "WERTYUIOP[]\\SDFGHJKL;’XCVBNM,./1234567890-=";
    bool done;
    char c;
    while(scanf("%c",&c) != EOF) {
        done=false;
        for(int i= 0; i < ori.length(); i++) {
            if( ori[i] == c ) {
                cout << rep[i];
                done = true;
                break;
            }
        }
        if(!done) cout << c;
    }
    return 0;
}
