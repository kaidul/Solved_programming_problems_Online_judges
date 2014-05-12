using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 5005

int lcp[mx][mx];
void computeLcp(st &s1, st &s2) {
    for(int i=sz(s1)-1; i>=0; i--) {
        for(int j=sz(s2)-1; j>=0; j--) {
            lcp[i][j] = s1[i] == s2[j] ? 1 + lcp[i + 1][j + 1] : 0;
        }
    }
}
int mUA[mx];
int mUB[mx];

int main() {
#ifndef ONLINE_JUDGE
    read("in.txt");
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    st A, B;
    cin >> A >> B ;

    mem(lcp, 0);
    computeLcp(A, A);
    for(int i=0; i<sz(A); i++) {
        int minUniqueLength=0;
        for(int j=0; j<sz(A); j++) {
            if(i==j) continue;
            minUniqueLength=max(minUniqueLength,lcp[i][j]);
        }
        minUniqueLength++;
        mUA[i]=minUniqueLength;
    }

    mem(lcp,0);
    computeLcp(B, B);
    for(int i=0; i<sz(B); i++) {
        int minUniqueLength=0;
        for(int j=0; j<sz(B); j++) {
            if(i==j) continue;
            minUniqueLength=max(minUniqueLength,lcp[i][j]);
        }
        minUniqueLength++;
        mUB[i]=minUniqueLength;
    }

    mem(lcp,0);
    computeLcp(A, B);
    int ans=inf;
    for(int i=0; i<sz(A); i++) {
        for(int j=0; j<sz(B); j++) {
            if(lcp[i][j]>=max( mUA[i] , mUB[j] )) {
                ans=min( ans, max( mUA[i] , mUB[j] ) );
            }
        }
    }
    if( ans>=inf ) ans=-1;
    cout<<ans<<endl;
    return 0;
}
