#include <iostream>
using namespace std;

class Person {
    protected:
        string name;
        int id;
    public:
        string getName() {
            return name;
        }
        int getId() {
            return id;
        }
        void setName(string name) {
            this->name = name;
        }
        Person():name("unknown"),id(0) {
            cout << "+ Person default" << endl;
        }
        Person(string name, int id): name(name),id(id) {
            cout << "+ Person" << endl;
        }
        ~Person() {
            cout << "- Person" << endl;
        }
};
class Student: virtual public Person{
    protected:
        int year;
    public:
        void RenameStudent(string name) {
            setName(name);
        }
        Student(string name, int id, int year):Person(name,id),year(year) {
            cout << "+ Student" << endl;
        }
        ~Student()
        {
            cout << "- Student" << endl;
        }
};
class Employee: virtual public Person {
    protected:
        int hours;
    public:
        string employeeName() {
            return getName();
        }
        Employee(string name, int id, int hours) : Person(name, id), hours(hours)
        {
            cout << "+ Employee" << endl;
        }
        ~Employee() {
            cout << "- Employee" << endl;
        }
};
class DoctoralStudent: public Student, public Employee {
    public:
        DoctoralStudent(string n, int i, int y, int h):
        Student(n,i,y), Employee(n,i,h), Person(n,i) {
            cout << "+ DoctoralStudent" << endl;
        }
        ~DoctoralStudent() {
            cout << "- DoctoralStudent" << endl;
        }
        void info() {
            cout << "Person: " << name << " " << id << endl;
            cout << "Year: " << year << endl;
            cout << "Hours: " << hours << endl;
        }
};
int main () {
    string name, newName;
    int id, year, hours;
    cin >> name >> id >> year >> hours >> newName;

    DoctoralStudent ds(name, id, year, hours);
    ds.info();

    ds.RenameStudent(newName);
    cout << "Employee sees: " << ds.employeeName() << endl;

    return 0;
}