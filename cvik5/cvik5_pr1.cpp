#include <iostream>
#include <iomanip>
using namespace std;

class Shipment {
    private:
        int tracking_number;
    protected:
        double weight;
    public:
        Shipment(int t, double w): tracking_number(t), weight(w) {}
        int get_tracking_number()
        {
            return tracking_number;
        }
        double get_weight() {
            return weight;
        }
};

class StandardShipment: public Shipment{
    protected:
        double price_per_kg;
    public:
        StandardShipment(int t, double w, double ppkg):
        Shipment(t, w),
        price_per_kg(ppkg)
        {}
        double calculatePrice()
        {
            return price_per_kg * weight;
        }
        void print()
        {
            cout << "Standard Shipment: " << Shipment::get_tracking_number() << " " << std::fixed << std::setprecision(2) << calculatePrice();
        }
};

class ExpressShipment: public StandardShipment {
    private:
        double express_fee;
    public:
        ExpressShipment(int t, double w, double ppkg, double ef) : StandardShipment(t, w, ppkg), express_fee(ef) {}
        double calculatePrice(){
            return StandardShipment::calculatePrice() + express_fee;
        }
        void print() {
            cout << "Express Shipment: " << StandardShipment::get_tracking_number() << " " << std::fixed << std::setprecision(2) << calculatePrice();
        }
};

int main() {
    int tracking_number;
    double weight, price_per_kg, express_fee;
    cin >> tracking_number >> weight >> price_per_kg >> express_fee;

    if (tracking_number < 0 || weight < 0.0 || price_per_kg <= 0.0 || express_fee <= 0.0)
        return 1;

    StandardShipment standard(tracking_number, weight, price_per_kg);
    ExpressShipment express(tracking_number, weight, price_per_kg, express_fee);

    standard.print();
    cout << endl;
    express.print();
    cout <<endl;
    cout << "Difference: " << std::fixed << std::setprecision(2) << express.calculatePrice() - standard.calculatePrice() << endl;

    return 0;
}