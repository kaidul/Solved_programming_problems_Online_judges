#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> t;
    int cs = 0;
    while(t--) {
        cs++;
        double a, b, c;
        cin >> a >> b >> c;
        double time = 0.0;
        double rate = 2;
        cout << "Case #" << cs << ": ";
        while(1) {
                double ntime = a/(rate);
                double res = c/rate;
                ntime += c/(rate+b);
                if(ntime >= res) {
                    printf("%.8f\n" , time+res);
                    break;
                }
                time += a/rate;
                rate += b;
        }
    }
}
