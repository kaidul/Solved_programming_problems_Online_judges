/**
You can use a binary search tree to generate the list of luckies.
The tree should be able to remove an element and return k-th smallest element in O(log n) time.

Once you have this list, you can solve each test case by bruteforcing L1, starting from L1 = floor(N / 2) and going down to 1.

Also note, that no odd number can be represented as a sum of luckies.
**/
#include <bits/stdc++.h>

#define Max 666667	/* max. number of nodes in the tree */
#define MaxN 2000001

/* Tree's housekeeping...*/
int left[Max], right[Max], parent[Max], key[Max], count[Max], N, root;

/* Returns the index of the k-th smallest element in the tree. */
int find(int k) {
    for (int x = root; ;)
        if (k < count[left[x]])
            x = left[x];
        else if (k == count[left[x]])
            return x;
        else
            k -= count[left[x]] + 1, x = right[x];
}

/*
 *  Removes the element with index 'x' from the tree.
 *  Implemented algorithm ensures that the height of the tree does not increase.
 */
void remove(int x) {
    int y;

    if (left[x] != 0 and right[x] != 0) {
        if (count[right[x]] >= count[left[x]])
            for (y = right[x]; left[y] != 0; y = left[y]);
        else
            for (y = left[x]; right[y] != 0; y = right[y]);
        key[x] = key[y];
        x = y;
    }

    if (left[x] == 0 and right[x] == 0) {
        if (left[parent[x]] == x)
            left[parent[x]] = 0;
        else
            right[parent[x]] = 0;
    } else {
        y = (left[x] == 0) ? right[x] : left[x];

        if (parent[x] == 0) {
            parent[root = y] = 0;
            return;
        }

        if (left[parent[x]] == x)
            left[parent[x]] = y;
        else
            right[parent[x]] = y;
        parent[y] = parent[x];
    }

    for (x = parent[x]; x != 0; x = parent[x])
        count[x]--;
}

/* Constructs a balanced tree with b - a + 1 elements; returns index of its root.
   The tree's nodes will get consecutive indices in their order in the tree. */
int build(int a, int b) {
    if (a > b) return 0;
    if (a == b) {
        N++;
        left[N] = right[N] = 0;
        count[N] = 1;
        return N;
    }
    int c = (a + b) / 2;
    int t = build(a, c - 1);
    left[++N] = t;
    t = N;
    right[t] = build(c + 1, b);
    count[t] = count[left[t]] + count[right[t]] + 1;
    parent[left[t]] = parent[right[t]] = t;
    return t;
}

/* Constructs the list of lucky numbers */
void make() {
    int i, j, k;

    /* First off, initialize the tree... */

    N = count[0] = 0;
    root = build(0, Max);
    parent[root] = 0;

    /*
     *  As an optimization, we start with the tree, containing all numbers
     *  of form 6k + 1 and 6k + 3 in the range of interest.
     *  These are the numbers, which remain after the first two elimination
     *  rounds.
     */
    for (i = 1, j = 1; i <= Max; j += 6)
        key[i++] = j, key[i++] = j + 2;

    /* Now just simulation... */
    for (k = 2; k < count[root]; k++) {
        j = key[find(k)] - 1;
        if (j >= count[root]) break;

        for (i = j; i < count[root]; i += j)
            remove(find(i));
    }

}

int main(void) {
    int tcase, caseNo = 0, n;
    make();
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++caseNo, key[find(n - 1)]);
    }
    return 0;
}
