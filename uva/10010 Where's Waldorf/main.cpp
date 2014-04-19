/****************************************************
 * Author      : Kaidul Islam
 * University  : Khulna University of Engr. and Tech.
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rep1(i, n) for(__typeof(n) i = 1; i <= (n); i++)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1 << 30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof x)
#define eps 1e-9
#define pii pair<int, int>
#define couple make_pair
#define X first
#define Y second
#define vi vector<int>
#define vpii vector< pii >
#define si set<int>
#define SDi(x) sf("%d", &x)
#define SD2(x, y) sf("%d %d", &x, &y)
#define SD3(x, y, z) sf("%d %d %d", &x, &y, &z)
#define SDs(x) sf("%s", x)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define newLine pf("\n")
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#if ( _WIN32 or __WIN32__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define SDl(x) sf(LLD, &x)
#define MAX6 1000000
#define MAX7 10000000
#define MAX9 1000000000
#define MOD7 (MAX7 + 7)
#define MOD9 (MAX9 + 9)
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])
typedef long long i64;
typedef unsigned long long ui64;
const i64 INF64 = (i64)1E18;

// BitMask
int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
int Check(int N, int pos) {
    return (N & (1 << pos));
}
int toggle(int N, int pos) {
    if( Check(N, pos) )
        return N = Reset(N, pos);
    return N = Set(N, pos);
}

// direction array
//int dx[] = {0, -1, 0, 1};
//int dy[] = {-1, 0, 1, 0};
int Dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int Dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int row, col;
bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < row and j < col;
}

/** Implementation **/

#define Max 55
char grid[Max][Max];
char words[25][2 * Max];
struct result {
    bool found;
    int m, n;
    result() {
        found = false;
    };
    result(int R, int C, bool yes) {
        m = R, n = C, found = yes;
    }
} results[25];
int q;

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
typedef struct trie_node trie_node_t;
struct trie_node {
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

// trie ADT
typedef struct trie trie_t;
struct trie {
    trie_node_t *root;
    int count;
};

// Returns new trie node (initialized to NULLs)
trie_node_t *getNode(void) {
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode ) {
        int i;
        pNode->value = 0;
        for(i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}

// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie) {
    pTrie->root = getNode();
    pTrie->count = 0;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trie_t *pTrie, char key[]) {
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] ) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->value = pTrie->count;
}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    // WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    trie_t trie;
    int indx, n = ARRAY_SIZE(Dx);
    char c;
    SDi(tcase);
    while(tcase--) {
        SD2(row, col);
        getc(stdin);
        rep(i, row) {
            indx = 0;
            while((c = getchar()) != '\n')
                grid[i][indx++] = tolower(c);
            grid[i][indx] = '\0';
        }
        SDi(q);
        getc(stdin);
        trie_t *pTrie = &trie;
        initialize(pTrie);
        rep(i, q) {
            indx = 0;
            while((c = getchar()) != '\n')
                words[i][indx++] = tolower(c);
            words[i][indx] = '\0';
            insert(pTrie, words[i]);
        }
        int index, posX, posY;
        trie_node_t *pCrawl, *start;
        rep(i, row) {
            rep(j, col) {
                c = grid[i][j];
                pCrawl = pTrie->root;
                index = CHAR_TO_INDEX(c);
                if( !pCrawl->children[index] ) continue;
                pCrawl = pCrawl->children[index];
                if(0 != pCrawl and pCrawl->value) {
                    indx = pCrawl->value;
                    if(results[indx].found == false) {
                        results[indx] = result(i, j, true);
                    }
                }
                start = pCrawl;
                rep(k, n) {
                    posX = i + Dx[k], posY = j + Dy[k];
                    pCrawl = start;
                    while(isValid(posX, posY)) {
                        c = grid[posX][posY];
                        index = CHAR_TO_INDEX(c);
                        if(!pCrawl->children[index]) break;
                        pCrawl = pCrawl->children[index];
                        if(0 != pCrawl and pCrawl->value) {
                            indx = pCrawl->value;
                            if(results[indx].found == false) {
                                results[indx] = result(i, j, true);
                            }
                        }
                        posX += Dx[k], posY += Dy[k];
                    }
                }
            }
        }
        result ans;
        rep1(i, q) {
            ans = results[i];
            print(ans.m + 1);
            println(ans.n + 1);
            results[i] = result();
        }
        if(tcase) newLine;
    }
    return EXIT_SUCCESS;
}
