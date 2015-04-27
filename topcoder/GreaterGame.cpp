#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1 << 30)
#define MAXN 100000

set<int> handSet, sotheSet;
int n;

double calcRest() {
    if(handSet.empty()) return 0;
    int res = 0;
    forstl(it, handSet) {
        forstl(jt, sotheSet) {
            res += *jt < *it;
        }
    }
    return res / (double) handSet.size();
}

class GreaterGame {
public:
	double calc(vector <int> hand, vector <int> sothe)  {
		n = hand.size();
		sotheSet.clear();
		FOR(i, 1, n * 2) sotheSet.insert(i);
		handSet.clear();
		rep(i, n) {
            handSet.insert(hand[i]);
            sotheSet.erase(hand[i]);
            if(sothe[i] != -1) {
                sotheSet.erase(sothe[i]);
            }
		}
		int res = 0;
		rep(i, n) {
            if(sothe[i] != -1) {
                auto it = handSet.lower_bound(sothe[i]);
                if(it == handSet.end()) {
                    handSet.erase(handSet.begin());
                } else {
                    handSet.erase(it);
                    res++;
                }
            }
		}
		return res + calcRest();
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
		cout << "Testing GreaterGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1426086229;
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
		GreaterGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int hand[] = {4,2};
				int sothe[] = {-1,-1};
				_expected = 1.5;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 1:
			{
				int hand[] = {4,2};
				int sothe[] = {1,3};
				_expected = 2.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 2:
			{
				int hand[] = {2};
				int sothe[] = {-1};
				_expected = 1.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 3:
			{
				int hand[] = {1,3,5,7};
				int sothe[] = {8,-1,4,-1};
				_expected = 2.5;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 4:
			{
				int hand[] = {6,12,17,14,20,8,16,7,2,15};
				int sothe[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
				_expected = 8.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			/*case 5:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
