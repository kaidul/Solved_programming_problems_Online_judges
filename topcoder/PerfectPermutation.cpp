#include <bits/stdc++.h>

using namespace std;

struct PerfectPermutation {
	int reorder(vector <int> P)  {
		
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
		cout << "Testing PerfectPermutation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423583122;
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
		PerfectPermutation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P[] = {2, 0, 1};
				_expected = 0;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 1:
			{
				int P[] = {2, 0, 1, 4, 3};
				_expected = 2;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 2:
			{
				int P[] = {2, 3, 0, 1};
				_expected = 2;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 3:
			{
				int P[] = {0, 5, 3, 2, 1, 4};
				_expected = 3;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 4:
			{
				int P[] = {4, 2, 6, 0, 3, 5, 9, 7, 8, 1};
				_expected = 5;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			/*case 5:
			{
				int P[] = ;
				_expected = ;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int P[] = ;
				_expected = ;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int P[] = ;
				_expected = ;
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
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
