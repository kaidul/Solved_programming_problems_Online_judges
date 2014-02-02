/**
  Type: Greedy - INTERVAL COVERING
  Algorithm:
  Abridge statement for INTERVAL COVERING problem:
	Giving an interval [0..n] for example and a set of segments. Find the minimum number of segments whose intervals can cover the whole given interval.
	Solution: Sort the set of segment in increasing order of their left and decreasing order of their right if they have the same left end. Traverse the set once, pick up the segment with the furthest right end.
Why is this correct? Let's take a look to this simple
    proof:
        - Let A be the set of segments results by doing the algorithm above (A has n elements).
        - Suppose there exists a set B which can cover the whole interval and has fewer elements than A (B has m < n elements).
        - For any element i, the current interval covered by A[1..i] must be larger than B[1..i] because we always pick the furthest right end for A. Therefore, the interval covered by A[i+1..n] must be smaller than B[i+1..m].
        - But since B has fewer elements, this mean there MUST exist at least 1 segment k (i <= k <= n) in B that B[k] has farther right end than A[k]. This is conflict with the statement that A always pick the farthest right end segment. Hence, there is no B at all.
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Segment {
public:
    int l, r;

    Segment();
    Segment(int _l, int _r): l(_l), r(_r) {}

    bool operator < (const Segment &segment) const {
        if (this -> l < segment.l) return true;
        if (this->l == segment.l && this->r > segment.r) return true;
        return false;
    }

    bool operator > (const Segment &segment) const {
        if (this -> l > segment.l) return true;
        if (this->l == segment.l && this->r < segment.r) return true;
        return false;
    }

    bool operator == (const Segment &segment) const {
        return (this -> l == segment.l && this -> r == segment.r);
    }
};

int m;

void readFile(vector <Segment> &result);
bool isNotCut(Segment &segment);
int B_SearchAtX(int x, vector<Segment> &segments);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int nTest;
    cin >> nTest;
    while (nTest--) {
        vector<Segment> input;
        vector<Segment> output;
        readFile(input);
        bool failed = false;

        // LeftEnd save the current left end and
        // rightEnd save the current right end
        int leftEnd = 0, rightEnd;

        // The next index to put in the result
        int index = 0;

        // First condition, input size > 0 and the
        // left end of the left most one must be in range
        if (input.size() > 0 && input[0].l <= 0) {
            rightEnd = input[index].r;

            for (int i = 1; i < (int)input.size(); i++)
                // If input[i].l covered the current leftEnd
                // |-----------| (current left end here)
                //          |-------------| (input[i])
                if (input[i].l <= leftEnd) {
                    if (input[i].r > rightEnd) {
                        // New right end is input[i].r
                        rightEnd = input[i].r;
                        index = i;
                    }
                    // Visualization for this case:
                    // |-----------| (current left end here)
                    //                |------| (input[i])
                } else if (input[i].l > leftEnd && input[i].r > rightEnd) {
                    // If input[i] is not cut with the current
                    // covered interval.
                    if (input[i].l > rightEnd) {
                        failed = true;
                        break;
                    }

                    // If it is finished (fully covered)
                    if (input[index].r >= m) break;

                    // Else update the result
                    output.push_back(input[index]);
                    // New leftEnd is current rightEnd
                    leftEnd = rightEnd;

                    // New rightEnd is input[i].r
                    rightEnd = input[i].r;
                    index = i;
                }
            // Put the final one in
            output.push_back(input[index]);
        } else failed = true;

        if (!failed && rightEnd >= m) {
            cout << output.size() << endl;
            for (int i = 0; i < (int)output.size(); i++)
                cout << output[i].l << " " << output[i].r << endl;
        } else cout << 0 << endl;
        if (nTest > 0) cout << endl;
    }
    return 0;
}

void readFile(vector<Segment> &result) {
    cin >> m;
    result.clear();
    while (true) {
        int l, r;
        cin >> l >> r;
        if (l == 0 && r == 0) break;
        Segment s(l, r);
        // Not of not cut is cut! Put it in, for get others
        // out - range segments
        if (!isNotCut(s)) result.push_back(s);
    }

    // Algorithm sort, your class must have compare operator
    // otherwise you has to write your own compare function
    sort(result.begin(), result.end());
}

bool isNotCut(Segment &segment) {
    return (segment.r < 0 || segment.l > m);
}
