#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
#define MAX 1001
#define INF (1 << 30)
struct TheGridDivTwo {
    /*
    int dfs(int x, int y, int depth, int k, vector< vector<int> > &dis) {
        dis[x][y] = depth;
        if(depth == k) return x;
        int ret = x;
        for(int i = 0; i < 4; ++i) {
            int X = x + dx[i], Y = y + dy[i];
            if(dis[X][Y] == -1) {
                ret = max(ret, dfs(X, Y, depth + 1, k, dis));
                dis[X][Y] = -1;
            }
        }
        return ret;
    }
    */
	int find(vector <int> x, vector <int> y, int k)  {
	    /*
	    // dfs; TLE
        const int MIN = -1000, MAX = 1000;
        const int INF = (1 << 30);
        vector< vector<int> > dis(MAX - MIN + 1, vector<int> (MAX - MIN + 1, -1));
        for(int i = 0, n = x.size(); i < n; ++i) {
            dis[x[i] + MAX][y[i] + MAX] = INF;
        }
		return dfs(MAX, MAX, 0, k, dis) - MAX;
		*/
		vector< vector<int> > dis(MAX * 2, vector<int> (MAX * 2, -1));
		queue <pair<int, int> > Q;
		int offsetX = 1000, offsetY = 1000;
		for(int i = 0, n = x.size(); i < n; ++i) {
            dis[x[i] + offsetX][y[i] + offsetY] = INF;
		}
		Q.push(make_pair(offsetX, offsetY));
		dis[offsetX][offsetY] = 0;
		int ans = 0;
		while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            ans = max(ans, x);
            if(dis[x][y] == k) continue;
            for(int i = 0; i < 4; ++i) {
                int X = x + dx[i], Y = y + dy[i];
                if(dis[X][Y] == -1) {
                    dis[X][Y] = dis[x][y] + 1;
                    Q.push(make_pair(X, Y));
                }
            }
		}
		return ans - offsetX;
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
		cout << "Testing TheGridDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423304569;
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
		TheGridDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,1,1,1};
				int y[] = {-2,-1,0,1};
				int k = 4;
				_expected = 2;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			case 1:
			{
				int x[] = {-1, 0, 0, 1};
				int y[] = {0, -1, 1, 0};
				int k = 9;
				_expected = 0;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			case 2:
			{
				int x[] = {};
				int y[] = {};
				int k = 1000;
				_expected = 1000;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			case 3:
			{
				int x[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
				int y[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
				int k = 47;
				_expected = 31;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
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
