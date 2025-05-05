#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class SizeMismatchError : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix sizes do not match.";
    }
};

class InvalidSizeError : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix has invalid size.";
    }
};

template<typename Type>
class Grid {
private:
    int height, width;
    vector<vector<Type>> cells;

public:
    Grid() : height(2), width(2), cells(2, vector<Type>(2, Type())) {}

    Grid(int h, int w) : height(h), width(w) {
        if (h <= 0 || w <= 0)
            throw InvalidSizeError();
        cells = vector<vector<Type>>(h, vector<Type>(w, Type()));
    }

    void place(int row, int col, Type value) {
        if (row < 0 || row >= height || col < 0 || col >= width)
            throw out_of_range("Index outside grid.");
        cells[row][col] = value;
    }

    Type access(int row, int col) const {
        if (row < 0 || row >= height || col < 0 || col >= width)
            throw out_of_range("Index outside grid.");
        return cells[row][col];
    }

    int totalRows() const { return height; }
    int totalCols() const { return width; }

    Grid<Type> operator+(const Grid<Type>& other) const {
        if (height != other.height || width != other.width)
            throw SizeMismatchError();

        Grid<Type> result(height, width);
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                result.cells[i][j] = cells[i][j] + other.cells[i][j];

        return result;
    }

    Grid<Type> operator*(const Grid<Type>& other) const {
        if (width != other.height)
            throw SizeMismatchError();

        Grid<Type> result(height, other.width);
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < other.width; ++j)
                for (int k = 0; k < width; ++k)
                    result.cells[i][j] += cells[i][k] * other.cells[k][j];

        return result;
    }

    void display() const {
        for (const auto& row : cells) {
            for (const auto& item : row)
                cout << item << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        Grid<int> one(2, 2);
        Grid<int> two(2, 2);

        one.place(0, 0, 1);
        one.place(0, 1, 2);
        one.place(1, 0, 3);
        one.place(1, 1, 4);

        two.place(0, 0, 5);
        two.place(0, 1, 6);
        two.place(1, 0, 7);
        two.place(1, 1, 8);

        cout << "Grid One:\n";
        one.display();

        cout << "\nGrid Two:\n";
        two.display();

        Grid<int> summed = one + two;
        cout << "\nOne + Two:\n";
        summed.display();

        Grid<int> multiplied = one * two;
        cout << "\nOne * Two:\n";
        multiplied.display();

        cout << "\nCreating invalid grid...\n";
        Grid<int> fail(-3, 4);

    } catch (const InvalidSizeError& err) {
        cerr << "Caught: " << err.what() << endl;
    }

    try {
        cout << "\nAdding mismatched grids...\n";
        Grid<int> a(3, 3), b(2, 3);
        Grid<int> c = a + b;
    } catch (const SizeMismatchError& err) {
        cerr << "Caught: " << err.what() << endl;
    }

    try {
        cout << "\nMultiplying incompatible grids...\n";
        Grid<int> x(2, 3), y(2, 2);
        Grid<int> z = x * y;
    } catch (const SizeMismatchError& err) {
        cerr << "Caught: " << err.what() << endl;
    }

    try {
        cout << "\nAccessing out-of-bounds...\n";
        Grid<int> test(2, 2);
        int value = test.access(5, 0);
    } catch (const out_of_range& err) {
        cerr << "Caught: " << err.what() << endl;
    }

    try {
        cout << "\nSetting out-of-bounds value...\n";
        Grid<int> test(2, 2);
        test.place(0, 5, 99);
    } catch (const out_of_range& err) {
        cerr << "Caught: " << err.what() << endl;
    }

    return 0;
}
