
#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() = 0;
    virtual void getData() = 0;
    virtual void display() = 0;

    virtual ~Bill() {}
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    void getData() {
        cout << "Enter consultation amount: ";
        cin >> consultation;

        cout << "Enter test amount: ";
        cin >> tests;
    }

    double total() {
        return consultation + tests;
    }

    void display() {
        cout << "OutPatient Bill: " << total() << endl;
    }
};

class InPatient : public Bill {
    int days;
    double perDay, medicine;

public:
    void getData() {
        cout << "Enter number of days: ";
        cin >> days;

        cout << "Enter room charge per day: ";
        cin >> perDay;

        cout << "Enter medicine charge: ";
        cin >> medicine;
    }

    double total() {
        return (days * perDay) + medicine;
    }

    void display() {
        cout << "InPatient Bill: " << total() << endl;
    }
};

int main() {
    Bill *b;
    OutPatient op;
    InPatient ip;

    int choice;

    cout << "1. OutPatient Bill" << endl;
    cout << "2. InPatient Bill" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        b = &op;
    }
    else if (choice == 2) {
        b = &ip;
    }
    else {
        cout << "Invalid choice";
        return 0;
    }

    b->getData();
    b->display();

    cout << "Total Amount: " << b->total() << endl;

    return 0;
}
