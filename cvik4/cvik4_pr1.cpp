#include <iostream>
#include <algorithm>
using namespace std;

class Color
{
private:
    int red, green, blue;

public:
    Color() : red(0), green(0), blue(0) {} // black
    Color(int level)
    {
        this->red = level;
        this->green = level;
        this->blue = level;
    }; // grey
    Color(int red, int green, int blue) : red(red), green(green), blue(blue) {} // custom
    Color operator+(const Color &other)
    {
        return Color(
            min(red += other.red, 255),
            min(green += other.green, 255),
            min(blue += other.blue, 255));
    }

    Color operator*(int factor)
    {
        if (factor < 0)
        {
            return 1;
        }
        return Color(
            min(red *= factor, 255),
            min(green *= factor, 255),
            min(blue *= factor, 255));
    }

    bool operator==(const Color &other)
    {
        if (red == other.red && green == other.green && blue == other.blue)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        cout << red << " " << green << " " << blue << endl;
    }
};

int main()
{

    int r1, g1, b1, r2, g2, b2, gl, f;
    cin >> r1 >> g1 >> b1 >> r2 >> g2 >> b2 >> gl >> f;

    if (r1 < 0 || r1 > 255 || g1 < 0 || g1 > 255 || b1 < 0 || b1 > 255 ||
        r2 < 0 || r2 > 255 || g2 < 0 || g2 > 255 || b2 < 0 || b2 > 255 ||
        gl < 0 || gl > 255 || f < 0 || f > 10)
    {
        cout << "Invalid Color";
        return 1;
    }
    Color black;
    cout << "Black: ";
    black.print();
    Color gray(gl);
    cout << "Gray: ";
    gray.print();
    Color first(r1, g1, b1);
    cout << "First: ";
    first.print();
    Color second(r2, g2, b2);
    cout << "Second: ";
    second.print();
    Color mixed = first.operator+(second);
    cout << "Mixed: ";
    mixed.print();
    Color scaled = mixed.operator*(f);
    cout << "Scaled: ";
    scaled.print();
    bool success = gray.operator==(scaled);
    if (success)
    {
        cout << "Matches gray: Yes";
    }
    else
    {
        cout << "Matches gray: No";
    }

    return 0;
}