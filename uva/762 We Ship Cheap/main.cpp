#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Empty(queue) while(!queue.empty())
#define RESET(t,value) memset((t), value, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define i64 long long
#define pb push_back
#define ppb pop_back
#define pii pair<double,double>
#define G struct node

#define Max 700

vector <int> adj[Max];
int visited[Max], dis[Max+1];
int par[Max];
stack <int> st;
queue <int> q;
map <string, int> city;

void re_arrange(int src, int des) {
    if(par[des] == src) {
        st.push(src);
        //return;
    } else if(par[des] == des) {
        cout << "No route\n";
        st.empty();
    } else {
        st.push(par[des]);
        re_arrange(src, par[des]);
    }
}

void find_path(int src, int des) {
    re_arrange(src, des);
    string str[Max];
    Fore (it, city) str[(*it).second]=(*it).first;
    while(!st.empty()) {
        int u = st.top();
        cout << str[u] << " ";
        st.pop();
        if(!st.empty()) {
            int v = st.top();
            cout << str[v] << endl;
        } else cout << str[des] << "\n";
    }
}

void BFS(int src, int des) {
    q.push(src);
    visited[src] = 1;
    while(!q.empty()) {
        int pop = q.front(), temp;
        REP(i, adj[pop].size()) {
            temp = adj[pop][i];
            if(!visited[temp]) {
                visited[temp] = 1;
                q.push(temp);
                par[temp] = pop;
                if(temp == des) return;
            }
        }
        q.pop();
    }
}

void reset() {
    city.clear();
    q = queue <int> ();
    RESET(visited, 0);
    REP(i, Max) {
        adj[i].clear();
        par[i] = i;
    }
}
int main() {
    READ("input.txt");
    string first, second, src_city, des_city;
    int e, src, des, index;
    bool blank = false;
    while(cin >> e) {
        index = 1;
        if(blank) cout << "\n";
        blank = true;
        REP(i, e) {
            cin >> first >> second;
            if (!city[first]) city[first] = index++;
            if (!city[second]) city[second] = index++;
            adj[city[first]].pb(city[second]);
            adj[city[second]].pb(city[first]);
        }
        cin >> src_city >> des_city;
        BFS(city[src_city], city[des_city]);
        if ( !city [src_city] || !city [des_city] || !visited[city [des_city]] )
            printf ("No route\n");
        else find_path(city[src_city], city[des_city]);

        reset();
    }
    return 0;
}
