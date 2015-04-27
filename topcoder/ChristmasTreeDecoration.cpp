#include <bits/stdc++.h>

using namespace std;

#define MAX 201

struct Kruskal {
    int u, v, cost;
    Kruskal(): u(), v(), cost() {}
    Kruskal(int a, int b, int c): u(a), v(b), cost(c) {}
    bool operator < (const Kruskal& a) const {
        return cost < a.cost;
    }
} g[MAX];

vector <int> parent;
void init(int size) {
    parent.resize(size);
    for(int i = 0; i < size; ++i) {
        parent[i] = i;
    }
}

int findSet(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int x, int y) {
    parent[findSet(x)] = findSet(y);
}

bool isSameSet(int x, int y) {
    return findSet(x) == findSet(y);
}

struct ChristmasTreeDecoration {
	int solve(vector <int> col, vector <int> x, vector <int> y)  {
        int n = x.size();
        for(int i = 0; i < n; ++i) {
            g[i] = Kruskal(x[i], y[i], col[x[i] - 1] == col[y[i] - 1] ? 1 : 0);
        }
        sort(g, g + n);
        int N = col.size();
        init(N + 5);
        int total = 0;
        for(int i = 0; i < n; ++i) {
            int u = g[i].u, v = g[i].v, cost = g[i].cost;
            if( !isSameSet(u, v) ) {
                unionSet(u, v);
                total += cost;
            }
        }
        return total;
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
		cout << "Testing ChristmasTreeDecoration (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1424364458;
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
		ChristmasTreeDecoration _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int col[] = {1,1,2,2};
				int x[] = {1,2,3,4};
				int y[] = {2,3,4,1};
				_expected = 1;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int col[] = {1,1,2,2};
				int x[] = {1,2,3,4,1,2};
				int y[] = {2,3,4,1,3,4};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int col[] = {50,50,50,50};
				int x[] = {1,2,3,1,1,2};
				int y[] = {2,3,4,4,3,4};
				_expected = 3;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int col[] = {1,4,2,3};
				int x[] = {1,2,3};
				int y[] = {2,3,4};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int col[] = {1,1,1,2,2,2,3,3,3,4,4,4};
				int x[] = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
				int y[] = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
				_expected = 5;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
