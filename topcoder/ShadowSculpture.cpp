#include <bits/stdc++.h>

using namespace std;

struct ShadowSculpture {
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)  {
		string result[] = {"Impossible", "Possible"};
		// other stuffs
		return result[1];
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
		cout << "Testing ShadowSculpture (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421170246;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ShadowSculpture _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string XY[] = {"YN","NN"};
				string YZ[] = {"YN","NN"};
				string ZX[] = {"YN","NN"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 1:
			{
				string XY[] = {"YN","NY"};
				string YZ[] = {"YN","NY"};
				string ZX[] = {"YN","NY"};
				_expected = "Impossible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 2:
			{
				string XY[] = {"YYY","YNY","YYY"};
				string YZ[] = {"YYY","YNY","YYY"};
				string ZX[] = {"YYY","YNY","YYY"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 3:
			{
				string XY[] = {"YYY","YNY","YYY"};
				string YZ[] = {"NYY","YNY","YYY"};
				string ZX[] = {"YYY","YNY","YYN"};
				_expected = "Impossible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 4:
			{
				string XY[] = {"N"};
				string YZ[] = {"N"};
				string ZX[] = {"N"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			/*case 5:
			{
				string XY[] = ;
				string YZ[] = ;
				string ZX[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string XY[] = ;
				string YZ[] = ;
				string ZX[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string XY[] = ;
				string YZ[] = ;
				string ZX[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
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
