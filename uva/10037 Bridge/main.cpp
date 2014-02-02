/*#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

// WA code
priority_queue < int, vector <int>, greater<int> > q, q2, return_q;
queue <string> result;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int tcase, n, person;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &person);
            q.push(person);
        }
        int person, person2, min_time = 0;
        char buf[25];
        while(!q.empty() || !return_q.empty()) {
            bool flag = false;
            if(!q.empty()) {
                person = q.top();
                q.pop();
                q2.push(person);
                flag = true;
            }
            if(!q.empty()) {
                person2 = q.top();
                q.pop();
                q2.push(person2);
                sprintf(buf, "%d %d", person, person2);
                result.push(string(buf));
                min_time += person2;
            } else {
                if(!return_q.empty()) {
                    int pop = return_q.top(), pop2;
                    q2.push(pop);
                    return_q.pop();
                    if(!flag) {
                        if(!return_q.empty()) {
                            pop2 = return_q.top();
                            sprintf(buf, "%d %d", pop, pop2);
                            result.push(string(buf));
                            min_time += pop2;
                            q2.push(pop2);
                            return_q.pop();
                        } else {
                            sprintf(buf, "%d", pop);
                            result.push(string(buf));
                            min_time += pop;
                        }
                    } else {
                        sprintf(buf, "%d %d", pop, person);
                        result.push(string(buf));
                        min_time += person;
                    }
                } else {
                    sprintf(buf, "%d", person);
                    result.push(string(buf));
                    min_time += person;
                }
            }
            if(!q.empty() || !return_q.empty()) {
                int pop = q2.top();
                q2.pop();
                return_q.push(pop);
                sprintf(buf, "%d", pop);
                result.push(string(buf));
                min_time += pop;
            }
        }
        q2 = priority_queue <int, vector <int>, greater<int> > ();
        printf("%d\n", min_time);
        while(!result.empty()) {
            printf("%s\n", result.front().c_str());
            result.pop();
        }
        if(tcase) putchar('\n');
    }
    return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

/**
Few observations are important here:
1. Getting 1,2 or 3 people to the other side has only one optimal strategy.
2. If we have 4 or more people, we can break the problem down into the problems of getting each 2 people to the other side.
3. Getting 2 people from four or more to the other side can have one of two optimal strategies.
Let our people be A and B be our fastest 2, with A being the fastest, and let C and D be our two slowest, with D being the slowest.
Strategy 1:
A & C go: Takes C time
A returns: Takes A time
A & D go: Takes D time
A returns: Takes A time
Total time = 2A + D + C

Strategy 2:
A & B go: Takes B time
A returns: Takes A time
C & D go: Takes D time
B returns: Takes B time
Total time = A + 2B + D

Hence, if Strategy 1 time < Strategy 2 time then
2A + D + C < A + 2B + D.
Therefore, A + C < 2B
And if this doesn’t hold, then Strategy 2 time <= Strategy 1 time

We sort our entries and then move from the back, taking the slowest two every time, until we’re left with 1,2 or 3 people.

**/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N,n;

    cin >> N;

    for (int i = 0; i < N; i++) {
        deque<int> LeftSide, RightSide;

        cin >> n;
        int T;
        for (int i = 0; i < n; i++) {
            cin >> T;
            LeftSide.push_back(T);
        }

        sort(LeftSide.begin(), LeftSide.end());
        int TotalTime = 0;
        stringstream fout;
        while(1) {
            int A = LeftSide[0];

            if (LeftSide.size() == 1) {
                fout << A;
                TotalTime += A;
                break;
            }

            int B = LeftSide[1];

            if (LeftSide.size() == 2) {
                fout << A << " " << B;
                TotalTime += B;
                break;
            }

            if (LeftSide.size() == 3) {
                // here fout << A << " " << B << endl << A << endl << A << " " <<  LeftSide[2]; yields the same result, but this ordering isn't working to be AC :p
                fout << A << " " << LeftSide[2] << endl << A << endl << A << " " <<  B ;
                TotalTime += B + A +  LeftSide[2];
                break;
            }
            int Y, Z;

            Z = LeftSide.back();
            LeftSide.pop_back();
            Y = LeftSide.back();
            LeftSide.pop_back();
            if (A + Y < 2 * B) {
                fout << A << " " << Z << endl << A << endl << A << " " << Y << endl << A << endl;
                TotalTime += Z + 2 * A + Y;
            } else {
                fout << A << " " << B << endl << A << endl << Y << " " << Z << endl << B << endl;
                TotalTime += 2 * B + A + Z;
            }
        }

        cout<< TotalTime << endl << fout.str() << endl;

        if (i != N - 1) cout << endl;
    }
    return 0;
}
