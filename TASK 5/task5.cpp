
#include <iostream>
#include <stdexcept>
using namespace std;

void validateBill(double amount) {
    if (amount < 0) {
        throw invalid_argument("Invalid bill amount");
    }

    cout << "Bill is valid" << endl;
}

void processBill(double amount) {
    try {
        validateBill(amount);
    }
    catch (const exception &e) {
        cout << "Logging Error: " << e.what() << endl;
        throw;
    }
}

int main() {
    double amount;

    cout << "Enter hospital bill amount: ";
    cin >> amount;

    try {
        processBill(amount);
        cout << "Bill processed successfully" << endl;
    }
    catch (const exception &e) {
        cout << "Final Error: " << e.what() << endl;
    }

    return 0;
}
