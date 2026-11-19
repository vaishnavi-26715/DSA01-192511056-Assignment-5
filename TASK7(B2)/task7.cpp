
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class ClaimError : public runtime_error {
public:
    ClaimError(string msg) : runtime_error(msg) {}
};

double approve(double billed, double cover) {
    if (billed < 0 || cover < 0) {
        throw invalid_argument("Negative amount");
    }

    if (billed > cover) {
        throw ClaimError("Exceeds insurance cover");
    }

    return billed;
}

double settle(double billed, double cover) {
    try {
        return approve(billed, cover);
    }
    catch (const ClaimError &e) {
        cout << "Audit: " << e.what() << endl;
        throw;
    }
}

int main() {
    string input;
    double billed, cover;

    try {
        cout << "Enter bill amount: ";
        cin >> input;
        billed = stod(input);

        cout << "Enter insurance cover: ";
        cin >> input;
        cover = stod(input);

        double result = settle(billed, cover);

        cout << "Approved Amount: " << result << endl;
    }
    catch (const ClaimError &e) {
        cout << "Claim Rejected: " << e.what() << endl;
    }
    catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception &e) {
        cout << "Other Error: " << e.what() << endl;
    }

    return 0;
}
