#include <iostream>

using namespace std;

int main2() {
    int n, num, first = -1, second = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > second) { second = num; }
        if (num > first) { second = first; first = num; }
    }
    cout << first << " " << second << std::endl;
    return 0;
}
