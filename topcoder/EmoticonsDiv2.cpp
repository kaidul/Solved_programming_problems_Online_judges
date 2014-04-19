#include <bits/stdc++.h>

using namespace std;

struct EmoticonsDiv2 {
public:
    int printSmiles(int smiles) {
        int res = smiles; //if x = 1, then f(1) + s/1, f(1) = 0
        for (int x = 1; x < smiles; x++) {
            if (smiles % x == 0) { // x is a divisor of s
                res = min(res, printSmiles(x) + smiles / x);
            }
        }
        return res;
    }
};
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
        cout << "Testing EmoticonsDiv2 (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1396226749;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        EmoticonsDiv2 _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int smiles = 2;
            _expected = 2;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 1: {
            int smiles = 6;
            _expected = 5;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 2: {
            int smiles = 11;
            _expected = 11;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 3: {
            int smiles = 16;
            _expected = 8;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 4: {
            int smiles = 1000;
            _expected = 21;
            _received = _obj.printSmiles(smiles);
            break;
        }
        /*case 5:
        {
        	int smiles = ;
        	_expected = ;
        	_received = _obj.printSmiles(smiles); break;
        }*/
        /*case 6:
        {
        	int smiles = ;
        	_expected = ;
        	_received = _obj.printSmiles(smiles); break;
        }*/
        /*case 7:
        {
        	int smiles = ;
        	_expected = ;
        	_received = _obj.printSmiles(smiles); break;
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

