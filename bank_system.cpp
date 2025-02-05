/**
 * @file bank_system.cpp
 * @brief A simple banking system demonstrating OOP concepts in C++.
 */

#include <iostream>
#include <vector>
#include <iomanip>

/**
 * @class BankAccount
 * @brief Represents a bank account with basic functionalities.
 */
class BankAccount {
private:
    std::string owner;   ///< Name of the account holder.
    int accountNumber;   ///< Unique account number.
    double balance;      ///< Current account balance.

public:
    /**
     * @brief Constructor to initialize a bank account.
     * @param name Account owner's name.
     * @param accNum Account number.
     * @param initialBalance Initial deposit amount.
     */
    BankAccount(std::string name, int accNum, double initialBalance)
        : owner(name), accountNumber(accNum), balance(initialBalance) {}

    /**
     * @brief Deposits an amount into the account.
     * @param amount The amount to be deposited.
     * @return void
     */
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " successfully.\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    /**
     * @brief Withdraws an amount from the account.
     * @param amount The amount to withdraw.
     * @return void
     */
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " successfully.\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!\n";
        }
    }

    /**
     * @brief Displays account details including owner, account number, and balance.
     * @return void
     */
    void displayAccount() const {
        std::cout << "Account Holder: " << owner << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }
};

/**
 * @class Bank
 * @brief Represents a simple bank system to manage multiple accounts.
 */
class Bank {
private:
    std::vector<BankAccount> accounts; ///< List of bank accounts.

public:
    /**
     * @brief Adds a new account to the bank.
     * @param account The BankAccount object to be added.
     * @return void
     */
    void addAccount(const BankAccount& account) {
        accounts.push_back(account);
        std::cout << "Account successfully created!\n";
    }

    /**
     * @brief Displays all bank accounts in the bank.
     * @return void
     */
    void displayAllAccounts() const {
        std::cout << "\n===== All Bank Accounts =====\n";
        for (const auto& account : accounts) {
            account.displayAccount();
            std::cout << "--------------------------\n";
        }
    }
};

/**
 * @brief Main function to demonstrate the banking system.
 * @return int Program exit status.
 */
int main() {
    Bank myBank;

    // Creating bank accounts
    BankAccount acc1("Alice", 1001, 500.0);
    BankAccount acc2("Bob", 1002, 1000.0);

    myBank.addAccount(acc1);
    myBank.addAccount(acc2);

    // Performing transactions
    std::cout << "\n=== Performing Transactions ===\n";
    acc1.deposit(200.0);
    acc1.withdraw(150.0);
    acc2.withdraw(500.0);
    acc2.deposit(700.0);

    // Displaying accounts
    myBank.displayAllAccounts();

    return 0;
}
