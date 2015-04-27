#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int N, Q;
vector<vector<int> > input;
vector<vector<int> > sqrtArr;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int elem;
    scanf("%d %d", &N, &Q);
    int sqrtN = (int) sqrt(N);
    int Set = N / sqrtN;
    for(int i = 0; i < Set; ++i) {
        vector<int> vec;
        for(int j = 0; j < sqrtN; ++j) {
            scanf("%d", &elem);
            vec.push_back(elem);
        }
        sqrtArr.push_back(vec);
        input.push_back(vec);
    }
    vector<int> vec;
    for(int i = Set * sqrtN; i < N; ++i) {
        scanf("%d", &elem);
        vec.push_back(elem);
    }
    if(Set * sqrtN != N) {
        sqrtArr.push_back(vec);
        input.push_back(vec);
    }

    for(int i = 0, n = sqrtArr.size(); i < n; ++i) {
        sort(sqrtArr[i].begin(), sqrtArr[i].end());
    }
    char query;
    int start, end, idx, X;
    for(int i = 0; i < Q; ++i) {
        getchar();
        scanf("%c", &query);
        if(query == 'C') {
            int cnt = 0;
            scanf("%d %d %d", &start, &end, &X);
            start--, end--, X;
            int leftBlock = start / sqrtN;
            int rightBlock = end / sqrtN;
            start -= leftBlock * sqrtN;
            end -= rightBlock * sqrtN;
            if(leftBlock == rightBlock) {
                for(int i = start; i <= end; ++i) {
                    if(input[leftBlock][i] <= X)
                        cnt++;
                }
            } else {
                for(int i = start; i < input[leftBlock].size(); ++i) {
                    if(input[leftBlock][i] <= X)
                        cnt++;
                }
                for(int i = leftBlock + 1; i < rightBlock; ++i) {
                    cnt += upper_bound(sqrtArr[i].begin(), sqrtArr[i].end(), X) - sqrtArr[i].begin();
                }
                for(int i = 0; i <= end; ++i) {
                    if(input[rightBlock][i] <= X)
                        cnt++;
                }
            }
            printf("%d\n", cnt);
        } else {
            scanf("%d %d", &idx, &X);
            idx--;
            int block = idx / sqrtN;
            idx -= (block * sqrtN);
            input[block][idx] = X;
            sqrtArr[block] = input[block];
            sort(sqrtArr[block].begin(), sqrtArr[block].end());
        }
    }
    return 0;
}
