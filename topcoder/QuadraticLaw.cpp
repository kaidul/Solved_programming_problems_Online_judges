#include <bits/stdc++.h>

using namespace std;

struct QuadraticLaw {
	long long getTime(long long d)  {
		long long result = 0LL;
		long long left = 1LL, right = sqrtl(d);
		while(left <= right) {
            long long mid = (left + right) >> 1;
            if(1LL + mid <= d / mid) {
                result = mid;
                left = mid  + 1;
            } else {
                right = mid - 1;
            }
		}
		return result;
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
		cout << "Testing QuadraticLaw (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425821832;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		QuadraticLaw _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long d = 1LL;
				_expected = 0LL;
				_received = _obj.getTime(d); break;
			}
			case 1:
			{
				long long d = 2LL;
				_expected = 1LL;
				_received = _obj.getTime(d); break;
			}
			case 2:
			{
				long long d = 5LL;
				_expected = 1LL;
				_received = _obj.getTime(d); break;
			}
			case 3:
			{
				long long d = 6LL;
				_expected = 2LL;
				_received = _obj.getTime(d); break;
			}
			case 4:
			{
				long long d = 7LL;
				_expected = 2LL;
				_received = _obj.getTime(d); break;
			}
			case 5:
			{
				long long d = 1482LL;
				_expected = 38LL;
				_received = _obj.getTime(d); break;
			}
			case 6:
			{
				long long d = 1000000000000000000LL;
				_expected = 999999999LL;
				_received = _obj.getTime(d); break;
			}
			case 7:
			{
				long long d = 31958809614643170LL;
				_expected = 178770270LL;
				_received = _obj.getTime(d); break;
			}
			/*case 8:
			{
				long long d = LL;
				_expected = LL;
				_received = _obj.getTime(d); break;
			}*/
			/*case 9:
			{
				long long d = LL;
				_expected = LL;
				_received = _obj.getTime(d); break;
			}*/
			/*case 10:
			{
				long long d = LL;
				_expected = LL;
				_received = _obj.getTime(d); break;
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
