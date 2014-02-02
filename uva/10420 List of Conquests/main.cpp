#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include <queue>
#include <vector>
#include<algorithm>
#define ll long long
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
using namespace std;
int main() {
    int n;
    vector<string>v;
    map<string,int>mp;
    string s,a;
    cin>>n;
    getchar();
    while(n--) {
        cin>>s;
        getchar();
        getline(cin,a);
        if(mp[s]) {
            mp[s]++;
        } else {
            mp[s]++;
            v.push_back(s);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++) {
        string c=v[i];
        cout<<""<<c<<" "<<mp[c]<<endl;
    }
    v.clear();

    return 0;
}
