#include <bits/stdc++.h>

using namespace std;

struct ArmyTeleportation {
	string ifPossible(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> xt, vector <int> yt)  {
		
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
		cout << "Testing ArmyTeleportation (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423401632;
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
		ArmyTeleportation _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1[] = {0, 1};
				int y1[] = {0, 1};
				int x2[] = {2, 1};
				int y2[] = {4, 3};
				int xt[] = {2, 3, 2};
				int yt[] = {0, 1, 3};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 1:
			{
				int x1[] = {0, 1, 2};
				int y1[] = {2, 4, 6};
				int x2[] = {3, 5, 6};
				int y2[] = {1, 1, 0};
				int xt[] = {3, 1, -2};
				int yt[] = {4, 2, 10};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 2:
			{
				int x1[] = {0, 1};
				int y1[] = {1, 2};
				int x2[] = {1, 2};
				int y2[] = {2, 3};
				int xt[] = {0, 0, 0};
				int yt[] = {5, 3, 8};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 3:
			{
				int x1[] = {6, -5, 1};
				int y1[] = {3, -10, -7};
				int x2[] = {0, 11, 5};
				int y2[] = {-5, 8, 5};
				int xt[] = {0, -5, 4};
				int yt[] = {-8, -9, -4};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 4:
			{
				int x1[] = {3, 2, 1};
				int y1[] = {1, 2, 3};
				int x2[] = {4, 5, 6};
				int y2[] = {6, 5, 4};
				int xt[] = {-2, 5, 6};
				int yt[] = {1, -3, 2};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 5:
			{
				int x1[] = {903, -970, 404, 563};
				int y1[] = {-348, -452, 37, 692};
				int x2[] = {3359, 1486, 2860, 3019};
				int y2[] = {-416, -520, -31, 624};
				int xt[] = {346, -838, 916};
				int yt[] = {-541, -717, -348};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 6:
			{
				int x1[] = {4600, 8914, 9330, -193, 5422};
				int y1[] = {25, 7650, -7366, -8494, -6574};
				int x2[] = {-117326, -121640, -122056, -112533, -118148};
				int y2[] = {322619, 314994, 330010, 331138, 329218};
				int xt[] = {9523, -7546, -9858};
				int yt[] = {-3750, -5347, -3828};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 7:
			{
				int x1[] = {4514, -67225, -78413, -96468, -58938};
				int y1[] = {-22815, -86062, -54529, -87391, 42044};
				int x2[] = {259998, 331737, 342925, 360980, 323450};
				int y2[] = {912263, 975510, 943977, 976839, 847404};
				int xt[] = {23726, -98808, -26788};
				int yt[] = {80876, -68160, -13684};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			/*case 8:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int xt[] = ;
				int yt[] = ;
				_expected = ;
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int xt[] = ;
				int yt[] = ;
				_expected = ;
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int xt[] = ;
				int yt[] = ;
				_expected = ;
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
