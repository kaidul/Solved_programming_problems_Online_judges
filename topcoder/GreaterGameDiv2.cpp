#include <bits/stdc++.h>

using namespace std;

struct GreaterGameDiv2 {
	int calc(vector <int> snuke, vector <int> sothe)  {
		int result = 0;
		for(int i = 0; i < snuke.size(); ++i) {
            result += (snuke[i] > sothe[i]);
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
		cout << "Testing GreaterGameDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414476557;
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
		GreaterGameDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int snuke[] = {1,3};
				int sothe[] = {4,2};
				_expected = 1;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 1:
			{
				int snuke[] = {1,3,5,7,9};
				int sothe[] = {2,4,6,8,10};
				_expected = 0;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 2:
			{
				int snuke[] = {2};
				int sothe[] = {1};
				_expected = 1;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 3:
			{
				int snuke[] = {3,5,9,16,14,20,15,17,13,2};
				int sothe[] = {6,18,1,8,7,10,11,19,12,4};
				_expected = 6;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			/*case 4:
			{
				int snuke[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int snuke[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int snuke[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
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
