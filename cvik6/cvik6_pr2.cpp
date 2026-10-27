#include <iostream>
using namespace std;

class Station{
    private:
        int id;
        int load;
        bool enabled;
    public:
        Station(): id(0), load(0), enabled(false){}
        Station(int i, int minutes, bool active): id(i), load(minutes), enabled(active){}
        int getId() {
            return id;
        }
        int getLoad() {
            return load;
        }
        bool isEnabled() {
            return enabled;
        }
        void setLoad(int minutes) {
            load = minutes;
        }
        bool operator<(const Station &other) const
        {
            return load < other.load;
        }
};
Station &lessLoaded(Station &first, Station &second)
{
    if (second < first)
    {
        return second;
    }
    return first;
}
void selectStation
(Station stations[], int count, int limit, Station *&selected){
    selected = nullptr;

    for (int i = 0; i < count; i++) {
        if (stations[i].isEnabled() &&
            stations[i].getLoad() <= limit)
        {

            if (selected == nullptr)
            {
                selected = &stations[i];
            }
            else
            {
                selected = &lessLoaded(*selected, stations[i]);
            }
        }
    }
}
bool assignJob(Station *station, int minutes)
{
    if (station == nullptr ||
        !station->isEnabled() ||
        minutes <= 0 ||
        station->getLoad() + minutes > 480)
        return false;

    station->setLoad(station->getLoad() + minutes);
    return true;
}

int main() {
    int n, q;
    cin >> n >> q;
    Station stations[20];
    for (int i = 0; i < n; i++)
    {
        int id, loaded;
        bool enabled;
        cin >> id >> loaded >> enabled;
        stations[i] = {id,loaded, enabled};
    }
    Station *selected = nullptr;
    for (int i = 0; i < q; i ++) {
        int limit, minutes;
        cin >> limit >> minutes;
        selectStation(stations, n, limit, selected);
        bool success = assignJob(selected, minutes);
        if (selected != nullptr) {
            cout << "Selected: " << selected->getId() << " "
                 << (success ? "OK" : "Rejected") << " "
                 << selected->getLoad() << '\n';
        }
        else
        {
            cout << "Selected: none Rejected\n";
        }
    }
    if (n == 0)
    {
        cout << "Final: empty\n";
    }
    else {
        cout << "Final: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << stations[i].getId() << ": "
                 << stations[i].getLoad() << endl;
        }
    }
        return 0;
    }