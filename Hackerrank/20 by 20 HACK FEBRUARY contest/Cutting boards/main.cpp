/*
// TLE Code
#include <bits/stdc++.h>

using namespace std;

#define _pair pair<int, int>
struct cordinate {
    int startX, startY;
    int endX, endY;
    cordinate() {}
    cordinate(int a, int b, int x, int y) {
        startX = a;
        startY = b;
        endX = x;
        endY = y;
    }
};
queue < cordinate > cordinates;
struct lines {
    char c;
    int indx;
    int cost;
    lines() {}
    lines(char x, int i, int y) { c = x; indx = i; cost = y;}
    bool operator < (const lines &other) const {
        return cost < other.cost;
    }
};
priority_queue < lines > q;
int main(void) {
    freopen("input.txt", "r", stdin);
    int tcase;
    cin >> tcase;
    int horiz, vertical;
    int m, n;
    while(tcase--) {
        cin >> m >> n;
        cordinates.push( cordinate(1, 1, m, n) );
        for(int i = 0; i < m - 1; ++i) {
            cin >> horiz;
            q.push( lines('y', i + 1, horiz) );
        }
        for(int i = 0; i < n - 1; ++i) {
            cin >> vertical;
            q.push( lines('x', i + 1, vertical) );
        }
        int totalCost = 0;
        while( !q.empty() ) {
            lines line = q.top();
//            cout << line.c << " " << line.cost << endl;
            if(line.c == 'y') {
                size_t size = cordinates.size();
                for(int i = 0; i < size; ++i) {
                    cordinate obj = cordinates.front();
                    cordinates.pop();
                    if( obj.endX >= line.indx and line.indx >= obj.startX ) {
                        totalCost += line.cost;
                        cordinates.push( cordinate(obj.startX, obj.startY, line.indx, obj.endY) );
                        cordinates.push( cordinate(line.indx + 1, obj.startY, obj.endX, obj.endY) );
                    } else {
                        cordinates.push( obj );
                    }
                }
            } else if(line.c == 'x') {
                size_t size = cordinates.size();
                for(int i = 0; i < size; ++i) {
                    cordinate obj = cordinates.front();
                    cordinates.pop();
                    if( obj.endY >= line.indx and line.indx >= obj.startY ) {
                        totalCost += line.cost;
                        cordinates.push( cordinate(obj.startX, obj.startY, obj.endX, line.indx));
                        cordinates.push( cordinate(obj.startX, line.indx + 1, obj.endX, obj.endY) );
                    } else {
                        cordinates.push( obj );
                    }
                }
            }
            q.pop();
        }
        cout << totalCost << endl;
        cordinates = queue < cordinate > ();
        q = priority_queue <lines> ();
     }
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

struct lines {
    char c;
    int cost;
    lines() {}
    lines(char x, int y) { c = x; cost = y;}
    bool operator < (const lines &other) const {
        return cost < other.cost;
    }
};
priority_queue < lines > q;

int main(void) {
//    freopen("input.txt", "r", stdin);
    int tcase;
    cin >> tcase;
    int x, y, totalCost;
    int m, n, cost;
    while(tcase--) {
        cin >> m >> n;
        for(int i = 0; i < m - 1; ++i) {
            cin >> cost;
            q.push( lines('x', cost) );
        }
        for(int i = 0; i < n - 1; ++i) {
            cin >> cost;
            q.push( lines('y', cost) );
        }
        x = y = 1;
        totalCost = 0;
        while( !q.empty() ) {
            lines line = q.top();
            if(line.c == 'y') {
                totalCost += (line.cost * x);
                ++y;
            } else {
                totalCost += (line.cost * y);
                ++x;
            }
            q.pop();
        }
        cout << totalCost << endl;
    }
    return 0;
}
