#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> v[501];
int n;
int vis[5001], righ[5001], lef[5001];
double val[5001], val2[5001];
bool solve(int pos) {
    vis[pos] = 1;

    for(int i = 0; i < v[pos].size(); i++) {
        if(lef[v[pos][i]] == -1 || solve(v[pos][i])) {
            lef[v[pos][i]] = pos;
            righ[pos] = v[pos][i];
            return true;
        }
    }
    return false;
}


int main() {
    int t;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> t;
    int cs = 0;
    while(t--) {
        cin >> n;
        cs++;
        for(int i = 0; i < n; i++) {
            cin >> val[i];
            v[i].clear();
        }
        for(int i = 0; i < n; i++) {
            cin >> val2[i];
        }
        cout << "Case #" << cs << ": ";
        sort(val2, val2+n);
        sort(val, val+n);
        memset(vis, 0, sizeof(vis));
        int ans = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[j]) {
                    if(val[j] > val2[i]) {
                        ans--;
                        vis[j] = 1;
                        break;
                    }
                }
            }
        }
        cout << n-ans << " ";
        memset(vis, 0, sizeof(vis));
        ans = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[j]) {
                    if(val2[j] > val[i]) {
                        ans--;
                        vis[j] = 1;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
