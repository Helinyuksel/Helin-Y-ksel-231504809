#include <iostream>
#include <cmath>
using namespace std;

class MortgagePayment {
private:
    double loanAmount;
    double annualInterestRate;
    int numberOfYears;

public:
    void setLoanAmount(double amount) {
        if (amount >= 0)
            loanAmount = amount;
        else
            cout << "Error: Loan amount cannot be negative." << endl;
    }

    void setAnnualInterestRate(double rate) {
        if (rate >= 0)
            annualInterestRate = rate;
        else
            cout << "Error: Annual interest rate cannot be negative." << endl;
    }

    void setNumberOfYears(int years) {
        if (years >= 0)
            numberOfYears = years;
        else
            cout << "Error: Number of years cannot be negative." << endl;
    }

    double calculateMonthlyPayment() const {
        double monthlyInterestRate = annualInterestRate / 12 / 100;
        int numberOfPayments = numberOfYears * 12;
        double monthlyPayment = loanAmount * monthlyInterestRate /
                                (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
        return monthlyPayment;
    }

    double calculateTotalAmountPaid() const {
        double monthlyPayment = calculateMonthlyPayment();
        int numberOfPayments = numberOfYears * 12;
        double totalAmountPaid = monthlyPayment * numberOfPayments;
        return totalAmountPaid;
    }
};

int main() {
    MortgagePayment mortgage;

    double loanAmount, annualInterestRate;
    int numberOfYears;

    cout << "Enter the loan amount: $";
    cin >> loanAmount;
    mortgage.setLoanAmount(loanAmount);

    cout << "Enter the annual interest rate (%): ";
    cin >> annualInterestRate;
    mortgage.setAnnualInterestRate(annualInterestRate);

    cout << "Enter the number of years: ";
    cin >> numberOfYears;
    mortgage.setNumberOfYears(numberOfYears);

    cout << "Monthly Payment: $" << mortgage.calculateMonthlyPayment() << endl;
    cout << "Total Amount Paid: $" << mortgage.calculateTotalAmountPaid() << endl;

    return 0;
}
