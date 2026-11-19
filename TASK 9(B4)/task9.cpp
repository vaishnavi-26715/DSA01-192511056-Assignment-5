
#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() = 0;
    virtual ~Bill() {}
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(double c, double t) {
        consultation = c;
        tests = t;
    }

    double total() override {
        return consultation + tests;
    }
};

class EmergencyBill : public Bill {
    double baseCharge, timeCharge;

public:
    EmergencyBill(double b, double t) {
        baseCharge = b;
        timeCharge = t;
    }

    double total() override {
        return baseCharge + timeCharge;
    }
};

class Payer {
public:
    virtual double amountCovered(double amount) = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double amountCovered(double amount) override {
        return amount;
    }
};

class CorporatePayer : public Payer {
public:
    double amountCovered(double amount) override {
        return amount * 0.80;
    }
};

int main() {
    double a, b;
    int billChoice, payerChoice;

    cout << "Choose Bill Type:\n";
    cout << "1. Outpatient\n";
    cout << "2. Emergency\n";
    cout << "Enter choice: ";
    cin >> billChoice;

    cout << "Enter first charge: ";
    cin >> a;

    cout << "Enter second charge: ";
    cin >> b;

    if (a < 0 || b < 0) {
        cout << "Error: Negative amount\n";
        return 0;
    }

    Bill* bill;

    if (billChoice == 1)
        bill = new OutPatient(a, b);
    else if (billChoice == 2)
        bill = new EmergencyBill(a, b);
    else {
        cout << "Invalid bill type";
        return 0;
    }

    cout << "\nChoose Payer:\n";
    cout << "1. Self Pay\n";
    cout << "2. Corporate Payer\n";
    cout << "Enter choice: ";
    cin >> payerChoice;

    Payer* payer;

    if (payerChoice == 1)
        payer = new SelfPay();
    else if (payerChoice == 2)
        payer = new CorporatePayer();
    else {
        delete bill;
        cout << "Invalid payer type";
        return 0;
    }

    cout << "\nTotal Bill: " << bill->total();
    cout << "\nAmount Covered: "
         << payer->amountCovered(bill->total());

    delete bill;
    delete payer;

    return 0;
}
