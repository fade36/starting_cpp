#include <iostream>
using namespace std;

class Racetime
{
private:
    int totalSeconds;

public:
    Racetime(int minutes, int seconds)
    {
        totalSeconds = minutes * 60 + seconds;
    }
    int getSeconds()
    {
        return totalSeconds;
    }
    void addSeconds(int seconds)
    {
        totalSeconds += seconds;
    }
    void print()
    {
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        cout << minutes << ":" << seconds << endl;
    }
};
Racetime penalized(Racetime time, int seconds)
{
    time.addSeconds(seconds);
    return time;
}
Racetime combined(Racetime first, Racetime second)
{
    Racetime newObj(0, first.getSeconds() + second.getSeconds());
    return newObj;
}

int main()
{
    int first_minutes, first_seconds, second_minutes, second_seconds, penalty_seconds;
    cin >> first_minutes >> first_seconds >> second_minutes >> second_seconds >> penalty_seconds;

    if (
        first_minutes < 0 || first_minutes > 1000 || first_seconds < 0 || first_seconds > 1000 ||
        second_minutes < 0 || second_minutes > 1000 || second_seconds < 0 || second_seconds > 1000 ||
        penalty_seconds < 0 || penalty_seconds > 1000)
    {
        cout << "Invalid time" << endl;
        return 1;
    }
    Racetime first(first_minutes, first_seconds);
    Racetime second(second_minutes, second_seconds);
    Racetime penalized_first = penalized(first, penalty_seconds);
    Racetime combinedTime = combined(penalized_first, second);

    cout << "First: ";
    first.print();
    cout << "Second: ";
    second.print();
    cout << "Corrected: ";
    penalized_first.print();
    cout << "Combined: ";
    combinedTime.print();

    cout << "Winner: "
         << ((penalized_first.getSeconds() < second.getSeconds()) ? "first" : (penalized_first.getSeconds() > second.getSeconds()) ? "second"
                                                                                                                                   : "tie");
    cout << endl;

    return 0;
}