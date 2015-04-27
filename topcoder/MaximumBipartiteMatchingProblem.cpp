#include <bits/stdc++.h>

using namespace std;

struct MaximumBipartiteMatchingProblem {
	long long solve(int n1, int n2, int ans, int d)  {
		
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
		cout << "Testing MaximumBipartiteMatchingProblem (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1424368168;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MaximumBipartiteMatchingProblem _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n1 = 3;
				int n2 = 3;
				int ans = 2;
				int d = 1;
				_expected = 5LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}
			case 1:
			{
				int n1 = 3;
				int n2 = 3;
				int ans = 1;
				int d = 1;
				_expected = -1LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}
			case 2:
			{
				int n1 = 5;
				int n2 = 10;
				int ans = 5;
				int d = 2;
				_expected = 50LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}
			case 3:
			{
				int n1 = 100000000;
				int n2 = 87654321;
				int ans = 12345678;
				int d = 54321;
				_expected = 1233229491567444LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}
			case 4:
			{
				int n1 = 1000000000;
				int n2 = 1000000000;
				int ans = 1000000000;
				int d = 1000000000;
				_expected = 1000000000000000000LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}
			/*case 5:
			{
				int n1 = ;
				int n2 = ;
				int ans = ;
				int d = ;
				_expected = LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}*/
			/*case 6:
			{
				int n1 = ;
				int n2 = ;
				int ans = ;
				int d = ;
				_expected = LL;
				_received = _obj.solve(n1, n2, ans, d); break;
			}*/
			/*case 7:
			{
				int n1 = ;
				int n2 = ;
				int ans = ;
				int d = ;
				_expected = LL;
				_received = _obj.solve(n1, n2, ans, d); break;
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
