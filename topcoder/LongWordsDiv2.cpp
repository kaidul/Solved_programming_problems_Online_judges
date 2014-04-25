#line 2 "LongWordsDiv2.cpp"
#include <bits/stdc++.h>
using namespace std;
struct LongWordsDiv2 {
    bool isUpperCase(char c) {
        return c >= 'A' and c <= 'Z';
    }
    string find(string word) {
        string result[] = {"Dislikes", "Likes"};
        int n = word.length();
        char prev = word[0], curr;
        if( !isUpperCase(prev) ) return result[0];
        for(int i = 1; i < n; ++i) {
            curr = word[i];
            if( !isUpperCase(curr) ) return result[0];
            if(prev == curr) return result[0];
            prev = curr;
        }
        char a, b, c, d;
        for(int i = 0; i < n; ++i) {
            a = word[i];
            for(int j = i + 1; j < n; ++j) {
                b = word[j];
                for(int k = j + 1; k < n; ++k) {
                    c = word[k];
                    for(int l = k + 1; l < n; ++l) {
                        d = word[l];
                        if(a == b and b == c and c == d) return result[0];
                        if(a == c and b == d) return result[0];
                    }
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

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing LongWordsDiv2 (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1398434266;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        LongWordsDiv2 _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string word = "AAA";
            _expected = "Dislikes";
            _received = _obj.find(word);
            break;
        }
        case 1: {
            string word = "ABCBA";
            _expected = "Likes";
            _received = _obj.find(word);
            break;
        }
        case 2: {
            string word = "ABCBAC";
            _expected = "Dislikes";
            _received = _obj.find(word);
            break;
        }
        case 3: {
            string word = "TOPCODER";
            _expected = "Likes";
            _received = _obj.find(word);
            break;
        }
        case 4: {
            string word = "VAMOSGIMNASIA";
            _expected = "Dislikes";
            _received = _obj.find(word);
            break;
        }
        case 5: {
            string word = "SINGLEROUNDMATCH";
            _expected = "Likes";
            _received = _obj.find(word);
            break;
        }
        case 6: {
            string word = "DALELOBO";
            _expected = "Likes";
            _received = _obj.find(word);
            break;
        }
        case 7:
        {
        	string word = "AAA";
        	_expected = "Dislikes";
        	_received = _obj.find(word); break;
        }
        case 8:
        {
        	string word = "ABA";
        	_expected = "Likes";
        	_received = _obj.find(word); break;
        }
        case 9:
        {
        	string word = "A";
        	_expected = "Likes";
        	_received = _obj.find(word); break;
        }
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
