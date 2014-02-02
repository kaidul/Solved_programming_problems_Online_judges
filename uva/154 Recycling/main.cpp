#include <iostream>
#include <cstdio>
#include <map>
using namespace std ;

int main() {
    freopen("input.txt", "r", stdin);
    map<char, int> colors;
    map<char, int> materials;
    int cities[101][5];
    string s;
    int i, j, k, cnt, dif, minDif, min;
    colors['b'] = 0;
    colors['g'] = 1;
    colors['o'] = 2;
    colors['r'] = 3;
    colors['y'] = 4;
    materials['A'] = 0;
    materials['G'] = 1;
    materials['N'] = 2;
    materials['P'] = 3;
    materials['S'] = 4;

    while (true) {
        cnt = 0;
        while (true) {
            cin >> s;
            if (s[0] == 'e')
                goto solve;
            else if (s[0] == '#')
                return 0;
            j = 0;
            while (j < s.length()) {
                cities[cnt][colors[s[j]]] = materials[s[j + 2]];
                j += 4;
            }
            cnt++;
        }
solve:
        minDif = 100000;
        min = 0;
        //loop over history to find the winner city
        for(i = 0 ; i < cnt; i ++) {
            dif = 0;
            for(j = 0 ; j < cnt ; j++) {
                if (i == j) continue;
                for(k = 0 ; k < 5 ; k++) {
                    if (cities[i][k] != cities[j][k])
                        dif++;
                }
            }
            if (dif < minDif) {
                minDif = dif;
                min = i;
            }
        }
        cout << min + 1 << endl;
    }
    return 0;
}
