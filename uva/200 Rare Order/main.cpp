#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

#define Max 27

vector<int> adj[Max];
stack<int> Stack;
bool visited[Max];

void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if(!visited[v])
            dfs(v);
    }
    Stack.push(u);
}

void topsort() {
    for(int i = 0; i < Max; ++i) {
        if(!visited[i])
            dfs(i);
    }
    while(!Stack.empty()) {
        int elem = Stack.top();
        printf("%c", elem + 'A');
        Stack.pop();
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    /*
    char prev[Max], curr[Max];
    gets(prev);
    memset(visited, true, sizeof visited);
    while(strcmp(gets(curr), "#")) {
        for(int i = 0; prev[i] and curr[i]; ++i) {
            if(prev[i] != curr[i]) {
                int u = prev[i] - 'A';
                int v = curr[i] - 'A';
                adj[u].push_back(v);
                visited[u] = visited[v] = false;
                break;
            }
        }
        strcpy(prev, curr);
    }
    topsort();
    */
    char A[2001][21] = {'a'}, tmp[21];
    int i = 0;
    int taken[26] = {0};

    while (scanf("%s", tmp) and tmp[0] != '#') {
        strcpy(A[i], tmp);
        i++;
    }

    for (int j = 0; j <= 20; j++) {
        for (int k = 0; k < i; k++) {
            if (A[k][j] >= 'A' and A[k][j] <= 'Z')
                taken[A[k][j] - 'A']++;

            if (taken[A[k][j] - 'A'] == 1)
                printf("%c", A[k][j]);
        }
    }
    printf("\n");
    return 0;
}
