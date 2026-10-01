#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;

public:
    Book(string title) : title(title) {}
    string getTitle()
    {
        return title;
    }
};

class Bookshelf
{
private:
    Book **slots;
    int size;

public:
    Bookshelf(int size) : size(size) { slots = new Book *[size](); }

    bool add(int index, std::string title)
    {

        if (index < 0 || index >= size)
            return false;
        if (slots[index] != nullptr)
            return false;

        slots[index] = new Book(title);
        return true;
    }

    bool take(int index, std::string &title)
    {

        if (index < 0 || index >= size || slots[index] == nullptr)
        {
            return false;
        }

        title = slots[index]->getTitle();
        delete slots[index];
        slots[index] = nullptr;

        return true;
    }

    bool resize(int newSize)
    {

        if (newSize < 1 || newSize > 100)
        {
            return false;
        }
        if (newSize == size)
        {
            return true;
        }
        if (newSize < size)
        {
            for (int i = newSize; i < size; i++)
            {
                if (slots[i] != nullptr)
                {
                    return false;
                }
            }
        }

        Book **new_slots = new Book *[newSize]();

        int limit = (newSize < size) ? newSize : size;

        for (int i = 0; i < limit; i++)
        {
            new_slots[i] = slots[i];
        }

        delete[] slots;

        slots = new_slots;
        size = newSize;

        return true;
    }

    void print()
    {
        cout << "Capacity: " << size << endl;
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            if (slots[i] != nullptr)
            {
                cout << i << ": " << slots[i]->getTitle() << endl;
                count++;
            }
        }
        cout << "Books: " << count << endl;
    }

    ~Bookshelf()
    {

        for (int i = 0; i < size; i++)
        {
            delete slots[i];
        }

        delete[] slots;

        cout << "RELEASED" << endl;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    if (n < 1 || n > 100 || q < 0 || q > 100)
    {
        return 1;
    }

    {
        Bookshelf bookshelf(n);

        for (int i = 0; i < q; i++)
        {
            char command;
            cin >> command;
            bool success;

            if (command == 'A')
            {
                int index;
                string title;
                cin >> index >> title;
                success = bookshelf.add(index, title);
                cout << (success ? "OK" : "REJECTED") << endl;
            }
            if (command == 'T')
            {
                int index;
                string title = "-";
                cin >> index;
                success = bookshelf.take(index, title);
                if (success)
                {
                    cout << "OK " << title << endl;
                }
                else
                {
                    cout << "REJECTED " << title << endl;
                }
            }
            if (command == 'R')
            {
                int size;
                cin >> size;
                success = bookshelf.resize(size);
                cout << (success ? "OK" : "REJECTED") << endl;
            }
        }
        bookshelf.print();
    }

    cout << "done" << endl;

    return 0;
}