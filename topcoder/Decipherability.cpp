#include <bits/stdc++.h>

using namespace std;

struct Decipherability {
	void solve(int indx, string str, string &s, int len, bool &flag, unordered_map <string, bool> &hashTable) {
	    if(!flag) return;
	    if(str.length() > len) return;
	    if(indx == s.length()) {
            if(str.length() == len) {
                if(hashTable[str]) {
                    flag = false;
                }
                hashTable[str] = true;
            }
            return;
	    }
	    solve(indx + 1, str + s[indx], s, len, flag, hashTable);
	    solve(indx + 1, str, s, len, flag, hashTable);
	}
	string check(string s, int K)  {
		string result[] = {"Uncertain", "Certain"};
		/*
		unordered_map <string, bool> hashTable;
		bool idx = 1;
		string curr = "";
		solve(0, curr, s, s.length() - K, idx, hashTable);
		return result[idx];
		*/
		int n = s.size();
		if(K == n) {
            return result[1];
		}
		for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n and j - i <= K; ++j) {
                if(s[i] == s[j]) {
                    return result[0];
                }
            }
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
		cout << "Testing Decipherability (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423584050;
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
		Decipherability _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "snuke";
				int K = 2;
				_expected = "Certain";
				_received = _obj.check(s, K); break;
			}
			case 1:
			{
				string s = "aba";
				int K = 1;
				_expected = "Certain";
				_received = _obj.check(s, K); break;
			}
			case 2:
			{
				string s = "aba";
				int K = 2;
				_expected = "Uncertain";
				_received = _obj.check(s, K); break;
			}
			case 3:
			{
				string s = "abcdabcd";
				int K = 3;
				_expected = "Certain";
				_received = _obj.check(s, K); break;
			}
			case 4:
			{
				string s = "koukyoukoukokukikou";
				int K = 2;
				_expected = "Uncertain";
				_received = _obj.check(s, K); break;
			}
			case 5:
			{
				string s = "wolfsothe";
				int K = 8;
				_expected = "Uncertain";
				_received = _obj.check(s, K); break;
			}
			case 6:
			{
				string s = "aa";
				int K = 2;
				_expected = "Certain";
				_received = _obj.check(s, K); break;
			}
			/*case 7:
			{
				string s = ;
				int K = ;
				_expected = ;
				_received = _obj.check(s, K); break;
			}*/
			/*case 8:
			{
				string s = ;
				int K = ;
				_expected = ;
				_received = _obj.check(s, K); break;
			}*/
			/*case 9:
			{
				string s = ;
				int K = ;
				_expected = ;
				_received = _obj.check(s, K); break;
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
