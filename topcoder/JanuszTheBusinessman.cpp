#include <bits/stdc++.h>

using namespace std;
const int MAXN = 50;
#define DEBUG 1

struct JanuszTheBusinessman {
	int makeGuestsReturn(vector <int> arrivals, vector <int> departures)  {
		int n = arrivals.size();
        pair<int, int> arrivalOrder[MAXN], departureOrder[MAXN];
        priority_queue <pair<int, int> > inHotel;

		for(int i = 0; i < n; ++i) {
            arrivalOrder[i] = make_pair(arrivals[i], i);
            departureOrder[i] = make_pair(departures[i], i);
		}
		sort(arrivalOrder, arrivalOrder + n);
		sort(departureOrder, departureOrder + n);
#ifdef DEBUG
        for(int i = 0; i < n; ++i) {
            cout << arrivalOrder[i].first << " " << departureOrder[i].first << endl;
        }
#endif
		int ans = 0;
		int last = -1;
		for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n && arrivalOrder[j].first <= departureOrder[i].first; ++j) {
                int idx = arrivalOrder[j].second;
                inHotel.push( make_pair(departures[idx], idx) );
            }
            if(arrivals[departureOrder[i].second] <= last)
                continue;
            ans++;
            last = inHotel.top().first;
            inHotel.pop();
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

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing JanuszTheBusinessman (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423396007;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		JanuszTheBusinessman _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		    /*
			case 0:
			{
				int arrivals[] = {2, 10, 6}	;
				int departures[] = {6, 11, 9};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 1:
			{
				int arrivals[] = {2, 10, 23, 34, 45, 123, 1};
				int departures[] = {25, 12, 40, 50, 48, 187, 365};
				_expected = 1;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			*/
			case 2:
			{
				int arrivals[] = {8, 12, 20, 30, 54, 54, 68, 75};
				int departures[] = {13, 31, 30, 53, 55, 70, 80, 76};
				_expected = 3;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			/*
			case 3:
			{
				int arrivals[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
				int departures[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 4:
			{
				int arrivals[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
				int departures[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
				_expected = 14;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			*/
			/*case 5:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
