
#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() {
        return 0;
    }

    virtual ~Bill() {
        cout << "Bill Destructor Called" << endl;
    }

    void show() {
        cout << "Total Bill: " << total() << endl;
    }
};

class OutPatientBill : public Bill {
    double amount;

public:
    void getData() {
        cout << "Enter OutPatient bill amount: ";
        cin >> amount;
    }

    double total() override {
        return amount;
    }

    ~OutPatientBill() {
        cout << "OutPatient Destructor Called" << endl;
    }
};

class InPatientBill : public Bill {
    double amount;

public:
    void getData() {
        cout << "Enter InPatient bill amount: ";
        cin >> amount;
    }

    double total() override {
        return amount;
    }

    ~InPatientBill() {
        cout << "InPatient Destructor Called" << endl;
    }
};

int main() {
    Bill *b;
    OutPatientBill op;
    InPatientBill ip;
    int choice;

    cout << "1. OutPatient Bill" << endl;
    cout << "2. InPatient Bill" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        b = &op;
        op.getData();
    }
    else if (choice == 2) {
        b = &ip;
        ip.getData();
    }
    else {
        cout << "Invalid choice";
        return 0;
    }

    b->show();

    return 0;
}
