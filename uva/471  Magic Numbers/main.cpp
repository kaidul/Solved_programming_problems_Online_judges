#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>

#define int64 long long
using namespace std;

bool isValid(int64 value) {
    map <int, bool> isRepeated;
    while (value > 0) {
        int mod = value % 10;
        if(isRepeated[mod])
            return false;
        isRepeated[mod] = true;
        value /= 10;
    }
    return true;
}

bool compare( pair<int64, int64> a, pair<int64, int64> b) {
    return a.first < b.first;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int64 tcase;
    int64 n;
    bool first = true;
    vector < pair<int64, int64> > result;
    scanf("%lld", &tcase);
    while(tcase--) {
        scanf("%lld", &n);
        if(n == 0) continue;
        result.clear();
        bool flag = false;
        for (int64 s2 = 1; (n * s2) >= 0; s2++) {
            int64 s1 = n * s2;

            for (int64 j = 0, numerator = s1; numerator ; j++, numerator /= 10)
                if (j > 10) {
                    flag = true;
                    break;
                }
            if (flag) break;

            if ( isValid(s1) and isValid(s2) )
                result.push_back( make_pair(s1, s2) );
        }
        sort(result.begin(), result.end(), compare);

        if (!first)
            putchar('\n');
        first = false;
        for (int i = 0; i < result.size(); i++)
            printf("%lld / %lld = %lld\n", result[i].first, result[i].second, n);
    }
    return 0;
}
/* Antu's code
#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

int digits[10];

int evaluate(long long int s1,long long int s2) {
    memset(digits,-1,sizeof(digits));
    int i,j,i_count;
    while(s1!=0) {
        j=s1%10;
        if(digits[j]==1) return 0;
        else digits[j]=1;
        s1=s1/10;
    }

    memset(digits,-1,sizeof(digits));
    while(s2!=0) {
        j=s2%10;
        if(digits[j]==1) return 0;
        else digits[j]=1;
        s2=s2/10;
    }


    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    long long int n,N,m,s1,s2,spacing=0,count;
    bool flag;
    bool first = true;
    cin>>n;
    while(n--) {
        cin>>N;
        flag=0;
        count=0;
        if(!first)
            putchar('\n');
        first = false;
        for(m=1; m<=9876543210; m++) {
            s1=N*m;
            if(s1>9876543210) break;
            flag=evaluate(s1,m);
            if(flag) {

                cout<<s1<<" / "<<m<<" = "<<N<<"\n";
            }
        }
    }
    return 0;

}
*/
