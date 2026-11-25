#include <iostream>
#include <regex>

using namespace std;

int main3() {
    string text;
    cin >> text;
    cout << (regex_match(text, regex("[A-Z]{2}[0-9]{3}[A-Z]{2}")) ? "Ano" : "Nie") << endl;
    return 0;
}
