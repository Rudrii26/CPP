//2.5_25CS027
#include<iostream>
#include<cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:

    // Default Constructor
    Loan() {
        loanID = 0;
        applicantName = "None";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;
    }

    // Parameterized Constructor
    Loan(int id, string name, double amount, double rate, int months) {
        loanID = id;
        applicantName = name;

        loanAmount = (amount > 0) ? amount : 0;
        annualInterestRate = (rate > 0) ? rate : 0;
        tenureMonths = (months > 0) ? months : 0;
    }

    double calculateEMI() {
        if(loanAmount == 0 || annualInterestRate == 0 || tenureMonths == 0)
            return 0;

        double r = annualInterestRate / (12 * 100);
        double emi = (loanAmount * r * pow(1 + r, tenureMonths)) /
                     (pow(1 + r, tenureMonths) - 1);

        return emi;
    }

    void display() {
        cout << "\nLoan Details";
        cout << "\nLoan ID: " << loanID;
        cout << "\nApplicant Name: " << applicantName;
        cout << "\nLoan Amount: " << loanAmount;
        cout << "\nAnnual Interest Rate: " << annualInterestRate;
        cout << "\nTenure (Months): " << tenureMonths;
        cout << "\nMonthly EMI: " << calculateEMI();
        cout << "\n---------------------------\n";
    }
};

int main() {

    // Multiple loan objects
    Loan l1;   // Default
    Loan l2(101, "Ali", 500000, 10, 60);

    l1.display();
    l2.display();

    return 0;
}
