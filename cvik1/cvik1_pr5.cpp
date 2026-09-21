#include <iostream>
using namespace std;

struct Rectangle
{
    int x, y, width, height; // x and y define left bottom corner
};

namespace geometry
{
    Rectangle shifted(Rectangle r, int dx, int dy)
    {
        r.x = r.x + dx;
        r.y = r.y + dy;
        return r;
    }

    bool fits(Rectangle r, int boarderW, int boarderH)
    {
        return r.x >= 0 && r.y >= 0 && r.x + r.width <= boarderW && r.y + r.height <= boarderH;
    }
}

int main()
{
    Rectangle r;
    int dx, dy, boarderW, boarderH;
    cin >> r.x >> r.y >> r.width >> r.height >> dx >> dy >> boarderW >> boarderH;
    Rectangle *copy = new Rectangle;

    *copy = geometry::shifted(r, dx, dy);
    cout << "Original: " << r.x << " " << r.y << endl;
    cout << "Proposal: " << copy->x << " " << copy->y << endl;
    if (geometry::fits(*copy, boarderW, boarderH))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    delete copy;
    return 0;
}