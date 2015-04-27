#include <bits/stdc++.h>

using namespace std;

#define MAXN 55

int sum[MAXN][MAXN];

class ChocolateDividingEasy {
public:
	int findBest(vector <string> chocolate)  {
		int n = chocolate.size();
		int m = chocolate[0].length();
		int ret = INT_MIN, ans = INT_MAX;
		sum[0][0] = (int) (chocolate[0][0] - '0');
		for(int i = 1; i < n; ++i) sum[i][0] = (int) (chocolate[i][0] - '0') + sum[i - 1][0];
		for(int j = 1; j < m; ++j) sum[0][j] = (int) (chocolate[0][j] - '0') + sum[0][j - 1];
		for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                sum[i][j] = (int) (chocolate[i][j] - '0') + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
		}
#if 0
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%d ", sum[i][j]);
            }
            printf("\n");
		}
#endif
		int fraction[10] = {0};

		for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1; j < n - 1; ++j) {
                for(int k = 0; k < m - 2; ++k) {
                    fraction[0] = sum[i][k];
                    fraction[1] = sum[j][k] - sum[i][k];
                    fraction[2] = sum[n - 1][k] - sum[j][k];

                    for(int l = k + 1; l < m - 1; ++l) {
                        ans = INT_MAX;

                        fraction[3] = sum[i][l] - sum[i][k];
                        fraction[4] = sum[j][l] - sum[j][k] - sum[i][l] + sum[i][k];
                        fraction[5] = sum[n - 1][l] - sum[j][l] - sum[n - 1][k] + sum[j][k];

                        fraction[6] = sum[i][m - 1] - sum[i][l];
                        fraction[7] = sum[j][m - 1] - sum[i][m - 1] - sum[j][l] + sum[i][l];
                        fraction[8] = sum[n - 1][m - 1] - sum[j][m - 1] - sum[n - 1][l] + sum[j][l];
                        ans = min(ans, *min_element(fraction, fraction + 9));
                        ret = max(ret, ans);
                    }
                }

            }
		}
		return ret;
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
		cout << "Testing ChocolateDividingEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1426002998;
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
//        int _tc = 0;
		ChocolateDividingEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chocolate[] = {
				                     "9768",
				                     "6767",
				                     "5313"
				                     };
				_expected = 3;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			case 1:
			{
				string chocolate[] = {
				                     "36753562",
				                     "91270936",
				                     "06261879",
				                     "20237592",
				                     "28973612",
				                     "93194784"
				                     };
				_expected = 15;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			case 2:
			{
				string chocolate[] = {
				                     "012",
				                     "345",
				                     "678"
				                     };
				_expected = 0;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			/*case 3:
			{
				string chocolate[] = ;
				_expected = ;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string chocolate[] = ;
				_expected = ;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string chocolate[] = ;
				_expected = ;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
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
