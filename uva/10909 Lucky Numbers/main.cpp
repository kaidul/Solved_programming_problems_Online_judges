/*
 *  Solution for problem 10909 'Lucky Number'.
 *
 *  The code uses a (simple) binary search tree to build the list of
 *  lucky numbers.
 */
#include <cstdio>
#include <cstring>

#define MAXN 670000	/* max. number of nodes in the tree */

/* Tree's housekeeping...*/
int left[MAXN], right[MAXN], parent[MAXN], key[MAXN], count[MAXN], N, root;

char lucky[2010000];

/* Returns the index of the k-th smallest element in the tree. */
int find(int k) {
    for (int x = root;;)
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
void rm(int x) {
    int y;

    if (left[x] != 0 && right[x] != 0) {
        if (count[right[x]] >= count[left[x]])
            for (y = right[x]; left[y] != 0; y = left[y]);
        else
            for (y = left[x]; right[y] != 0; y = right[y]);
        key[x] = key[y];
        x = y;
    }

    if (left[x] == 0 && right[x] == 0) {
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

/* Constructs a balanced tree with b-a+1 elements; returns index of its root.
   The tree's nodes will get consecutive indices in their order in the tree. */
int build(int a, int b) {
    if (a > b) return 0;
    if (a == b) {
        N++;
        left[N] = right[N] = 0;
        count[N] = 1;
        return N;
    }

    int c=(a+b)/2, t = build(a, c-1);
    left[++N] = t;
    t = N;
    right[t] = build(c+1, b);
    count[t] = count[left[t]] + count[right[t]] + 1;
    parent[left[t]] = parent[right[t]] = t;
    return t;
}

void mark(int x) {
    for (; x; x = right[x])
        lucky[key[x]] = 1, mark(left[x]);
}

/* Constructs the list of lucky numbers */
void make() {
    int i, j, k;

    /* First off, initialize the tree... */

    N = count[0] = 0;
    parent[root = build(0, 666667)] = 0;

    /*
     *  As an optimization, we start with the tree, containing all numbers
     *  of form 6k+1 and 6k+3 in the range of interest.
     *  These are the numbers, which remain after the first two elimination
     *  rounds.
     */
    for (i = 1, j = 1; i <= 666700; j += 6)
        key[i++] = j, key[i++] = j+2;

    /* Now just simulation... */
    for (k = 2; k < count[root]; k++) {
        j = key[find(k)]-1;
        if (j >= count[root]) break;

        for (i = j; i < count[root]; i += j)
            rm(find(i));
    }

    /* Finally, mark the remaining numbers in the boolean array lucky[] */
    memset(lucky, 0, sizeof(lucky));
    mark(root);
}

int main() {
    int a, n;

    for (make(); scanf("%d", &n) == 1;) {
        a = 0;
        if (n >= 1 && (n & 1) == 0) {
            for (a = n/2; a > 0 && !lucky[a]; a--);
            for (; a > 0; a -= 2)
                if (lucky[a] && lucky[n-a]) break;
        }

        if (a <= 0)
            printf("%d is not the sum of two luckies!\n", n);
        else
            printf("%d is the sum of %d and %d.\n", n, a, n-a);
    }

    return 0;
}
