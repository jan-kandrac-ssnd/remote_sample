#include <iostream>
#include <unordered_set>

using namespace std;

u_int64_t next(u_int64_t input) {
    u_int64_t sum = 0;
    while (input != 0) {
        const u_int64_t a = input % 10;
        input = input / 10;
        sum += a * a;
    }
    return sum;
}

int main5() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        unordered_set<u_int64_t> memo;
        u_int64_t num;
        cin >> num;
        while (num != 1) {
            if (memo.contains(num)) {
                cout << -1 << endl;
                break;
            }
            memo.emplace(num);
            num = next(num);
        }
        if (memo.contains(num)) continue;
        cout << memo.size() << endl;
    }
    return 0;
}
