#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Item
{
    string name;
    int amount;
    double price;
};

double value(Item item)
{
    return item.price * item.amount;
}

int main()
{

    ifstream file("stock.txt");

    int n;
    double total = 0;

    if (!file)
    {
        cout << "File error";
        return 1;
    }

    file >> n;

    string helper;
    getline(file, helper);

    Item *item = new Item[n];

    for (int i = 0; i < n; i++)
    {
        getline(file, item[i].name);
        file >> item[i].amount >> item[i].price;
        getline(file, helper);
    }

    file.close();

    ofstream fileOutput("report.txt");

    double maxPrice = value(item[0]);
    string nameHighest = item[0].name;

    if (!fileOutput)
    {
        cout << "File error";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (maxPrice < value(item[i]))
        {
            maxPrice = value(item[i]);
            nameHighest = item[i].name;
        }
        total += value(item[i]);
        fileOutput << item[i].name << ": " << value(item[i]) << endl;
    }

    fileOutput << "Total: " << total << endl;
    fileOutput << "Highest: " << nameHighest << endl;

    delete[] item;
    fileOutput.close();
    return 0;
}