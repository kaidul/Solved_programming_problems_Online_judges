#line 2 "WakingUpEasy.cpp"
#include <bits/stdc++.h>
using namespace std;
struct WakingUpEasy {
	int countAlarms(vector <int> volume, int S) {
        int cnt = 0;
        for(int i = 0; S > 0; ++i) {
            S -= volume[i];
            ++cnt;
            volume.push_back(volume[i]);
        }
        return cnt;
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
		cout << "Testing WakingUpEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397142012;
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
		WakingUpEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int volume[] = {5, 2, 4};
				int S = 13;
				_expected = 4;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
			}
			case 1:
			{
				int volume[] = {5, 2, 4};
				int S = 3;
				_expected = 1;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
			}
			case 2:
			{
				int volume[] = {1};
				int S = 10000;
				_expected = 10000;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
			}
			case 3:
			{
				int volume[] = {42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
				                 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
				                 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69};
				int S = 9999;
				_expected = 203;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
			}
			case 4:
			{
				int volume[] = {1};
				int S = 7;
				_expected = 7;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
			}
			/*case 5:
			{
				int volume[] = ;
				int S = ;
				_expected = ;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
			}*/
			/*case 6:
			{
				int volume[] = ;
				int S = ;
				_expected = ;
				_received = _obj.countAlarms(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), S); break;
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
