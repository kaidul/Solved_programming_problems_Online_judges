#include <bits/stdc++.h>

using namespace std;

string dictionary[200 + 5];
int dictionary_length;
int visited[200 + 5];

struct node {
    string str;
    int cost;
    node (string a, int c): str(a), cost(c) {}
    node (): str(), cost() {}
};

queue <node> q;

bool isOneCharDiff(string a, string b) {
    if ( a.length() != b.length() ) return false;
    int cnt = 0;
    for ( int i = 0, n = a.length(); i < n; i++ ) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt == 1;
}

int bfs (string a, string b) {
    q = queue <node> ();
    memset(visited, false, sizeof visited);
    q.push(node (a, 0));
    for (int i = 0; i < dictionary_length; i++) if(dictionary[i] == a) {visited[i] = true; break;}
    node u;
    while (!q.empty()) {
        u = q.front(), q.pop();
        if (u.str == b)
            return u.cost;
        for ( int i = 0; i < dictionary_length; i++ ) {
            if ( !visited[i] ) {
                if ( isOneCharDiff(u.str, dictionary[i]) ) {
                    q.push(node(dictionary[i], u.cost + 1));
                    visited[i] = true;
                }
            }
        }
    }
    return 0;
}

int main(void) {
//    freopen("in.txt", "r", stdin);
    int testCase;
    bool blank = false;
    scanf ("%d\n\n", &testCase);
    while ( testCase-- ) {
        char input [100];
        dictionary_length = 0;
        while ( gets (input) and strcmp (input, "*") ) dictionary [dictionary_length++] = input;
        if (blank) printf("\n"); blank = true;
        while ( gets (input) && strlen (input) ) {
            char *pch;
            string a, b;
            pch = strtok(input, " ");
            a = pch;
            pch = strtok (NULL, " ");
            b = pch;
            cout << a << " " << b;
            printf (" %d\n", bfs (a, b));
        }
    }

    return 0;
}
