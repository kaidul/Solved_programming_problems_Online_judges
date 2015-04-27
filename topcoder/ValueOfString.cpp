#include <bits/stdc++.h>

using namespace std;

struct ValueOfString {
	int findValue(string s)  {
		int n = s.length();
		int result = 0;
		int val[30] = {0};
		for(int i = 0; i < n; ++i) {
            val[ s[i] - 'a' + 1 ]++;
		}
		for(int i = 1; i <= 26; i++) {
            val[i] += val[i - 1];
		}
		for(int i = 0; i < n; ++i) {
            result += val[ s[i] - 'a' + 1 ] * ((int)(s[i] - 'a' + 1));
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
		cout << "Testing ValueOfString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425913233;
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
		ValueOfString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "babca";
				_expected = 35;
				_received = _obj.findValue(s); break;
			}
			case 1:
			{
				string s = "zz";
				_expected = 104;
				_received = _obj.findValue(s); break;
			}
			case 2:
			{
				string s = "y";
				_expected = 25;
				_received = _obj.findValue(s); break;
			}
			case 3:
			{
				string s = "aaabbc";
				_expected = 47;
				_received = _obj.findValue(s); break;
			}
			case 4:
			{
				string s = "topcoder";
				_expected = 558;
				_received = _obj.findValue(s); break;
			}
			case 5:
			{
				string s = "thequickbrownfoxjumpsoverthelazydog";
				_expected = 11187;
				_received = _obj.findValue(s); break;
			}
			case 6:
			{
				string s = "zyxwvutsrqponmlkjihgfedcba";
				_expected = 6201;
				_received = _obj.findValue(s); break;
			}
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.findValue(s); break;
			}*/
			/*case 8:
			{
				string s = ;
				_expected = ;
				_received = _obj.findValue(s); break;
			}*/
			/*case 9:
			{
				string s = ;
				_expected = ;
				_received = _obj.findValue(s); break;
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
