#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector <int> a;

int kadane(int *start, int *end) {
    int max_so_far = INT_MIN, max_ending_here = 0, size = a.size();
    *start = 0;
    for(int i = 0; i < size; i++) {
        max_ending_here += a[i];

        if(max_ending_here < 0)
            max_ending_here = 0, *start = i + 1;

        if(max_so_far < max_ending_here)
            *end = i, max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, item, start, end;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &item);
    	a.push_back(item);
    }
    int max_sum = kadane(&start, &end);
    printf("%d\n", max_sum);
    return 0;
}
