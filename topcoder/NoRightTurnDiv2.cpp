#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;

int n;
vector<int> result, solution;
vector<int> adj[MAXN];
bool visited[MAXN] = {false};
bool found = false;
struct NoRightTurnDiv2 {

//	bool isValid(int i, int j) {
//
//        return false;
//	}

    void dfs(int u) {
        if(found) return;
        if(result.size() == n) {
            solution = result;
            found = true;
            return;
        }
        for(int i = 0; i < (int)adj[u].size(); ++i) {
            if(!visited[adj[u][i]]) {
                visited[adj[u][i]] = true;
                result.push_back(adj[u][i]);
                dfs(adj[u][i]);
                if(found) return;
                result.pop_back();
                visited[adj[u][i]] = false;
            }
        }
    }

    void init() {
        memset(visited, false, sizeof visited);
        for(int i = 0; i < MAXN; ++i) adj[i].clear();
    }

	vector <int> findPath(vector <int> x, vector <int> y)  {
        ::n = x.size();
        init();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++i) {
                if(i == j) continue;
                if(isValid(i, j)) {
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            visited[i] = true;
            result.push_back(i);
            dfs(i);
            if(solution.size() == n) return solution;
            result.clear();
            memset(visited, false, sizeof visited);
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
		cout << "Testing NoRightTurnDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425914182;
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
		NoRightTurnDiv2 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {-10, 0, 10};
				int y[] = {10, -10, 10};
				int __expected[] = {0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*
			case 1:
			{
				int x[] = {0,0,-3,-3,3,3};
				int y[] = {-1,1,-3,3,-3,3};
				int __expected[] = {0, 4, 5, 3, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {10,9,8,7,6,5,4,3,2,1};
				int y[] = {1,4,9,16,25,36,49,64,81,100};
				int __expected[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 2,-2, 4,-4, 2,-2, 0};
				int y[] = {1, 2, 2, 4, 4, 6, 6, 5};
				int __expected[] = {4, 2, 0, 1, 3, 5, 6, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-76,98,83,58,-15,94,21,55,80,84,-39,-90,-46,100,-80,-49,-2,-70,36,48,88,10,
				          55,-56,22,67,31,81,100,-39,64,-62,-7,45,-82,-24,51,-33,53,11,20,-74,-83,47,
				          9,39,42,63,-97,94};
				int y[] = {-90,68,91,-92,-6,88,99,10,39,-69,-61,-4,71,-5,90,-51,21,-53,-21,-86,41,-9,
				          42,-23,-4,12,94,-59,55,18,70,-88,-86,-17,-97,-33,87,80,91,-80,-79,-79,-78,
				          -99,57,67,-52,-46,61,-10};
				int __expected[] = {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPath(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
