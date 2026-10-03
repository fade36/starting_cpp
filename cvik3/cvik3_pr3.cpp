#include <iostream>
using namespace std;

class Warehouse
{
private:
    int *stock;
    int size;

public:
    Warehouse(int size, int quantities[]) : size(size)
    {
        stock = new int[size];
        for (int i = 0; i < size; i++)
        {
            stock[i] = quantities[i];
        }
    }
    int getSize()
    {
        return size;
    }
    int getQuantity(int index)
    {
        return stock[index];
    }
    bool replenish(int index, int amount)
    {
        if (index < 0 || index > size - 1 || amount <= 0 || stock[index] + amount > 1000000)
        {
            return false;
        }
        stock[index] += amount;
        return true;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << stock[i] << " ";
        }
        cout << endl;
    }
    ~Warehouse()
    {
        delete[] stock;
    }
};
bool replenish(Warehouse &warehouse, int index, int amount)
{
    return warehouse.replenish(index, amount);
}

Warehouse *afterOrder(Warehouse &warehouse, int order[], int count)
{
    if (count != warehouse.getSize())
    {
        return nullptr;
    }
    int *remaining = new int[count];

    for (int i = 0; i < count; i++)
    {
        if (order[i] < 0 || warehouse.getQuantity(i) < order[i])
        {
            delete[] remaining;
            return nullptr;
        }
        remaining[i] = warehouse.getQuantity(i) - order[i];
    }
    Warehouse *new_warehouse = new Warehouse(count, remaining);
    delete[] remaining;

    return new_warehouse;
}

void checkRange(int a, int boudary1, int boudary2)
{
    if (a < boudary1 || a > boudary2)
    {
        cout << "Invalid" << endl;
        return;
    }
}

void releaseWarehouse(Warehouse *&result)
{
    if (result == nullptr)
    {
        return;
    }
    delete result;
    result = nullptr;
}

int main()
{
    int n;
    cin >> n;
    checkRange(n, 1, 100);

    int *temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
        if (temp[i] < 0 || temp[i] > 1000000)
        {
            cout << "Invalid quantity" << endl;
            delete[] temp;
            return 1;
        }
    }
    Warehouse warehouse(n, temp);
    delete[] temp;

    int q;
    cin >> q;
    checkRange(q, 0, 100);

    for (int i = 0; i < q; i++)
    {
        int index, amount;
        cin >> index >> amount;
        if (index < -100 || index > 200 || amount < -1000000 || amount > 1000000)
        {
            return 1;
        }
        bool success = replenish(warehouse, index, amount);
        if (success)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "REJECTED" << endl;
        }
    }

    int m;
    cin >> m;
    checkRange(m, 1, 100);
    int *quantities = new int[m];

    for (int i = 0; i < m; i++)
    {
        cin >> quantities[i];
        checkRange(quantities[i], -1000000, 1000000);
    }
    Warehouse *new_warehouse = afterOrder(warehouse, quantities, m);
    delete[] quantities;

    if (new_warehouse == nullptr)
    {
        cout << "Order rejected" << endl;
    }
    else
    {
        cout << "Result: ";
        new_warehouse->print();
        releaseWarehouse(new_warehouse);
        cout << "Released" << endl;
    }
    cout << "Original: ";
    warehouse.print();

    return 0;
}