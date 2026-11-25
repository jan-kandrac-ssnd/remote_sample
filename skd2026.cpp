#include <iostream>
#include <cmath>

using namespace std;

int main4() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int interval_size = 2; interval_size < n; interval_size*=2) {
        for (int i = 0; i < n; i+= interval_size) {
            if (a > i && a <= i + interval_size && b > i && b <= i + interval_size) {
                cout << log2(interval_size) << endl;
                return 0;
            }
        }
    }
    cout << "To bude epicke!" << endl;
    return 0;
}
