#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <climits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define RESET(t,value) memset((t), value, sizeof(t))

#define READ(f) freopen(f, "r", stdin)

#define INF (1<<30)
#define pb push_back

#define Range 100

vector <int> x, L, I, listSequence, v;
int pos;

void _reset() {
    listSequence.clear();
    L.clear();
    x.clear();
    v.clear();
    I.clear();
}


int LisNlogk() {
    int i;
    I.pb(-INF);
    for(int i = 0; i <= x.size(); i++) I.pb(INF);
    int trackPosition = 0;
    int max = -INF;
    for(i = 0; i < x.size(); i++ ) {
        int begin, end, mid;
        begin = 0;
        end = trackPosition;
        while( begin <= end ) {
            mid = ( begin + end ) / 2;
            if( I[mid] < x[i] )
                begin = mid + 1;
            else
                end = mid - 1;
        }

        I[begin] = x[i];
        L.pb(begin); // storing the LIS of every position
        if(L[i] > max) { // track the last index for later reconstruct the sequence
            max = L[i];
            pos = i;
        }
        if( trackPosition < begin )
            trackPosition = begin;
    }
    return trackPosition;
}

void sequence() {
    listSequence.pb(x[pos]);
    for(int i = pos-1; i >= 0; i--) {
        if( x[i] < x[pos] &&  L[i] == L[pos] -1) {
            pos = i;
            listSequence.pb(x[i]);
        }
    }
    for(int i = listSequence.size() -1; i >= 0; i--) cout << listSequence[i] << "\n";
}

int main() {
    int tcase, input;
    string s;
    cin >> tcase;
    cin.ignore();
    cin.ignore();
    while (tcase--) {
        _reset();
        while(getline(cin, s, '\n')) {
            if(s.length() == 0) break;
            istringstream ss(s);
            ss >> input;
            x.pb(input);
        }
        cout << "Max hits: " << LisNlogk() << "\n";
        sequence();
        if(tcase) cout << "\n";
    }

    return EXIT_SUCCESS;
}
