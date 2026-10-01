#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int minute;
    int hour;

public:
    Time(int hour, int minute) : hour(hour), minute(minute) {}
    int toMinute()
    {
        return minute + hour * 60;
    }
};

class Visit
{
private:
    string plate;
    Time arrival;
    Time departure;

public:
    Visit() : plate(""), arrival(0, 0), departure(0, 0) {}
    Visit(string plate, Time arrival, Time departure) : plate(plate), arrival(arrival), departure(departure) {}

    int duration()
    {
        int difference = departure.toMinute() - arrival.toMinute();

        if (difference < 0)
        {
            difference += 24 * 60;
        }
        return difference;
    }
    void setDeparture(Time time)
    {
        departure = time;
    }
    int price()
    {

        int minutes = duration();

        if (minutes == 0)
        {
            return 0;
        }

        int hours = (minutes + 59) / 60;
        return 150 + (hours - 1) * 100;
    }
    void print();
};
void Visit::print()
{
    cout << plate << ": " << duration() << " " << price() << endl;
}

bool correctDeparture(Visit &visit, int hour, int minute)
{
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        return false;
    }
    visit.setDeparture(Time(hour, minute));
    return true;
}

int main()
{

    int n;
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid count";
        return 1;
    }
    Visit *visits = new Visit[n];

    for (int i = 0; i < n; i++)
    {
        string plate;
        int ah, am, dh, dm;

        cin >> plate >> ah >> am >> dh >> dm;

        if (plate.length() > 5)
        {
            return 1;
            // here is needed beter way of checking values from user input
        }
        visits[i] = Visit(plate, Time(ah, am), Time(dh, dm));
    }

    int k, new_depH, new_depM;

    cin >> k >> new_depH >> new_depM;
    if (k < 0 || k > n - 1)
    {
        return 1;
    }

    Visit backup = visits[k];
    bool success = correctDeparture(visits[k], new_depH, new_depM);

    if (success)
    {
        cout << "OK";
    }
    else
    {
        cout << "REJECTED";
    }
    cout << "Current: ";
    visits[k].print();

    cout << "Backup: ";
    backup.print();

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        visits[i].print();
    }
    delete[] visits;

    return 0;
}