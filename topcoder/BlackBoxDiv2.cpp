#include <bits/stdc++.h>

using namespace std;

struct BlackBoxDiv2 {
	public:
	int count(string front, string side) {
		
	}
};
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
		cout << "Testing BlackBoxDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396046927;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BlackBoxDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string front = "BB";
				string side = "BB";
				_expected = 7;
				_received = _obj.count(front, side); break;
			}
			case 1:
			{
				string front = "...";
				string side = ".....";
				_expected = 1;
				_received = _obj.count(front, side); break;
			}
			case 2:
			{
				string front = "...";
				string side = "BBB";
				_expected = 0;
				_received = _obj.count(front, side); break;
			}
			case 3:
			{
				string front = "...BB.B....";
				string side = "B.B.B.B.B";
				_expected = 16081;
				_received = _obj.count(front, side); break;
			}
			case 4:
			{
				string front = "BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB";
				string side = ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB";
				_expected = 771030153;
				_received = _obj.count(front, side); break;
			}
			/*case 5:
			{
				string front = ;
				string side = ;
				_expected = ;
				_received = _obj.count(front, side); break;
			}*/
			/*case 6:
			{
				string front = ;
				string side = ;
				_expected = ;
				_received = _obj.count(front, side); break;
			}*/
			/*case 7:
			{
				string front = ;
				string side = ;
				_expected = ;
				_received = _obj.count(front, side); break;
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

