
#include <iostream>
#include <vector>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() {}
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(double c, double t) {
        consultation = c;
        tests = t;
    }

    double total() const override {
        return consultation + tests;
    }
};

class InPatient : public Bill {
    int days;
    double rate, surgery;

public:
    InPatient(int d, double r, double s) {
        days = d;
        rate = r;
        surgery = s;
    }

    double total() const override {
        return days * rate + surgery;
    }
};

struct BillData {
    int type;
    int days;
    double a, b, c;
};

double switchTotal(BillData x) {
    switch (x.type) {
        case 1:
            return x.a + x.b;

        case 2:
            return x.days * x.a + x.b;

        default:
            return 0;
    }
}

int main() {
    int n, choice;

    vector<Bill*> bills;
    vector<BillData> data;

    double virtualSum = 0;
    double switchSum = 0;

    cout << "Enter number of bills: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        BillData x;

        cout << "\n1. OutPatient";
        cout << "\n2. InPatient";
        cout << "\nEnter bill type: ";
        cin >> choice;

        x.type = choice;

        if (choice == 1) {
            cout << "Enter consultation amount: ";
            cin >> x.a;

            cout << "Enter test amount: ";
            cin >> x.b;

            bills.push_back(new OutPatient(x.a, x.b));
        }
        else if (choice == 2) {
            cout << "Enter number of days: ";
            cin >> x.days;

            cout << "Enter room charge per day: ";
            cin >> x.a;

            cout << "Enter surgery charge: ";
            cin >> x.b;

            bills.push_back(
                new InPatient(x.days, x.a, x.b)
            );
        }
        else {
            cout << "Invalid choice";
            for (Bill* b : bills)
                delete b;
            return 0;
        }

        data.push_back(x);
    }

    cout << "\n--- VIRTUAL FUNCTION METHOD ---\n";

    for (Bill* b : bills) {
        cout << "Bill Amount: " << b->total() << endl;
        virtualSum += b->total();
    }

    cout << "Virtual Total: " << virtualSum << endl;

    cout << "\n--- SWITCH METHOD ---\n";

    for (BillData x : data) {
        double amount = switchTotal(x);
        cout << "Bill Amount: " << amount << endl;
        switchSum += amount;
    }

    cout << "Switch Total: " << switchSum << endl;

    if (virtualSum == switchSum)
        cout << "\nBoth methods give same result.";
    else
        cout << "\nResults are different.";

    for (Bill* b : bills)
        delete b;

    return 0;
}
