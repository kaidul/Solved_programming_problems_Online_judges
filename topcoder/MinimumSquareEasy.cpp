#line 2 "MinimumSquareEasy.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
class MinimumSquareEasy {
public:
    long long minArea(vector <int> x, vector <int> y) {
        i64 x1,x2,y1,y2,area,lenx,leny,side;
        int sz=x.size();
        vector< int > a,b;
        i64 mn=LONG_LONG_MAX;
        for(int i=0; i<sz; i++) {
            for(int j=i+1; j<sz; j++) {
                for(int k=0; k<sz; k++) {
                    if(i==k or j==k) continue;
                    else {
                        a.push_back(x[k]);
                        b.push_back(y[k]);
                    }
                }
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                x1 = a[0]-1,x2 = a[sz-3]+1;
                y1 = b[0]-1,y2 = b[sz-3]+1;
                lenx = x2-x1;
                leny = y2-y1;
                side = max(lenx,leny);
                area = side*side;
                mn = min(mn,area);
                a.clear();
                b.clear();
            }
        }
        return mn;
    }
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing MinimumSquareEasy (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1396287190;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        MinimumSquareEasy _obj;
        long long _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int x[] = {0, 1, 2};
            int y[] = {0, 1, 5};
            _expected = 4LL;
            _received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)));
            break;
        }
        case 1: {
            int x[] = {-1, -1, 0, 2, 0};
            int y[] = {-2, -1, 0, -1, -2};
            _expected = 9LL;
            _received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)));
            break;
        }
        case 2: {
            int x[] = {1000000000, -1000000000, 1000000000, -1000000000};
            int y[] = {1000000000, 1000000000, -1000000000, -1000000000};
            _expected = 4000000008000000004LL;
            _received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)));
            break;
        }
        case 3: {
            int x[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
            int y[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
            _expected = 22801LL;
            _received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)));
            break;
        }
        /*case 4:
        {
        	int x[] = ;
        	int y[] = ;
        	_expected = LL;
        	_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
        }*/
        /*case 5:
        {
        	int x[] = ;
        	int y[] = ;
        	_expected = LL;
        	_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int x[] = ;
        	int y[] = ;
        	_expected = LL;
        	_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
        }*/
        default:
            return 0;
        }
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
        if (_received == _expected)
            cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
        else {
            cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
            cout << "           Expected: " << _expected << endl;
            cout << "           Received: " << _received << endl;
        }
    }
}

// END CUT HERE
