#include <bits/stdc++.h>

using namespace std;

struct KitayutaMart2 {
	int numBought(int K, int T)  {
		int i = 1;
		int cost = 0;
		while(true) {
            cost += K * (1 << (i - 1));
            if(cost == T) {
                return i;
            }
            ++i;
		}
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
		cout << "Testing KitayutaMart2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423414207;
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
		KitayutaMart2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 100;
				int T = 100;
				_expected = 1;
				_received = _obj.numBought(K, T); break;
			}
			case 1:
			{
				int K = 100;
				int T = 300;
				_expected = 2;
				_received = _obj.numBought(K, T); break;
			}
			case 2:
			{
				int K = 150;
				int T = 1050;
				_expected = 3;
				_received = _obj.numBought(K, T); break;
			}
			case 3:
			{
				int K = 160;
				int T = 163680;
				_expected = 10;
				_received = _obj.numBought(K, T); break;
			}
			/*case 4:
			{
				int K = ;
				int T = ;
				_expected = ;
				_received = _obj.numBought(K, T); break;
			}*/
			/*case 5:
			{
				int K = ;
				int T = ;
				_expected = ;
				_received = _obj.numBought(K, T); break;
			}*/
			/*case 6:
			{
				int K = ;
				int T = ;
				_expected = ;
				_received = _obj.numBought(K, T); break;
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
