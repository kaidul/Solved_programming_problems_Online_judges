#line 2 "MovingRooksDiv1.cpp"
#include <bits/stdc++.h>
using namespace std;
struct MovingRooksDiv1 {
	vector <int> move(vector <int> Y1, vector <int> Y2) {

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
		cout << "Testing MovingRooksDiv1 (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398469654;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MovingRooksDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Y1[] = {0};
				int Y2[] = {0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 1:
			{
				int Y1[] = {1,0};
				int Y2[] = {0,1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 2:
			{
				int Y1[] = {1,2,0};
				int Y2[] = {2,0,1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 3:
			{
				int Y1[] = {2,1,0,3,5,4};
				int Y2[] = {0,1,2,3,4,5};
				int __expected[] = {0, 1, 0, 2, 1, 2, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 4:
			{
				int Y1[] = {10,9,8,7,6,5,4,3,2,1,0};
				int Y2[] = {0,1,2,3,4,5,6,7,8,9,10};
				int __expected[] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 10, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 2, 8, 2, 9, 2, 10, 3, 4, 3, 5, 3, 6, 3, 7, 3, 8, 3, 9, 3, 10, 4, 5, 4, 6, 4, 7, 4, 8, 4, 9, 4, 10, 5, 6, 5, 7, 5, 8, 5, 9, 5, 10, 6, 7, 6, 8, 6, 9, 6, 10, 7, 8, 7, 9, 7, 10, 8, 9, 8, 10, 9, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int Y1[] = ;
				int Y2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int Y1[] = ;
				int Y2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int Y1[] = ;
				int Y2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
