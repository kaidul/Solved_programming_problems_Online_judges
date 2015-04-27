#include <bits/stdc++.h>

using namespace std;

struct XorSequence {
	long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R)  {
		
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
		cout << "Testing XorSequence (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423586030;
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
		XorSequence _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int sz = 6;
				int A0 = 3;
				int A1 = 2;
				int P = 0;
				int Q = 1;
				int R = 3;
				_expected = 8LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}
			case 1:
			{
				int N = 8;
				int sz = 8;
				int A0 = 2;
				int A1 = 5;
				int P = 3;
				int Q = 1;
				int R = 4;
				_expected = 13LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}
			case 2:
			{
				int N = 8;
				int sz = 7;
				int A0 = 3;
				int A1 = 0;
				int P = 1;
				int Q = 2;
				int R = 4;
				_expected = 12LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}
			case 3:
			{
				int N = 32;
				int sz = 15;
				int A0 = 7;
				int A1 = 9;
				int P = 11;
				int Q = 2;
				int R = 1;
				_expected = 60LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}
			case 4:
			{
				int N = 131072;
				int sz = 131072;
				int A0 = 7;
				int A1 = 7;
				int P = 1;
				int Q = 0;
				int R = 0;
				_expected = 0LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}
			case 5:
			{
				int N = 131072;
				int sz = 131070;
				int A0 = 411;
				int A1 = 415;
				int P = 398;
				int Q = 463;
				int R = 9191;
				_expected = 4302679760LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}
			/*case 6:
			{
				int N = ;
				int sz = ;
				int A0 = ;
				int A1 = ;
				int P = ;
				int Q = ;
				int R = ;
				_expected = LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}*/
			/*case 7:
			{
				int N = ;
				int sz = ;
				int A0 = ;
				int A1 = ;
				int P = ;
				int Q = ;
				int R = ;
				_expected = LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
			}*/
			/*case 8:
			{
				int N = ;
				int sz = ;
				int A0 = ;
				int A1 = ;
				int P = ;
				int Q = ;
				int R = ;
				_expected = LL;
				_received = _obj.getmax(N, sz, A0, A1, P, Q, R); break;
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
