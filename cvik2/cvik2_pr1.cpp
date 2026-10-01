#include <iostream>
using namespace std;

class Tank
{
private:
    int capacity;
    int volume;

public:
    Tank(int capacity, int volume = 0) : capacity(capacity), volume(volume) {}
    int getVolume()
    {
        return volume;
    }
    int getFreeSpace()
    {

        return capacity - volume;
    }
    bool add(int amount);
    bool drain(int amount);
};
bool Tank::add(int amount)
{
    if (amount < 0 || amount + volume > capacity)
    {
        return false;
    }
    volume += amount;
    return true;
}
bool Tank::drain(int amount)
{
    if (amount < 0 || volume - amount < 0)
    {
        return false;
    }
    volume -= amount;
    return true;
}

int main()
{

    int c, v, q;
    cin >> c >> v >> q;

    if (c < 1 || c > 10000 || v < 0 || v > c || q < 0 || q > 100)
    {
        return 1;
    }

    Tank tank(c, v);

    for (int i = 0; i < q; i++)
    {
        char operation;
        int amount;

        cin >> operation >> amount;
        bool success;

        if (operation == '+')
        {
            success = tank.add(amount);
        }
        if (operation == '-')
        {
            success = tank.drain(amount);
        }
        if (success)
        {
            cout << "OK";
        }
        else
        {
            cout << "REJECTED";
        }
        cout << tank.getVolume() << endl;
    }

    cout << "Free Space: " << tank.getFreeSpace() << endl;

    return 0;
}