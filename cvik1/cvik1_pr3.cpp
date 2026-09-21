#include <iostream>
#include <iomanip>

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

    double *arr = new double[n];

    std::cout << "Type double values in range -1000 to 1000:\n";

    for (int i = 0; i < n; ++i)
    {
        double temp;

        while (true)
        {
            std::cin >> temp;

            if (temp >= -1000 && temp <= 1000)
            {
                arr[i] = temp;
                break;
            }

            std::cout << "Invalid value. Type a number from -1000 to 1000: ";
        }
    }

    double min = arr[0];
    double max = arr[0];
    double sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];

        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    double mean = sum / n;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Mean: " << mean << '\n';
    std::cout << "Max: " << max << "   Min: " << min << '\n';

    int count_above = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cout << i + 1 << "    "
                  << arr[i] << "    "
                  << arr[i] - mean << '\n';

        if (arr[i] > mean)
        {
            ++count_above;
        }
    }

    std::cout << "Above mean: " << count_above << '\n';

    delete[] arr;

    return 0;
}