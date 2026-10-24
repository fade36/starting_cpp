#include <iostream>
using namespace std;

class Printer {
    protected:
        int speed;
    public:
        Printer(int s): speed(s) {
            cout << "+ Printer" << endl;
        }
        int get_speed() {
            return speed;
        }
        ~Printer()
        {
            cout << "- Printer" << endl;
        }
};
class Scanner {
    protected:
        int speed;
    public:
        Scanner(int s): speed(s) {
            cout << "+ Scanner" << endl;
        }
        int get_speed() {
            return speed;
        }
        ~Scanner() {
            cout << "- Scanner" << endl;
        }
};
class OfficeMachine : public Printer, public Scanner {
    private:
        std::string model;
    public:
        OfficeMachine(std::string m, int printSpeed, int scanSpeed) : 
        model(m), Printer(printSpeed), Scanner(scanSpeed) {
            cout << "+ OfficeMachine" << endl;
        }
        int copyTime(int pages) {
            int t1 = (pages + Printer::get_speed() - 1) / Printer::get_speed();
            int t2 = (pages + Scanner::get_speed() - 1) / Scanner::get_speed();
            return t1 + t2;
        }
        void printInfo(){
            cout << "Model: " << model << endl;
            cout << "Printer speed: " << Printer::get_speed() << endl;
            cout << "Scanner speed: " << Scanner::get_speed() << endl;
        }
        ~OfficeMachine()
        {
            cout << "- OfficeMachine" << endl;
        }
};

int main() {
    std::string model;
    int speedP, speedS, pages;
    cin >> model >> speedP >> speedS >> pages;

    if(speedP < 0 || speedP > 100 || speedS < 0 || speedS > 100 || pages < 0 || pages > 1000) {
        return 1;
    }
    OfficeMachine om(model, speedP, speedS);
    om.printInfo();
    cout << "CopyTime: " << om.copyTime(pages) << " min" << endl;

    return 0;
}
