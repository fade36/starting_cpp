#include <iostream>
using namespace std;

class Account
{
private:
    int balance;

public:
    Account(int balance = 0) : balance(balance) {}
    int getBalance()
    {
        return balance;
    }
    bool deposit(int amount)
    {
        if (amount < 0 || amount + balance > 1000000000)
        {
            return false;
        }
        balance += amount;
        return true;
    }
    bool withdraw(int amount)
    {
        if (amount < 0 || balance - amount < 0)
        {
            return false;
        }
        balance -= amount;
        return true;
    }
};
bool transfer(Account &from, Account &to, int amount)
{
    if (from.getBalance() < amount || amount < 0 || amount + to.getBalance() > 1000000000 || &from == &to)
    {
        return false;
    }
    from.withdraw(amount);
    to.deposit(amount);
    return true;
}

int main()
{
    int balance1, balance2, q;
    cin >> balance1 >> balance2 >> q;

    if (balance1 < 0 || balance1 > 1000000000 || balance2 < 0 || balance2 > 1000000000 || q < 0 || q > 100)
    {
        cout << "Invalid input" << endl;
        return 1;
    }

    Account account0(balance1);
    Account account1(balance2);

    Account *accounts[2] = {&account0, &account1};

    for (int i = 0; i < q; i++)
    {
        int from, to, amount;
        bool success;

        cin >> from >> to >> amount;
        if ((to != 0 && to != 1) || (from != 0 && from != 1) || (amount < -1000000000 || amount > 1000000000))
        {
            return 1;
        }
        success = transfer(*accounts[from], *accounts[to], amount);

        if (success)
        {
            cout << "OK " << account0.getBalance() << " " << account1.getBalance() << endl;
        }
        else
        {
            cout << "REJECTED " << account0.getBalance() << " " << account1.getBalance() << endl;
        }
    }

    cout << "Final: " << account0.getBalance() << " " << account1.getBalance() << endl;

    return 0;
}