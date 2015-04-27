#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1 << 30)
#define MAXN (1 << 20)

//char nodes[MAXN];
unordered_map <int, char> nodes;

class IncompleteBST {
public:
    bool isValid(int idx, char Min, char Max) {
        if(!nodes[idx]) return true;
        if(nodes[idx] < Min or nodes[idx] > Max) return false;
        int leftIdx = idx << 1, rightIdx = leftIdx | 1;
        return isValid(leftIdx, Min, nodes[idx]) && isValid(rightIdx, nodes[idx] + 1, Max);
    }

    string missingValues(vector <string> tree)  {
        int n = tree.size();
//        rep(i, MAXN) nodes[i] = '@';
        int idx, indx;
        char ch;
        rep(i, n) {
            stringstream ss(tree[i]);
            ss >> ch >> idx;
            if(ch == '?') {
                indx = idx;
                continue;
            }
            nodes[idx] = ch;
        }
        string result = "";
        rep(i, 26) {
            ch = i + 'A';
            nodes[indx] = ch;
            if(isValid(1, 'A', 'Z')) result += ch;
        }
        return result;
    }
};

/*
vector<char> seq;
unordered_map <int, char> nodes;

class IncompleteBST {
public:
    void inorder(int idx) {
        if(idx > MAXN or !nodes[idx]) return;
        int leftIdx = idx << 1, rightIdx = leftIdx | 1;
        inorder(leftIdx);
        seq.push_back(nodes[idx]);
        inorder(rightIdx);
    }

    string missingValues(vector <string> tree)  {
        int n = tree.size();
        int idx; char ch;
        rep(i, n) {
            stringstream ss(tree[i]);
            ss >> ch >> idx;
            nodes[idx] = ch;
        }
        string result = "";
        inorder(1);
        int k = seq.size();
        rep(i, k) {
            if(seq[i] == '?') {
                if(i == 0) {
                    for(char c = 'A'; c <= seq[i + 1]; c++) {
                        result += c;
                    }
                } else if(i == k - 1) {
                    for(char c = seq[i - 1]; c <= 'Z'; c++) {
                        result += c;
                    }
                } else {
                    for(char c = seq[i - 1]; c <= seq[i + 1]; c++) {
                        result += c;
                    }
                }
                break;
            }
        }
        return result;
    }
};
*/

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing IncompleteBST (1000.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1426598053;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        IncompleteBST _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string tree[] = {"A 1", "? 2"};
            _expected = "A";
            _received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string)));
            break;
        }
        case 1: {
            string tree[] = {"B 1", "? 2"};
            _expected = "AB";
            _received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string)));
            break;
        }
        case 2: {
            string tree[] = {"V 1", "? 3"};
            _expected = "WXYZ";
            _received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string)));
            break;
        }
        case 3: {
            string tree[] = {"K 1", "K 2", "A 6", "? 12", "Y 3"};
            _expected = "";
            _received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string)));
            break;
        }
        case 4: {
            string tree[] = {"Z 1", "Y 2", "X 4", "W 8", "V 16", "U 32", "T 64", "S 128", "R 256", "Q 512",
                             "P 1024", "O 2048", "N 4096", "M 8192", "L 16384", "K 32768", "J 65536", "? 131072"
                            };
            _expected = "ABCDEFGHIJ";
            _received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string)));
            break;
        }
        /*case 5:
        {
        	string tree[] = ;
        	_expected = ;
        	_received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
        }*/
        /*case 6:
        {
        	string tree[] = ;
        	_expected = ;
        	_received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
        }*/
        /*case 7:
        {
        	string tree[] = ;
        	_expected = ;
        	_received = _obj.missingValues(vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
        }*/
        default:
            return 0;
        }
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
        if (_received == _expected)
            cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
        else {
            cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
            cout << "           Expected: " << "\"" << _expected << "\"" << endl;
            cout << "           Received: " << "\"" << _received << "\"" << endl;
        }
    }
}

// END CUT HERE
