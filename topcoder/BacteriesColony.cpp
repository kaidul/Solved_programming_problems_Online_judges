#include <bits/stdc++.h>

using namespace std;

struct BacteriesColony {
    vector <int> performTheExperiment(vector <int> colonies)  {
        bool changed;
        int dx;
        do {
            changed = false; dx = 0;
            for(int i = 1, n = colonies.size(); i < n - 1; ++i) {
                if(colonies[i - 1] - dx > colonies[i] and colonies[i + 1] > colonies[i]) {
                    colonies[i]++;
                    dx = 1;
                    changed = true;
                } else if(colonies[i - 1] - dx < colonies[i] and colonies[i + 1] < colonies[i]) {
                    colonies[i]--;
                    dx = -1;
                    changed = true;
                } else {
                    dx = 0;
                }
            }
        } while(changed);
        return colonies;
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
        cout << "Testing BacteriesColony (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1423392791;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        BacteriesColony _obj;
        vector <int> _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int colonies[] = {5, 3, 4, 6, 1 };
            int __expected[] = {5, 4, 4, 4, 1 };
            _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
            _received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int)));
            break;
        }
        case 1: {
            int colonies[] = {1, 5, 4, 9 };
            int __expected[] = {1, 4, 5, 9 };
            _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
            _received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int)));
            break;
        }
        case 2: {
            int colonies[] = {78, 34, 3, 54, 44, 99 };
            int __expected[] = {78, 34, 34, 49, 49, 99 };
            _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
            _received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int)));
            break;
        }
        case 3: {
            int colonies[] = {32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 };
            int __expected[] = {32, 59, 59, 59, 47, 47, 47, 47, 47, 18, 18, 19, 53, 53, 91 };
            _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
            _received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int)));
            break;
        }
        /*case 4:
        {
        	int colonies[] = ;
        	int __expected[] = ;
        	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
        	_received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int))); break;
        }*/
        /*case 5:
        {
        	int colonies[] = ;
        	int __expected[] = ;
        	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
        	_received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int colonies[] = ;
        	int __expected[] = ;
        	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
        	_received = _obj.performTheExperiment(vector <int>(colonies, colonies+sizeof(colonies)/sizeof(int))); break;
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
            cout << "           Expected: {";
            for (unsigned i = 0; i < _expected.size(); i++) {
                if (i) cout << ",";
                cout << " " << _expected[i];
            }
            cout << " }" << endl;
            cout << "           Received: {";
            for (unsigned i = 0; i < _received.size(); i++) {
                if (i) cout << ",";
                cout << " " << _received[i];
            }
            cout << " }" << endl;
        }
    }
}

// END CUT HERE
