#include <cstdio>
#include <iostream>

using namespace std;

#define Max 21

int main(void) {
//    freopen("input.txt", "r", stdin);
//    freopen("square_detector.txt", "w", stdout);
    int tcase, caseNo = 0;
    int n, count = 0, start = 0, end = 0, row;
    char grid[Max][Max];
    scanf("%d", &tcase);
    bool yes, first;
    while (tcase--) {
        yes = first = true;
        scanf("%d", &n);
        getc(stdin);
        for (int i = 0; i < n; i++) {
            gets(grid[i]);
            int j = 0;
            if(yes) {
                for (j = 0; j < n; j++) {
                    if(grid[i][j] == '#' and first == true) {
                        first = false;
                        start = j;
                        row = i;
                        for (j = j + 1; j < n; j++) {
                            if(grid[i][j] != '#') {
                                end = j - 1;
                                for (j = j + 1; j < n; j++) {
                                    if(grid[i][j] == '#') {
                                        yes = false;
                                        break;
                                    }
                                }
                            }
                            if(yes == false) break;
                        }
                        end = n - 1;
                        //if(yes == false) break;
                    } else if (first == false) {
                        if(i <= (row + end - start)) {
                            for (j = 0; j < start; j++) {
                                if(grid[i][j] == '#') {
                                    yes = false;
                                    break;
                                }
                            }
                            for (j = start; j <= end; j++) {
                                if(grid[i][j] != '#') {
                                    yes = false;
                                    break;
                                }
                            }
                            for (j = end + 1; j < n; j++) {
                                if(grid[i][j] == '#') {
                                    yes = false;
                                    break;
                                }
                            }
                        } else {
                            for (j = 0; j < n; j++) {
                                if(grid[i][j] == '#') {
                                    yes = false;
                                    break;
                                }

                            }
                        }
                        if(yes == false) break;
                    }
                }
            }
        }
        if(yes) printf("Case #%d: YES\n", ++caseNo);
        else printf("Case #%d: NO\n", ++caseNo);
    }
    return 0;
}
