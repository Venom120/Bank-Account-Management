#include <iostream>
#include <string>
using namespace std;
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNumber, double initialBalance, double interest)
        : BankAccount(accNumber, initialBalance), interestRate(interest) {}

    void applyInterest() {
        balance += balance * (interestRate / 100.0);
        cout << "Interest applied. New balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& accNumber, double initialBalance, double overdraft)
        : BankAccount(accNumber, initialBalance), overdraftLimit(overdraft) {}

    void withdraw(double amount) {
        if (amount > 0 && (balance + overdraftLimit) >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid withdrawal amount or overdraft limit exceeded. " << endl;
        }
    }
};

int main() {
    system("cls");
    SavingsAccount savings("SAV12345", 1000.0, 5.0);
    CheckingAccount checking("CHK67890", 500.0, 100.0);

    savings.display();
    savings.deposit(200.0);
    savings.applyInterest();
    savings.display();
    cout<<endl;

    checking.display();
    checking.withdraw(700.0);
    checking.display();

    return 0;
}
