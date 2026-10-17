#include <iostream>
using namespace std;

class ClockTime
{
private:
    int totalMinutes;

public:
    ClockTime()
    {
        totalMinutes = 0;
    }
    ClockTime(int hours, int minutes)
    {
        totalMinutes = 60 * hours + minutes;
    }
    bool operator<(const ClockTime &other)
    {
        if (totalMinutes < other.totalMinutes)
        {
            return true;
        }
        return false;
    }
    bool operator==(const ClockTime &other)
    {
        if (totalMinutes == other.totalMinutes)
        {
            return true;
        }
        return false;
    }
    ClockTime &operator++()
    {
        totalMinutes = (totalMinutes + 1) % 1440;
        return *this;
    }
    ClockTime operator++(int)
    {
        ClockTime old = *this;
        totalMinutes = (totalMinutes + 1) % 1440;
        return old;
    }
    friend ostream &operator<<(ostream &output, const ClockTime &time)
    {
        output << ((time.totalMinutes / 60 < 10) ? "0" : "")
               << time.totalMinutes / 60 << ":"
               << ((time.totalMinutes % 60 < 10) ? "0" : "")
               << time.totalMinutes % 60;
        return output;
    }
    friend std::istream &operator>>(std::istream &input, ClockTime &time)
    {
        int hours, minutes;
        input >> hours >> minutes;
        time.totalMinutes = hours * 60 + minutes;
        return input;
    }
};

int main()
{
    ClockTime start;
    ClockTime reference;
    cin >> start >> reference;
    cout << "Start: " << start << endl;
    cout << "Relation: " << ((start.operator==(reference)) ? "same" : (start.operator<(reference)) ? "earlier"
                                                                                                   : "later")
         << endl;
    ClockTime before = start++;
    ClockTime after = ++start;
    cout << "Postfix returned: " << before << endl;
    cout << "Prefix returned: " << after << endl;
    cout << "Final: " << start << endl;

    return 0;
}
