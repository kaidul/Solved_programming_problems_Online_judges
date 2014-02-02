#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>
#include <iterator>
using namespace std;


bool doAssign(int Index, vector<int> Data, vector<bool> Taken, vector<int> &Results) {
    if (Index == Data.size()) return true;
    int pivotLoc = ((Results.size() - 1) * Results.size()) / 2;
    for (int i = 2; i < Data.size(); i++) {
        if (Index == 2) {
            double Avd = (Data[0] + Data[1] - Data[i]) / 2.0;
            if (Avd - (int)Avd > 0.00000001) continue;
            Results.push_back(Avd);
            Results.push_back(Data[0] - (int)Avd);
            Results.push_back(Data[1] - (int)Avd);
            Taken[i] = true;
        } else if (Index == pivotLoc) {
            if (Taken[i] == true) continue;
            Results.push_back(Data[i] - Results[0]);
            Taken[i] = true;
        } else {
            pivotLoc = ((Results.size() - 2) * (Results.size()-1)) / 2;
            if (Taken[i] == true) continue;
            if (Data[i] - Results.back() != Results[Index % pivotLoc]) continue;
            Taken[i] = true;
        }

        if (doAssign(Index + 1, Data, Taken, Results)) return true;

        Taken[i] = false;
        if (Index == 2) Results.clear();
        if (Index == pivotLoc) Results.pop_back();
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) == 1) {

        int limit = (n * (n - 1) ) / 2;

        vector<int> Data;
        Data.resize( limit);

        for (int i = 0; i < limit; i++)
            scanf("%d", &Data[i]);
        sort(Data.begin(), Data.end());

        vector <int> Results;
        vector <bool> taken;
        for(int i = 0; i < limit; i++)
            taken.push_back(false);

        doAssign(2, Data, taken, Results);

        sort(Results.begin(), Results.end());

        if (Results.size() == 0)
            cout << "Impossible\n";
        else
            for (int i = 0; i < Results.size(); i++)
                cout << Results[i] << ((i == Results.size() - 1) ? ('\n') : (' '));
    }
    return 0;
}
