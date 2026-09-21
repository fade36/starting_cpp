#include <iostream>
#include <iomanip>

double price(int pages, int copies)
{
    double total = pages * copies * 0.08 + 2;
    return total;
}

double volume(int pages, int copies)
{
    double total = pages * copies * 0.06 + 5;

    if (pages * copies >= 500)
    {
        total *= 0.9;
    }
    return total;
}

int main()
{
    int pages = 0;
    int copies = 0;

    std::cout << "Type number of pages and copies" << std::endl;
    std::cin >> pages >> copies;
    std::cout << "Basic: " << std::fixed << std::setprecision(2) << price(pages, copies) << std::endl;
    std::cout << "Volume: " << std::fixed << std::setprecision(2) << volume(pages, copies) << std::endl;
    if (price(pages, copies) > volume(pages, copies))
    {
        std::cout << "Choise: Volume" << std::endl;
    }
    else if (price(pages, copies) < volume(pages, copies))
    {
        std::cout << "Choise: Basic" << std::endl;
    }
    else
    {
        std::cout << "Same price" << std::endl;
    }

    return 0;
}