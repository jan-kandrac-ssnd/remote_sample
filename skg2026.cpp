#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    long long p, n;
    cin >> p >> n;
    long long cars[n];
    long long rides[n];
    long long fuel[n];
    for (int i = 0; i < n; i++) { cin >> cars[i]; rides[i] = 0; fuel[i] = 0; }

    long long cycle_size = std::accumulate(cars, cars + n, 1LL, [](const long long &a, const long long &b) { return std::lcm(a, b + 1); });
    long long cycle_burn = std::accumulate(cars, cars + n, 0LL, [cycle_size](const long long &a, const long long &b) { return a + cycle_size / (b + 1) * b; });
    long long cycles = p / cycle_burn;
    for (int i = 0; i < n; i++) { rides[i] = cars[i] * cycles; }

    p %= cycle_burn;

    for (int i = 0; i < n; i++) { fuel[i] = min(p, cars[i]); p -= fuel[i]; }

    while (any_of(fuel, fuel + n, [](const int &f) { return f > 0; })) {
        // fuel to be burned by each car
        long long step = *min_element(fuel, fuel + n);
        // burning fuel
        if (step != 0) for (int i = 0; i < n; i++) { fuel[i] -= step; rides[i] += step; }
        // refueling (or adding one more ride)
        bool repeat = true;
        while (repeat) {
            repeat = false;
            for (int i = 0; i < n; i++) {
                if (fuel[i] == 0) {
                    fuel[i] = min(p, cars[i]);
                    p -= fuel[i];
                } else {
                    --fuel[i];
                    ++rides[i];
                    if (fuel[i] == 0) repeat = true;
                }
            }
        }
    }

    cout << distance(rides, max_element(rides, rides + n)) << endl;

    return 0;
}
