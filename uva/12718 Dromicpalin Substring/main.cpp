#include <bits/stdc++.h>

#define Max 1005

using namespace std;

int main(void) {
//    freopen("input.txt", "r", stdin);
    int tcase, caseNo = 0;;
    char input[Max];
    scanf("%d", &tcase);
    getc(stdin);
    while (tcase--) {
        gets(input);
        int total = 0;
        int length = strlen(input);
        //total += length;
        for(int i = 0; i < length; ++i) {
            map <char, int> parity;
            int oddParity = 0, previous, j;
            for(int k = 0; k < length - i; ++k) {
                j = i + k;
                previous = parity[input[j]];
                ++parity[input[j]];
                if(parity[input[j]] == 1)
                    ++oddParity;
                else if(previous & 1)
                    --oddParity;
                else
                    ++oddParity;
//                map <char, bool> taken;
//                for(int indx = i; indx <= j; ++indx) {
//                    if(parity[input[indx]] & 1 and !taken[input[indx]]) {
//                        ++oddParity;
//                        taken[input[indx]] = true;
//                    }
//                }
                if(oddParity < 2)
                    total++;
            }
        }
//        for(int k = 1; k < length; ++k) {
//            for(int i = 0; i < length - k; ++i) {
//                int j = i + k;
//                map <char, int> parity;
//                for(int indx = i; indx <= j; ++indx) {
//                    ++parity[input[indx]];
//                }
//                int oddParity = 0;
//                map <char, bool> taken;
//                for(int indx = i; indx <= j; ++indx) {
//                    if(parity[input[indx]] & 1 and !taken[input[indx]]) {
//                        ++oddParity;
//                        taken[input[indx]] = true;
//                    }
//                }
//                if(oddParity < 2)
//                    total++;
//            }
//        }
        printf("Case %d: %d\n", ++caseNo, total);
    }
    return 0;
}
