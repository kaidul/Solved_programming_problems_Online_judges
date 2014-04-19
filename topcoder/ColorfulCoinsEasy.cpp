#line 2 "ColorfulCoinsEasy.cpp"
#include <bits/stdc++.h>
using namespace std;
struct ColorfulCoinsEasy {
	string isPossible(vector <int> values) {
        string result[] = {"Impossible", "Possible"};
        int val = values[values.size() - 1] - 1;
        map <int, bool> flag;
        int tmp;
        for(int i = values.size() - 2; i >= 0; --i) {
            tmp = val / values[i];
            if(flag[tmp]) return result[0];
            flag[tmp] = true;
            val %= values[i];
        }
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
		cout << "Testing ColorfulCoinsEasy (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397142594;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColorfulCoinsEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int values[] = {1};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int values[] = {1, 3};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int values[] = {1, 2, 4};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int values[] = {1, 5, 15, 90};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 4:
			{
				int values[] = {1, 4, 20, 60, 180, 1440, 5760};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 5:
			{
				int values[] = {1, 7, 21, 105, 630, 3150, 18900};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 6:
			{
				int values[] = {1, 10, 30, 300, 900, 9000, 18000};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 7:
			{
				int values[] = {1, 2, 10, 40, 200, 1000, 4000, 20000};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 8:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
