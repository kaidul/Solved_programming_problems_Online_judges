#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int lds(vector<int> height, vector<int> weight) {
    int Sum[height.size()];

    for (size_t i = 0; i < height.size(); i++) {
        Sum[i] = weight[i];
        for (size_t j = 0; j < i; j++)
            if (height[i] < height[j])
                Sum[i] = max(Sum[i], Sum[j] + weight[i]);
    }
    return *max_element(Sum, Sum + height.size());
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<int> height(N), weight(N);

        for (int i = 0; i < N; i++)	scanf("%d", &height[i]);
        for (int i = 0; i < N; i++)	scanf("%d", &weight[i]);

        int LDS = lds(height, weight);
        reverse(height.begin(), height.end()), reverse(weight.begin(), weight.end());
        int LIS = lds(height, weight);
        if (LIS >= LDS)	printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, LIS, LDS);
        else			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, LDS, LIS);

    }
    return 0;
}
