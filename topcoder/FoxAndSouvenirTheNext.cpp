#include <bits/stdc++.h>

using namespace std;

struct FoxAndSouvenirTheNext {
    int ableToSplitUtils(int indx, int taken, int N, int curr, int sum, vector<int> &value, vector<vector<vector<int> > > &dp) {
        if(indx >= value.size()) {
            return (int)(curr == sum and taken == N);
        }
        if(curr == sum and taken == N) {
            return 1;
        }
        if(dp[taken][curr][indx] != -1) return dp[taken][curr][indx];
        int found = 0;
        for(int i = indx; i < value.size() and !found; ++i) {
            if(taken < N and curr + value[i] <= sum) {
                found |= ableToSplitUtils(i + 1, taken + 1, N, curr + value[i], sum, value, dp);
            }
        }
        return dp[taken][curr][indx] = found;
    }

    string ableToSplit(vector <int> value)  {
        int n = value.size();
        string result[] = {"Impossible", "Possible"};
        if(n & 1) return result[0];
        int sum = 0;
        for(int i = 0; i < n; ++i) sum += value[i];
        if(sum & 1) return result[0];
        vector<vector<vector<int> > > dp(n / 2 + 1, vector<vector<int> >(sum / 2 + 1, vector<int>(n + 1, -1) ) );
        return result[ ableToSplitUtils(0, 0, n / 2, 0, sum / 2, value, dp) ];
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
        cout << "Testing FoxAndSouvenirTheNext (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1425142808;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        FoxAndSouvenirTheNext _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int value[] = {1,2,3,4};
            _expected = "Possible";
            _received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int)));
            break;
        }
        case 1: {
            int value[] = {1,1,1,3};
            _expected = "Impossible";
            _received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int)));
            break;
        }
        case 2: {
            int value[] = {1,1,2,3,5,8};
            _expected = "Possible";
            _received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int)));
            break;
        }
        case 3: {
            int value[] = {2,3,5,7,11,13};
            _expected = "Impossible";
            _received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int)));
            break;
        }
        case 4: {
            int value[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
            _expected = "Possible";
            _received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int)));
            break;
        }
        case 5: {
            int value[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
            _expected = "Impossible";
            _received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int)));
            break;
        }
        /*case 6:
        {
        	int value[] = ;
        	_expected = ;
        	_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
        }*/
        /*case 7:
        {
        	int value[] = ;
        	_expected = ;
        	_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
        }*/
        /*case 8:
        {
        	int value[] = ;
        	_expected = ;
        	_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
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
            cout << "           Expected: " << "\"" << _expected << "\"" << endl;
            cout << "           Received: " << "\"" << _received << "\"" << endl;
        }
    }
}

// END CUT HERE
