#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector <int> a;


pair <int, int> maxSubArraySum() {
    int max_so_far = 0, max_ending_here = 0;
    int size = a.size(), pos = 1, start = 1, finish = 1;
    for(int i = 0; i < size; i++) {
        max_ending_here += a[i];
        if(max_ending_here < 0) max_ending_here = 0, pos = i + 2, start = max_so_far <= 0 ? pos : start;
        if(max_so_far < max_ending_here || (max_so_far == max_ending_here && (i + 2 - pos > finish - start))) max_so_far = max_ending_here, start = pos, finish = i + 2;
    }
    if(max_so_far <= 0) return make_pair(0, 0);
    else return make_pair(start, finish);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, item, routes, max_sum, caseNo = 1;
    scanf("%d", &routes);
    while(routes--) {
        a.clear();
        scanf("%d", &n);
        while(--n && cin >> item) a.push_back(item);
        pair <int, int> nicest_part = maxSubArraySum();
        if(!nicest_part.first && !nicest_part.second) printf("Route %d has no nice parts\n", caseNo);
        else printf("The nicest part of route %d is between stops %d and %d\n", caseNo, nicest_part.first, nicest_part.second);
        caseNo++;
    }
    return 0;
}
