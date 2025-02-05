#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>

class BankAccount {
private:
    std::string owner;
    int accountNumber;
    double balance;

public:
    BankAccount(std::string name, int accNum, double initialBalance)
        : owner(name), accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " successfully.\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " successfully.\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!\n";
        }
    }

    void displayAccount() const {
        std::cout << "Account Holder: " << owner << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    int getAccountNumber() const { return accountNumber; }
};

class Bank {
private:
    std::vector<std::shared_ptr<BankAccount>> accounts;

public:
    void addAccount(const std::shared_ptr<BankAccount>& account) {
        accounts.push_back(account);
        std::cout << "Account successfully created!\n";
    }

    std::shared_ptr<BankAccount> findAccount(int accNum) {
        for (const auto& account : accounts) {
            if (account->getAccountNumber() == accNum) {
                return account;
            }
        }
        return nullptr;
    }

    void displayAllAccounts() const {
        std::cout << "\n===== All Bank Accounts =====\n";
        for (const auto& account : accounts) {
            account->displayAccount();
            std::cout << "--------------------------\n";
        }
    }
};

int main() {
    Bank myBank;

    myBank.addAccount(std::make_shared<BankAccount>("Alice", 1001, 500.0));
    myBank.addAccount(std::make_shared<BankAccount>("Bob", 1002, 1000.0));

    int choice, accNum;
    double amount;

    do {
        std::cout << "\nBank System Menu:\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Display All Accounts\n4. Exit\nChoose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                if (auto acc = myBank.findAccount(accNum)) {
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    acc->deposit(amount);
                } else {
                    std::cout << "Account not found!\n";
                }
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                if (auto acc = myBank.findAccount(accNum)) {
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    acc->withdraw(amount);
                } else {
                    std::cout << "Account not found!\n";
                }
                break;
            case 3:
                myBank.displayAllAccounts();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}
