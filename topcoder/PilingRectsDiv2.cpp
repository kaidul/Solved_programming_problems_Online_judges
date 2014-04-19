#include <bits/stdc++.h>

using namespace std;

struct PilingRectsDiv2 {
	public:
	int getmax(vector <int> X, vector <int> Y, int limit) {
		
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
		cout << "Testing PilingRectsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396046795;
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
		PilingRectsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {1,2,3,1};
				int Y[] = {3,2,4,4};
				int limit = 3;
				_expected = 3;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}
			case 1:
			{
				int X[] = {4,7};
				int Y[] = {7,4};
				int limit = 25;
				_expected = 2;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}
			case 2:
			{
				int X[] = {10};
				int Y[] = {10};
				int limit = 9999;
				_expected = -1;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}
			case 3:
			{
				int X[] = {10};
				int Y[] = {3};
				int limit = 30;
				_expected = 1;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}
			case 4:
			{
				int X[] = {3,6,5,8,2,9,14};
				int Y[] = {14,6,13,8,15,6,3};
				int limit = 27;
				_expected = 4;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}
			case 5:
			{
				int X[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149};
				int Y[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146};
				int limit = 5345;
				_expected = 24;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}
			/*case 6:
			{
				int X[] = ;
				int Y[] = ;
				int limit = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}*/
			/*case 7:
			{
				int X[] = ;
				int Y[] = ;
				int limit = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
			}*/
			/*case 8:
			{
				int X[] = ;
				int Y[] = ;
				int limit = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), limit); break;
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

