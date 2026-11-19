
#include <iostream>
#include <stdexcept>
using namespace std;

class BillingError : public runtime_error {
public:
    BillingError(string msg) : runtime_error(msg) {}
};

int main() {
    double amount, limit;

    try {
        cout << "Enter hospital bill amount: ";
        cin >> amount;

        cout << "Enter insurance cover limit: ";
        cin >> limit;

        if (amount < 0 || limit < 0) {
            throw invalid_argument("Negative amount is not allowed");
        }

        if (amount > limit) {
            throw BillingError("Bill exceeds insurance limit");
        }

        cout << "Bill Amount: " << amount << endl;
        cout << "Bill Approved Successfully!" << endl;
    }

    catch (const BillingError &e) {
        cout << "Billing Error: " << e.what() << endl;
    }

    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
