#include <bits/stdc++.h>

using namespace std;

struct Fragile2 {
    void modifyGraph(int first, int second, vector<string> &graph) {
        for(int i = 0, n = graph[first].length(); i < n; ++i) {
            graph[first][i] = 'N';
        }
        for(int i = 0, n = graph[second].length(); i < n; ++i) {
            graph[second][i] = 'N';
        }
        for(int i = 0, n = graph[0].length(); i < n; ++i) {
            graph[i][first] = 'N';
            graph[i][second] = 'N';
        }
    }

    void dfs(int u, vector<string> &graph, vector<bool> &visited) {
        visited[u] = true;
        for(int i = 0, n = graph[0].length(); i < n; ++i) {
            if(graph[u][i] == 'Y' and !visited[i]) {
                dfs(i, graph, visited);
            }
        }
    }

    int numberOfConnectedComp(vector<string> &graph, pair<int, int> &vertices, bool flag) {
        int n = graph[0].length();
        vector<bool> visited(n, false);
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            if(flag) {
                if(i == vertices.first or i == vertices.second)
                    continue;
            }
            if(!visited[i]) {
                dfs(i, graph, visited);
                ret++;
            }
        }
        return ret;
    }

	int countPairs(vector <string> graph)  {
		int n = graph[0].length();
		int cnt = 0;
		for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                pair<int, int> articulate_pair = make_pair(i, j);
                int before = numberOfConnectedComp(graph, articulate_pair, false);
                vector <string> tmp(graph);
                modifyGraph(i, j, tmp);
                int after = numberOfConnectedComp(tmp, articulate_pair, true);
                if(after > before) {
                    ++cnt;
                }
            }
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
		cout << "Testing Fragile2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423414658;
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
		Fragile2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string graph[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
				_expected = 3;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				string graph[] = {"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"};
				_expected = 5;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				string graph[] = {"NNN", "NNN", "NNN"};
				_expected = 0;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				string graph[] = {"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
				                  "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"};
				_expected = 9;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 4:
			{
				string graph[] = {"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN",
				                  "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN",
				                  "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN",
				                  "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"};
				_expected = 42;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			/*case 5:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.countPairs(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
