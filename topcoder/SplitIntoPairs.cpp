#include <bits/stdc++.h>

using namespace std;

struct SplitIntoPairs {
	public:
	int makepairs(vector <int> A, int X) {
		
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
		cout << "Testing SplitIntoPairs (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389502418;
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
		SplitIntoPairs _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {2,-1};
				int X = -1;
				_expected = 0;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}
			case 1:
			{
				int A[] = {1,-1};
				int X = -1;
				_expected = 1;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}
			case 2:
			{
				int A[] = {-5,-4,2,3};
				int X = -1;
				_expected = 2;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}
			case 3:
			{
				int A[] = {5,-7,8,-2,-5,3};
				int X = -7;
				_expected = 3;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}
			case 4:
			{
				int A[] = {3,4,5,6,6,-6,-4,-10,-1,-9};
				int X = -2;
				_expected = 4;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}
			case 5:
			{
				int A[] = {1000000,1000000};
				int X = -5;
				_expected = 1;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}
			/*case 6:
			{
				int A[] = ;
				int X = ;
				_expected = ;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int X = ;
				_expected = ;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int X = ;
				_expected = ;
				_received = _obj.makepairs(vector <int>(A, A+sizeof(A)/sizeof(int)), X); break;
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

