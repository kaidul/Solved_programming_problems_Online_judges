#include <bits/stdc++.h>

using namespace std;

struct TypoCoderDiv2 {
public:
    int count(vector <int> rating) {
        int ret = 0;
        bool ciet = true;
        for(int i = 0, n = rating.size(); i < n; ++i) {
            if(rating[i] >= 1200) {
                if(ciet) {
                    ++ret;
                    ciet = false;
                }
            } else {
                if(!ciet) {
                    ++ret;
                    ciet = true;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing TypoCoderDiv2 (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1396046707;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        TypoCoderDiv2 _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int rating[] = {1000,1200,1199};
            _expected = 2;
            _received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int)));
            break;
        }
        case 1: {
            int rating[] = {1500,2200,900,3000};
            _expected = 3;
            _received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int)));
            break;
        }
        case 2: {
            int rating[] = {600,700,800,900,1000,1100,1199};
            _expected = 0;
            _received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int)));
            break;
        }
        case 3: {
            int rating[] = {0,4000,0,4000,4000,0,0};
            _expected = 4;
            _received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int)));
            break;
        }
        case 4: {
            int rating[] = {575,1090,3271,2496,859,2708,3774,2796,1616,2552,3783,2435,1111,526,562};
            _expected = 4;
            _received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int)));
            break;
        }
        /*case 5:
        {
        	int rating[] = ;
        	_expected = ;
        	_received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int rating[] = ;
        	_expected = ;
        	_received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
        }*/
        /*case 7:
        {
        	int rating[] = ;
        	_expected = ;
        	_received = _obj.count(vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
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
