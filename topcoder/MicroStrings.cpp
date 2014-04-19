#line 2 "MicroStrings.cpp"
#include <bits/stdc++.h>
using namespace std;
class MicroStrings {
public:
    string makeMicroString(int A, int D) {
        string res = "";
        ostringstream convert;
        convert << A;
        res += convert.str();
        int sub;
        while(1) {
            sub = A - D;
            if(sub < 0) break;
            ostringstream convert;
            convert << sub;
            res += convert.str();
            A = sub;
        }
        return res;
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
        cout << "Testing MicroStrings (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1396279651;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        MicroStrings _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int A = 12;
            int D = 5;
            _expected = "1272";
            _received = _obj.makeMicroString(A, D);
            break;
        }
        case 1: {
            int A = 3;
            int D = 2;
            _expected = "31";
            _received = _obj.makeMicroString(A, D);
            break;
        }
        case 2: {
            int A = 31;
            int D = 40;
            _expected = "31";
            _received = _obj.makeMicroString(A, D);
            break;
        }
        case 3: {
            int A = 30;
            int D = 6;
            _expected = "3024181260";
            _received = _obj.makeMicroString(A, D);
            break;
        }
        /*case 4:
        {
        	int A = ;
        	int D = ;
        	_expected = ;
        	_received = _obj.makeMicroString(A, D); break;
        }*/
        /*case 5:
        {
        	int A = ;
        	int D = ;
        	_expected = ;
        	_received = _obj.makeMicroString(A, D); break;
        }*/
        /*case 6:
        {
        	int A = ;
        	int D = ;
        	_expected = ;
        	_received = _obj.makeMicroString(A, D); break;
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
