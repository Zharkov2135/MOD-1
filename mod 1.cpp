#include <iostream>
#include <stdexcept>
using namespace std;

class coord {
    int x, y;

public:
    coord() {
        x = 0;
        y = 0;
    }

    coord(int i, int j) {
        x = i;
        y = j;
    }

    void get_xy(int& i, int& j) {
        i = x;
        j = y;
    }

    // ogoloshennia operatora /
    coord operator/(const coord& other) const;
};

// vyznachennia operatora /
coord coord::operator/(const coord& other) const {
    if (other.x == 0 || other.y == 0) {
        throw runtime_error("Dilenniia na nul u poli x abo y");
    }
    return coord(x / other.x, y / other.y);
}

int main() {
    try {
        int x1, y1, x2, y2;

        cout << "Vvedit koordynaty pershoho obiekta (x y): ";
        cin >> x1 >> y1;

        cout << "Vvedit koordynaty druhoho obiekta (x y): ";
        cin >> x2 >> y2;

        coord a(x1, y1);
        coord b(x2, y2);

        coord c = a / b;   // vyklyk operatora /

        int i, j;
        c.get_xy(i, j);

        cout << "Rezultat dilennia: (" << i << ", " << j << ")" << endl;
    }
    catch (const exception& e) {
        cout << "Vynyatok: " << e.what() << endl;
    }

    return 0;
}
