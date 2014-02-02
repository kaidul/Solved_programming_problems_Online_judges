#include<iostream>
#include<cstdio>
using namespace std;

int m, k;
int a[500], s[500], e[500];

int greed( long long work ) {
    int last = 0;

    for(int i = 0; i < k; i++) {
        long long sum = 0;
        int j;
        for(j = last; j < m; j++) {
            sum += a[j];
            if (sum > work) break;
        }
        last = j;
    }

    if(last == m) return 1;
    else return 0;
}


void rgreed(long long work) {
    int last = m;
    for(int i = k - 1; i >= 0; i--) {
        long long sum = 0;
        int j;
        e[i] = last - 1;
        for(j = e[i]; j >= 0; j--) {
            sum += a[j];
            if(sum > work) break;
        }
        s[i] = last = j + 1;
    }
    for(int i = 0; i < k; i++) {
        while(e[i] < s[i]) {
            e[i]++, s[i + 1]++;
        }
    }
}

void print() {
    for(int i = 0; i < k; i++) {
        if(i) printf(" /");
        for(int j = s[i]; j <= e[i]; j++) {
            if(j) printf(" ");
            printf("%d", a[j]);
        }
    }
    printf("\n");
}

int main(void) {
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> m >> k;
        long long left = 0, right = 0, middle;
        for(int j = 0; j < m; j++) {
            cin >> a[j];
            right += a[j];
        }
        // binary search
        while(left < right) {
            middle = left + (right - left) / 2;
            if( greed( middle ) )
                right = middle;
            else
                left = middle + 1;
        }
        rgreed( right );
        print();
    }
}
