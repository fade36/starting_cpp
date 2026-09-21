#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file_in("notes.txt");
    std::ofstream file_out("numbered.txt");

    if (!file_in)
    {
        std::cerr << "Cannot open notes.txt\n";
        return 1;
    }

    if (!file_out)
    {
        std::cerr << "Cannot open numbered.txt\n";
        return 1;
    }

    std::string line;
    int line_count = 0;
    int written_count = 0;

    while (std::getline(file_in, line))
    {
        ++line_count;

        if (!line.empty())
        {
            file_out << line_count << ": " << line << '\n';
            ++written_count;
        }
    }

    std::cout << "Read: " << line_count << '\n';
    std::cout << "Write: " << written_count << '\n';

    return 0;
}