#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#define pb push_back
#define MAX 1000000
using namespace std;
map <string, int> m;
int value = 1;
void making_map(string s, int n) {
    if(s.size() == n) {
        m[s] = value++;
        return;
    }
    char last;
    if(s.size() == 0)
        last = 'a';
    else
        last = s[s.size() - 1] + 1;
    for(char i = last; i <= 'z'; i++)
        making_map(s + i, n);
}
int main() {
    string input;
    for(int i = 1; i <= 5; i++)
        making_map("", i);
    while(cin >> input )
        cout << m[input] << endl;
    return 0;
}
