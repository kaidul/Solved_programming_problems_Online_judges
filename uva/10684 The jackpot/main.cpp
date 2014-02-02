#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector <int> a;


int maxSubArraySum() {
    int max_so_far = 0, max_ending_here = 0;
    int size = a.size();
    for(int i = 0; i < size; i++) {
        max_ending_here += a[i];
        if(max_ending_here < 0) max_ending_here = 0;
        if(max_so_far < max_ending_here) max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, item, max_sum;
    while(scanf("%d", &n) && n) {
        a.clear();
        while(n-- && scanf("%d", &item)) a.push_back(item);
        int result = maxSubArraySum();
        if(!result) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", result);
    }
    return 0;
}
