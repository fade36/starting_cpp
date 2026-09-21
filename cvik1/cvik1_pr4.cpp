#include <iostream>

int main()
{
    int n;

    std::cout << "Type n in range 1-1000: ";
    std::cin >> n;

    if (n < 1 || n > 1000)
    {
        std::cout << "Invalid n\n";
        return 1;
    }

    int *arr = new int[n];

    std::cout << "Type integers in range -1000 to 1000:\n";

    for (int i = 0; i < n; ++i)
    {
        int value;

        while (true)
        {
            std::cin >> value;

            if (value >= -1000 && value <= 1000)
            {
                arr[i] = value;
                break;
            }

            std::cout << "Invalid value. Type a number from -1000 to 1000: ";
        }
    }

    int m;

    std::cout << "Type m in range 1-1000: ";
    std::cin >> m;

    if (m < 1 || m > 1000)
    {
        std::cout << "Invalid m\n";
        delete[] arr;
        return 1;
    }

    int *arr_new = new int[n + m];

    for (int i = 0; i < n; ++i)
    {
        arr_new[i] = arr[i];
    }

    delete[] arr;

    std::cout << "Type additional integers in range -1000 to 1000:\n";

    for (int i = n; i < n + m; ++i)
    {
        int value;

        while (true)
        {
            std::cin >> value;

            if (value >= -1000 && value <= 1000)
            {
                arr_new[i] = value;
                break;
            }

            std::cout << "Invalid value. Type a number from -1000 to 1000: ";
        }
    }

    for (int i = 0; i < n + m; ++i)
    {
        std::cout << arr_new[i] << ' ';
    }

    std::cout << '\n';

    int drops = 0;

    for (int i = 0; i < n + m - 1; ++i)
    {
        if (arr_new[i] > arr_new[i + 1])
        {
            ++drops;
        }
    }

    std::cout << "DROPS: " << drops << '\n';

    delete[] arr_new;

    return 0;
}