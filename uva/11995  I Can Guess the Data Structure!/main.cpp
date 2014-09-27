#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
#define Max 1010

class action {
public:
    int opcode;
    int value;
};
stack<int> st;
queue<int> q;
priority_queue<int, vector<int>, less<int> > pq;
int n;
action list[Max];

bool isStack();
bool isQueue();
bool isPriorityQueue();

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (!cin.eof()) {
        cin >> n;
        if (cin.eof()) break;

        q = queue <int> ();
        st = stack <int> ();
        pq = priority_queue <int> ();

        for (int i = 1; i <= n; i++)
            cin >> list[i].opcode >> list[i].value;

        bool isSt = isStack();
        bool isQ = isQueue();
        bool isPq = isPriorityQueue();

        if (isSt + isQ + isPq > 1) cout << "not sure" << endl;
        else if (isSt + isQ + isPq == 0) cout << "impossible" << endl;
        else {
            if (isSt) cout << "stack" << endl;
            else if (isQ) cout << "queue" << endl;
            else if (isPq) cout << "priority queue" << endl;
        }
    }
    return 0;
}

bool isStack() {
    for (int i = 1; i <= n; i++) {
        if (list[i].opcode == 1) st.push(list[i].value);
        else if (list[i].opcode == 2) {
            int pop;
            if (!st.empty()) {
                pop = st.top();
                st.pop();
            } else return(false);
            if (pop != list[i].value) return(false);
        }
    }
    return(true);
}

bool isQueue() {
    for (int i = 1; i <= n; i++) {
        if (list[i].opcode == 1) q.push(list[i].value);
        else if (list[i].opcode == 2) {
            int pop;
            if (!q.empty()) {
                pop = q.front();
                q.pop();
            } else return(false);
            if (pop != list[i].value) return(false);
        }
    }
    return(true);
}

bool isPriorityQueue() {
    for (int i = 1; i <= n; i++) {
        if (list[i].opcode == 1) pq.push(list[i].value);
        else if (list[i].opcode == 2) {
            int pop;
            if (!pq.empty()) {
                pop = pq.top();
                pq.pop();
            } else return(false);
            if (pop != list[i].value) return(false);
        }
    }
    return(true);
}
