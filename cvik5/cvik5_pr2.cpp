#include <iostream>
using namespace std;


class Route{
    protected:
        int code;
        std::string name;
        int distance;
    public:
        Route(int c, std::string n, int d): code(c), name(n), distance(d) {
            cout << "+ Route" << endl;
        }
        int getCode() {
            return code;
        }
        int getDistance() {
            return distance;
        }
        virtual void info() {
            cout << "Route: " << code << " " << name << " " << distance << " km" << endl;
        }
        virtual ~Route() {
            cout << "- Route" << endl;
        }
};
class GuidedRoute: public Route {
    protected:
        std::string guide;
    public:
        GuidedRoute(int c, std::string n, int d, std::string g) : Route(c, n, d), guide(g)
        {
            cout << "+ Guide" << endl;
        }

    public:
        std::string getGuide() {
            return guide;
        }
        virtual void info() {
            Route::info();
            cout << "Guide: " << guide << endl;
        }
        virtual ~GuidedRoute() {
            cout << "- Guide" << endl;
        }
};
class MountainRoute : public GuidedRoute {
    private:
        int difficulty;
    public:
        MountainRoute(int c, std::string n, int d, std::string g, int level) :
        GuidedRoute(c,n,d,g), difficulty(level) {
            cout << "+ MountainRoute" << endl;
        }
        void info() {
            GuidedRoute::info();
            cout << "Difficulty: " << difficulty << endl;
        }
        ~MountainRoute()
        {
            cout << "- MountainRoute" << endl;
        }
};

int main() {
    int code;
    cin >> code;
    if (code < 1 || code > 999)
        return 1;
    Route *routes[3] = 
    {
        new Route(10,"River", 4),
        new GuidedRoute(20, "Forest", 7, "Eva"),
        new MountainRoute(30, "Ridge", 12, "Adam", 3)
    };
    int total_dist = 0;
    bool found = false;
    int index;
    for (int i = 0; i < 3; i++)
    {
        routes[i]->info();
        total_dist += routes[i]->getDistance();
        if (code == routes[i]->getCode()) {
            found = true;
            index = i;
        }
    }
    cout << "Total Distance: " << total_dist << endl;
    if (found) {
        cout << "Found: " << endl;
        routes[index]->info();
    }
    else {
        cout << "Not Found" << endl;
    }
    for (int i = 0; i < 3; i ++) {
        delete routes[i];
    }
}
