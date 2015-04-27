#include <bits/stdc++.h>

using namespace std;

struct RobotOnMoonEasy {
    string isSafeCommand(vector <string> board, string S)  {
        int n = board.size();
        int m = board[0].size();
        int currX = 0, currY = 0;
        bool found = false;
        for(int i = 0; i < n and !found; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'S') {
                    currX = i, currY = j;
                    found = true;
                    break;
                }
            }
        }
        string result[] = {"Dead", "Alive"};
        int len = S.length();
        int prevX, prevY;
        for(int i = 0; i < len; ++i) {
            prevX = currX, prevY = currY;
            switch(S[i]) {
            case 'U':
                currX--;
                break;
            case 'D':
                currX++;
                break;
            case 'L':
                currY--;
                break;
            case 'R':
                currY++;
                break;
            }
            if(currX >= n or currX < 0 or currY >= m or currY < 0) {
                return result[0];
            } else if(board[currX][currY] == '#') {
                currX = prevX, currY = prevY;
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

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing RobotOnMoonEasy (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1425999942;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        RobotOnMoonEasy _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string board[] = {".....",
                              ".###.",
                              "..S#.",
                              "...#."
                             };
            string S = "URURURURUR";
            _expected = "Alive";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        case 1: {
            string board[] = {".....",
                              ".###.",
                              "..S..",
                              "...#."
                             };
            string S = "URURURURUR";
            _expected = "Dead";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        case 2: {
            string board[] = {".....",
                              ".###.",
                              "..S..",
                              "...#."
                             };
            string S = "URURU";
            _expected = "Alive";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        case 3: {
            string board[] = {"#####",
                              "#...#",
                              "#.S.#",
                              "#...#",
                              "#####"
                             };
            string S = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
            _expected = "Alive";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        case 4: {
            string board[] = {"#####",
                              "#...#",
                              "#.S.#",
                              "#...#",
                              "#.###"
                             };
            string S = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
            _expected = "Dead";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        case 5: {
            string board[] = {"S"};
            string S = "R";
            _expected = "Dead";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        case 6: {
            string board[] = {".S"};
            string S = "LRLRLRLRL";
            _expected = "Alive";
            _received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S);
            break;
        }
        /*case 7:
        {
        	string board[] = ;
        	string S = ;
        	_expected = ;
        	_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
        }*/
        /*case 8:
        {
        	string board[] = ;
        	string S = ;
        	_expected = ;
        	_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
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
