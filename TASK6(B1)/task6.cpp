
#include <iostream>
#include <string>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual string type() const = 0;

    virtual void print() const {
        cout << type() << " Bill Amount: " << total() << endl;
    }

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

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

class InPatient : public Bill {
    int days;
    double room, medicine;

public:
    void getData() {
        cout << "Enter number of days: ";
        cin >> days;
        cout << "Enter room charge per day: ";
        cin >> room;
        cout << "Enter medicine charge: ";
        cin >> medicine;
    }

    double total() const override {
        return days * room + medicine;
    }

    string type() const override {
        return "InPatient";
    }
};

class DayCare : public Bill {
    double package;

public:
    void getData() {
        cout << "Enter package price: ";
        cin >> package;
    }

    double total() const override {
        return package;
    }

    string type() const override {
        return "DayCare";
    }
};

class Emergency : public Bill {
    double base, rate;
    int hours;

public:
    void getData() {
        cout << "Enter base charge: ";
        cin >> base;
        cout << "Enter number of hours: ";
        cin >> hours;
        cout << "Enter charge per hour: ";
        cin >> rate;
    }

    double total() const override {
        return base + hours * rate;
    }

    string type() const override {
        return "Emergency";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill &b) = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill &b) override {
        return b.total();
    }
};

class Insurance : public Payer {
    double limit, copay;

public:
    void getData() {
        cout << "Enter insurance cover limit: ";
        cin >> limit;
        cout << "Enter co-payment percentage: ";
        cin >> copay;
    }

    double amountCovered(const Bill &b) override {
        double amount = b.total() * (100 - copay) / 100;
        if (amount > limit)
            amount = limit;
        return amount;
    }
};

class GovernmentScheme : public Payer {
    double packageRate;

public:
    void getData() {
        cout << "Enter government package rate: ";
        cin >> packageRate;
    }

    double amountCovered(const Bill &b) override {
        return packageRate;
    }
};

int main() {
    OutPatient op;
    InPatient ip;
    DayCare dc;
    Emergency em;

    Bill *b;
    Payer *p;

    SelfPay s;
    Insurance i;
    GovernmentScheme g;

    int choice, payerChoice;

    cout << "HOSPITAL BILLING SYSTEM\n";

    cout << "\n1. OutPatient";
    cout << "\n2. InPatient";
    cout << "\n3. DayCare";
    cout << "\n4. Emergency";

    cout << "\nEnter bill type: ";
    cin >> choice;

    if (choice == 1) {
        b = &op;
        op.getData();
    }
    else if (choice == 2) {
        b = &ip;
        ip.getData();
    }
    else if (choice == 3) {
        b = &dc;
        dc.getData();
    }
    else if (choice == 4) {
        b = &em;
        em.getData();
    }
    else {
        cout << "Invalid bill type";
        return 0;
    }

    cout << "\n1. Self Pay";
    cout << "\n2. Insurance";
    cout << "\n3. Government Scheme";

    cout << "\nEnter payer type: ";
    cin >> payerChoice;

    if (payerChoice == 1) {
        p = &s;
    }
    else if (payerChoice == 2) {
        p = &i;
        i.getData();
    }
    else if (payerChoice == 3) {
        p = &g;
        g.getData();
    }
    else {
        cout << "Invalid payer type";
        return 0;
    }

    cout << "\n----- BILL DETAILS -----\n";
    b->print();

    cout << "Amount Covered: "
         << p->amountCovered(*b) << endl;

    return 0;
}
