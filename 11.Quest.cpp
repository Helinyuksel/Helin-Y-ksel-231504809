#include <iostream>
using namespace std;

class Payroll {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Payroll(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}

    double calculateGrossPay() const {
        if (hoursWorked <= 60) {
            return hourlyRate * hoursWorked;
        } else {
            cerr << "Error: Hours worked cannot exceed 60." << endl;
            return 0.0;
        }
    }
};

int main() {
    const int numemp = 7;
    double rate;
    int hours;

    Payroll employees[numemp] = {
        Payroll(15.0, 0),
        Payroll(20.0, 0),
        Payroll(18.5, 0),
        Payroll(22.0, 0),
        Payroll(17.0, 0),
        Payroll(25.0, 0),
        Payroll(21.5, 0)
    };

    for (int i = 0; i < numemp; ++i) {
        cout << "Enter the hours worked for employee " << i + 1 << ": ";
        cin >> hours;

        employees[i] = Payroll(employees[i].calculateGrossPay(), hours);
    }

    cout << "Gross pay for each employee:" << endl;
    for (int i = 0; i < numemp; ++i) {
        cout << "Employee " << i + 1 << ": $" << employees[i].calculateGrossPay() << endl;
    }

    return 0;
}

