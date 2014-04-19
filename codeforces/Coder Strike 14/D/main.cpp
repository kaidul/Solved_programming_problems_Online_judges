#include<bits/stdc++.h>
using namespace std;
vector<int >d[30005];
bool v[30005];
void df(int x) {
    v[x] =1;
    for(int i=0; i<d[x].size(); ++i)
        if(!v[d[x][i]])
            df(d[x][i]);
    cout<<x<<" ";
}

int main() {
    int n,m,a,b,i;
    cin>>n>>m;
    for(i=0; i<m; ++i)
        cin>>a>>b,d[a].push_back(b);
    for(i=1; i<=n; ++i)if(!v[i])df(i);
}
