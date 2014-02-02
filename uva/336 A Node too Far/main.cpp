#include <bits/stdc++.h>

#define Max 100000
#define pb push_back
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;

vector <int> adj[Max];
int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    queue <int> q;
    set <int> s;
    int caseNo = 0, e, x, y, src, ttl;
    int dis[Max + 1];
    bool visited[Max];
    memset(visited, false, sizeof visited);

    while(scanf("%d", &e) and e) {

        for(int i = 0; i < Max; ++i)
            adj[i].clear();
        q = queue <int> ();
        s.clear();

        for(int i = 0; i < e; i++) {
            scanf("%d %d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
            s.insert(x);
            s.insert(y);
        }

        while(scanf("%d %d", &src, &ttl)) {
            if(!src and !ttl) break;
            int count = 1;
            q.push(src);
            dis[src] = 0;
            visited[src] = true;
            while( !q.empty() ) {
                int u = q.front();
                for(int i = 0; i < (int)adj[u].size(); ++i) {
                    int v = adj[u][i];
                    if(!visited[v]) {
                        dis[v] = dis[u] + 1;
                        if(dis[v] > ttl)
                            break;
                        q.push(v);
                        visited[v] = true;
                        ++count;
                    }
                }
                q.pop();
            }
            int z = s.size() - count;
            if( z < 0 ) z = 0;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caseNo, z, src, ttl);
            memset(visited, false, sizeof visited);
        }

    }
    return 0;
}
