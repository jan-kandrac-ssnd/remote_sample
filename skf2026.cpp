#include <iostream>
#include <set>

using namespace std;

struct Position { int x = 0, y = 0; };

static bool operator<(const Position a, const Position b){ return a.x == b.x ? a.y < b.y : a.x < b.x; }
static bool operator==(const Position a, const Position b){ return a.x == b.x && a.y == b.y; }

set<Position> visited;

inline bool is_neighbor(const Position &old_position, const Position &position) {
    return position != old_position && visited.contains(position);
}

int main6() {
    string input;
    cin >> input;
    Position old_pos;
    for (const char c: input) {
        visited.emplace(old_pos);
        Position new_pos = old_pos;
        switch (c) {
            case 'S': new_pos.y--; break;
            case 'J': new_pos.y++; break;
            case 'V': new_pos.x++; break;
            case 'Z': new_pos.x--; break;
        }
        if (visited.contains(new_pos)) { cout << "L" << endl; return 0; }
        if (is_neighbor(old_pos, Position{.x = new_pos.x - 1, .y = new_pos.y})) { cout << "L" << endl; return 0; }
        if (is_neighbor(old_pos, Position{.x = new_pos.x + 1, .y = new_pos.y})) { cout << "L" << endl; return 0; }
        if (is_neighbor(old_pos, Position{.x = new_pos.x, .y = new_pos.y - 1})) { cout << "L" << endl; return 0; }
        if (is_neighbor(old_pos, Position{.x = new_pos.x, .y = new_pos.y + 1})) { cout << "L" << endl; return 0; }
        old_pos = new_pos;
    }
    cout << "W" << endl;

    return 0;
}
