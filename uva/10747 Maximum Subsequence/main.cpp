#include <cstdio>
#include <cctype>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long L;

bool cmpabs(L x, L y) {
    if (abs(x) != abs(y))
        return abs(x) > abs(y);
    return x > y;
}

L Sum(const vector<L> &v, int a, int b) {
    L res = 0;
    for (int i = a; i <= b; i++)
        res += v[i];
    return res;
}

L solve(vector<L> a, int K) {
    int N = a.size();
    if (K >= N) return Sum(a, 0, N-1);

    vector<L> a_dec = a;
    sort(a_dec.begin(), a_dec.end());
    reverse(a_dec.begin(), a_dec.end());

    if (K == 1) return a_dec[0];

    L zero_sum = Sum(a_dec, 0, K-1);
    if (a_dec[K-1] > 0) zero_sum -= a_dec[K-1];

    int pos = 0, neg = 0, zeroes = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) pos++;
        if (a[i] < 0) neg++;
        if (a[i] == 0) zeroes++;
    }

    sort(a.begin(), a.end(), cmpabs);

    if (pos + neg < K) {
        return Sum(a_dec, 0, K-1);
    }

    if (pos + neg == K) {
        if ((neg % 2) == 0) return Sum(a, 0, K-1);
        assert(zeroes > 0);
        return zero_sum;
    }

    if (pos == 0 && (K%2)==1) {
        if (zeroes > 0) return zero_sum;
        return Sum(a_dec, 0, K-1);
    }

    L sum = 0;
    int sign = +1, last_neg = -1, last_pos = -1;

    for (int i = 0; i < K; i++) {
        assert(a[i] != 0);
        if (a[i] < 0) {
            sign = -sign;
            last_neg = i;
        } else {
            last_pos = i;
        }
        sum += a[i];
    }
    if (sign > 0) return sum;

    assert(last_neg >= 0);

    int next_neg = -1, next_pos = -1;
    for (int i = K; i < N; i++) if (a[i] < 0) {
            next_neg = i;
            break;
        }
    for (int i = K; i < N; i++) if (a[i] > 0) {
            next_pos = i;
            break;
        }

    if (last_pos < 0) {
        assert(next_pos > 0);
        return sum - a[last_neg] + a[next_pos];
    }

    if (next_neg < 0 && next_pos < 0) {
        assert(false);
    }

    if (next_neg < 0) return sum - a[last_neg] + a[next_pos];
    if (next_pos < 0) return sum - a[last_pos] + a[next_neg];

    L val1 = abs(a[next_pos]) * abs(a[last_pos]);
    L val2 = abs(a[next_neg]) * abs(a[last_neg]);
    if (val1 > val2)
        return sum - a[last_neg] + a[next_pos];
    else if (val1 < val2)
        return sum - a[last_pos] + a[next_neg];
    else
        return max(sum - a[last_neg] + a[next_pos], sum - a[last_pos] + a[next_neg]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N, K;
    while (scanf("%d %d", &N, &K) == 2) {
        if (!N && !K) break;
        assert(1 <= K && K <= N && N <= 10000);

        vector <L> a(N);
        for (int i = 0; i < N; i++)
            scanf("%lld", &a[i]);
        printf("%lld\n", solve(a, K));
    }
}
