#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
typedef complex <double> point;
#define X real();
#define Y imag();
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).X,(a).Y)
#define angle(a) atan2((a).Y,(a).X)
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vex(a,v),t)+(a))
#define reflect(V,M) (conj((V)/(M))*(M))
#define EPS 1.0e-8

bool pointOnLine(const point &a, const point &b, const point &p) {
    return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}

bool intersect(const point &a, const point &b, const point &p, const point &q, point &ret) {
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1-d2) > EPS;
}

int main() {
    int x1,x2,x3,x4,y1,y2,y3,y4,tc;
    cin >> tc;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for(int i = 0 ; i < tc ; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point firstS(x1,y1);
        point firstE(x2,y2);
        point secondS(x3,y3);
        point secondE(x4,y4);
        point ret;
        if(intersect(firstS , firstE,secondS,secondE,ret)) {
            printf("POINT %.2f %.2f\n", ret.real(), ret.imag());
        } else {
            if(pointOnLine(firstS , firstE,secondS)) {
                cout << "LINE" << endl;
            } else
                cout << "NONE" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;


    return 0;
}
