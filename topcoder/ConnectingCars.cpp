#include <bits/stdc++.h>

using namespace std;
struct Car {
    int pos;
    int length;
} cars[55];
bool compare(Car const& lhs, Car const& rhs) {
    return lhs.pos < rhs.pos;
}
struct ConnectingCars {
    long long minimizeCost(vector <int> positions, vector <int> lengths)  {
        long long ans = 0;
        long long n = positions.size();
        for(int i = 0; i < n; ++i) {
            cars[i].pos = positions[i], cars[i].length = lengths[i];
        }
        sort(cars, cars + n, &compare);
        for(long long i = 0; i < n - 1; ++i) {
            long long gap = cars[i + 1].pos - cars[i].pos - cars[i].length;
            if(gap > 0) ans += min(i + 1, n - i - 1) * gap;
        }
        return ans;
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
        cout << "Testing ConnectingCars (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1423243140;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        ConnectingCars _obj;
        long long _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int positions[] = {1, 3, 10, 20};
            int lengths[] = {2, 2, 5, 3};
            _expected = 15LL;
            _received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int)));
            break;
        }
        case 1: {
            int positions[] = {100, 50, 1};
            int lengths[] = {10, 2, 1};
            _expected = 96LL;
            _received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int)));
            break;
        }
        case 2: {
            int positions[] = {4, 10, 100, 13, 80};
            int lengths[] = {5, 3, 42, 40, 9};
            _expected = 66LL;
            _received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int)));
            break;
        }
        case 3: {
            int positions[] = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427};
            int lengths[] = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540};
            _expected = 1009957100LL;
            _received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int)));
            break;
        }
        /*case 4:
        {
        	int positions[] = ;
        	int lengths[] = ;
        	_expected = LL;
        	_received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
        }*/
        /*case 5:
        {
        	int positions[] = ;
        	int lengths[] = ;
        	_expected = LL;
        	_received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int positions[] = ;
        	int lengths[] = ;
        	_expected = LL;
        	_received = _obj.minimizeCost(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
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
