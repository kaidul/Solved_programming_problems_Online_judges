#include <cstdio>

int n;
double target, capacity, mp, pos[99], price[99], min;

/*
target = the distance from the origin to the destination
capacity = gallon capacity of the automobile's fuel tank
mp = milage per gallon
cost = cost in dollars of filling the automobiles tank in the origination city
pos[] = distance in miles from the origination city to the gasoline station
price[] = price (in cents) per gallon of gasoline sold at that station
*/
void run(double cost, double location, double left, double now) {
    if (now == n) {
        left -= (target - location) / mp;
        if (left >= 0 && cost < min)
            min = cost;
        return;
    }
    for (int i = now; i < n; i++)
        // distance to next station from present location = pos[i] - location
        // left * mp = how much distance can be still gone
        if (left * mp >= (pos[i] - location)) {
            double newLeft = left - (pos[i] - location) / mp;
            // without taking gasoline from current station
            run(cost, pos[i], newLeft, i + 1);
            // taking gasoline
            run(cost + (capacity - newLeft) * price[i] * 0.01 + 2, pos[i], left, i + 1);
        }
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int caseNo = 0;
    double cost;
    while (scanf("%lf", &target) && target >= 0) {
        scanf("%lf%lf%lf%d", &capacity, &mp, &cost, &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &pos[i], &price[i]);
        min = 2e9;
        run(cost, 0, capacity, 0);
        printf("Data Set #%d\nminimum cost = $%.2lf\n", ++caseNo, min);
    }
    return 0;
}
