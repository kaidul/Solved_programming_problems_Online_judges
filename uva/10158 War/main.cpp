#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

int n;

#if 0 // AC but less elegant

#define MAXN 10005

struct Node {
    int parent, rank;
    vector<int> enemyList;
} nodes[MAXN];

void initSet() {
    for(int i = 0; i < n; ++i) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
        nodes[i].enemyList.clear();
    }
}

int findSet(int x) {
    if(nodes[x].parent == x) return x;
    return nodes[x].parent = findSet(nodes[x].parent);
}

int setFriends(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if(x == y) return 1;
    for(int i = 0; i < nodes[y].enemyList.size(); ++i) {
        if(nodes[y].enemyList[i] == x) {
            return -1;
        }
    }
    if(nodes[x].rank > nodes[y].rank) swap(x, y);
    nodes[x].parent = y;
    for(int i = 0; i < nodes[x].enemyList.size(); ++i) {
        nodes[y].enemyList.push_back(nodes[x].enemyList[i]);
        for(int j = 0; j < nodes[nodes[x].enemyList[i]].enemyList.size(); ++j) {
            if(nodes[nodes[x].enemyList[i]].enemyList[j] == x) {
                nodes[nodes[x].enemyList[i]].enemyList[j] = y;
            }
        }
    }
    nodes[x].enemyList.clear();

    if(nodes[x].rank == nodes[y].rank) {
        nodes[y].rank++;
    }
    return 1;
}

int setEnemies(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if(x == y) return -1;
    // x is already an enemy of y
    for(int i = 0; i < nodes[y].enemyList.size(); ++i) {
        if(nodes[y].enemyList[i] == x) {
            return 1;
        }
    }
    // if x and y have any common enemy
    for(int i = 0; i < nodes[x].enemyList.size(); ++i) {
        for(int j = 0; j < nodes[y].enemyList.size(); ++j) {
            if(nodes[x].enemyList[i] == nodes[y].enemyList[j]) {
                return -1;
            }
        }
    }
    // all y's enemy will become x's friends
    for(int i = 0; i < nodes[y].enemyList.size(); ++i) {
        setFriends(x, nodes[y].enemyList[i]);
    }
    // all x's enemy will become y's friends
    for(int i = 0; i < nodes[x].enemyList.size(); ++i) {
        setFriends(y, nodes[x].enemyList[i]);
    }
    x = findSet(x);
    y = findSet(y);
    nodes[x].enemyList.push_back(y);
    nodes[y].enemyList.push_back(x);
}


bool areFriends(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    return x == y;
}

bool areEnemies(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    for(int i = 0; i < nodes[x].enemyList.size(); ++i) {
        if(nodes[x].enemyList[i] == y) {
            return true;
        }
    }
    return false;
}
#else

#define MAXN 10000

int representative[MAXN * 2 + 10];

void initSet() {
    for(int i = 0; i <= 2 * n; ++i) {
        representative[i] = i;
    }
}

int findSet(int x) {
    if(representative[x] == x) return x;
    return representative[x] = findSet(representative[x]);
}

int setFriends(int x, int y) {
    int setX = findSet(x);
    int setY = findSet(y);
    int enemySetX = findSet(x + n);
    int enemySetY = findSet(y + n);
    if(setX == enemySetY or setY == enemySetY) {
        return -1;
    }
    representative[setX] = setY;
    representative[enemySetX] = enemySetY;
    return 1;
}

int setEnemies(int x, int y) {
    int setX = findSet(x);
    int setY = findSet(y);
    int enemySetX = findSet(x + n);
    int enemySetY = findSet(y + n);
    if(setX == setY) {
        return -1;
    }
    // frienship is mutual
    representative[enemySetX] = setY;
    representative[enemySetY] = setX;
    return 1;
}

bool areFriends(int x, int y) {
    return findSet(x) == findSet(y);
}

bool areEnemies(int x, int y) {
    int setX = findSet(x);
    int setY = findSet(y);
    int enemySetX = findSet(x + n);
    int enemySetY = findSet(y + n);
    return setX == enemySetY or setY == enemySetX;
}

#endif
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int x, y, opcode;
    while(scanf("%d", &n) == 1) {
        initSet();
        while(scanf("%d %d %d", &opcode, &x, &y)) {
            if(opcode == 0 and x == 0 and y == 0) break;
            switch(opcode) {
            case 1:
                if(setFriends(x, y) == -1) {
                    printf("-1\n");
                }
                break;
            case 2:
                if(setEnemies(x, y) == -1) {
                    printf("-1\n");
                }
                break;
            case 3:
                printf("%d\n", areFriends(x, y));
                break;
            case 4:
                printf("%d\n", areEnemies(x, y));
                break;
            }
        }
    }
    return 0;
}
