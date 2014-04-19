#line 2 "MergeStrings.cpp"
#include <bits/stdc++.h>
using namespace std;
class MergeStrings {
public:
	string getmin(string S, string A, string B) {
        S = A + B;
//        random_shuffle(S.begin(), S.end());
        return S;
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
		cout << "Testing MergeStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396657585;
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
		MergeStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "??CC??";
				string A = "ABC";
				string B = "BCC";
				_expected = "ABCCBC";
				_received = _obj.getmin(S, A, B); break;
			}
			case 1:
			{
				string S = "WHAT?";
				string A = "THE";
				string B = "WA";
				_expected = "";
				_received = _obj.getmin(S, A, B); break;
			}
			case 2:
			{
				string S = "PARROT";
				string A = "PARROT";
				string B = "";
				_expected = "PARROT";
				_received = _obj.getmin(S, A, B); break;
			}
			case 3:
			{
				string S = "???????????";
				string A = "AZZAA";
				string B = "AZAZZA";
				_expected = "AAZAZZAAZZA";
				_received = _obj.getmin(S, A, B); break;
			}
			case 4:
			{
				string S = "????K??????????????D???K???K????????K?????K???????";
				string A = "KKKKKDKKKDKKDDKDDDKDKK";
				string B = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD";
				_expected = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK";
				_received = _obj.getmin(S, A, B); break;
			}
			/*case 5:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
			}*/
			/*case 6:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
			}*/
			/*case 7:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
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
