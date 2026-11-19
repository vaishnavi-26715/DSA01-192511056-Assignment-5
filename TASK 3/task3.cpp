
#include <iostream>
using namespace std;

class Payer {
public:
    virtual double amountCovered(double bill) = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double amountCovered(double bill) override {
        return bill;
    }
};

class Insurance : public Payer {
    double limit;
    double percentage;

public:
    void getData() {
        cout << "Enter insurance cover limit: ";
        cin >> limit;

        cout << "Enter co-payment percentage: ";
        cin >> percentage;
    }

    double amountCovered(double bill) override {
        double amount = bill * (100 - percentage) / 100;

        if (amount > limit)
            return limit;

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

    double amountCovered(double bill) override {
        return packageRate;
    }
};

int main() {
    Payer *p;
    SelfPay s;
    Insurance i;
    GovernmentScheme g;

    double bill;
    int choice;

    cout << "Enter hospital bill amount: ";
    cin >> bill;

    cout << "\n1. Self Pay";
    cout << "\n2. Insurance";
    cout << "\n3. Government Scheme";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        p = &s;
    }
    else if (choice == 2) {
        p = &i;
        i.getData();
    }
    else if (choice == 3) {
        p = &g;
        g.getData();
    }
    else {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Amount Covered: " << p->amountCovered(bill);

    return 0;
}
