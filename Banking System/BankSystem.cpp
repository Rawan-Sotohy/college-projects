#include <iostream>
#include "BankSystem.h"

using namespace std;

// Constructor for the BankingSystem class
// Initializes the head pointer to nullptr and sets the initial account number
BankingSystem::BankingSystem() : head(nullptr), nextAccountNumber(154890) {}

// Fn to create a new account
void BankingSystem::CreateAccount() {
    Account* newAccount = new Account; // Allocate memory for a new account
    newAccount->UniqeNum = nextAccountNumber++; // Assign a unique account number and increment it for the next account
    cout << "Enter your name: ";
    cin >> newAccount->name; // Get the account holder's name
    cout << "Set your Account Password: ";
    cin >> newAccount->password; // Get the account password

    // Ask if the user wants to add an initial balance
    string answer;
    cout << "Do you want to add an initial balance to your account?\nYes or No :)\n";
    cin >> answer;
    if (answer == "Yes") {
        cout << "Enter the initial balance you want to add: ";
        cin >> newAccount->balance; // Get the initial balance
    }
    else {
        newAccount->balance = 0.0; // Set balance to 0 if no initial balance is provided
    }

    newAccount->next = head; // Link the new account to the current head
    head = newAccount; // Update the head to the new account
    cout << "\n Account created & your Account Number is: " << newAccount->UniqeNum << " ^_^\n" << endl;
}

// Fn to delete an account
void BankingSystem::DeleteAccount() {
    int accountNumber;
    string password;
    cout << "Enter your Account Number to delete: ";
    cin >> accountNumber; // Get the account number to delete
    Account* current = head; // Start from the head of the list
    bool accountFound = false; // Flag to check if account is found
    Account* previous = nullptr; // Keep track of the previous account

    // Traverse the list to find the account to delete
    while (current != nullptr) {
        if (current->UniqeNum == accountNumber) {
            cout << "Enter your password: ";
            cin >> password; // Get the account password
            if (current->password == password) {
                if (previous == nullptr) {
                    head = current->next; // Update head if the account to delete is the first one
                }
                else {
                    previous->next = current->next; // Update the next pointer of the previous account
                }
                                                 }
            else {
                cout << "Incorrect password" << endl; // Print an error if password is incorrect
                return;
            }
                delete current; // Delete the account
                cout << "Account: " << accountNumber << " deleted" << endl;
                return;
        }
        previous = current; // Move to the next account
        current = current->next;
    }
    if (!accountFound) {
        cout << "\n  Account not found " << endl; // Print an error if account is not found
    }
}

// Fn to deposit an amount into an account
void BankingSystem::Deposit() {
    int accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber; // Get the account number
    Account* current = head; // Start from the head of the list
    // Traverse the list to find the account to deposit into
    while (current != nullptr) {
        if (current->UniqeNum == accountNumber) {
            cout << "Enter amount to Deposit: ";
            cin >> amount; // Get the amount to deposit
            current->balance += amount; // Add the amount to the balance
            cout << "\nDeposited " << amount << " to Account " << accountNumber << " & now you have: " << current->balance << " in your account" << endl;
            return;
        }
        current = current->next; // Move to the next account
    }
    cout << "Account not found" << endl;
}


// Function to withdraw an amount from an account
void BankingSystem::Withdraw() {
    int accountNumber;
    double amount;
    string password;
    cout << "Enter Account Number: ";
    cin >> accountNumber; // Get the account number

    Account* current = head; // Start from the head of the list
    bool accountFound = false; // Flag to check if account is found

    // Traverse the list to find the account to withdraw from
    while (current != nullptr) {
        if (current->UniqeNum == accountNumber) {
            accountFound = true; // Account found
            cout << "Enter password: ";
            cin >> password; // Get the account password
            if (current->password == password) {
                cout << "Enter amount to Withdraw: ";
                cin >> amount; // Get the amount to withdraw
                if (current->balance >= amount) {
                    current->balance -= amount; // Subtract the amount from the balance
                    cout << "\nWithdrew " << amount << " from account " << accountNumber << " & now you have: " << current->balance << " in your account" << endl;
                }
                else {
                    cout << "Insufficient funds" << endl; // Print an error if funds are insufficient
                }
            }
            else {
                cout << "Incorrect password" << endl; // Print an error if password is incorrect
            }
            return;
        }
        current = current->next; // Move to the next account
    }

    if (!accountFound) {
        cout << "\n  Account not found " << endl; // Print an error if account is not found
    }
}



// Fn to check the balance of an account
void BankingSystem::CheckAccountBalance() {
    int accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber; // Get the account number

    Account* current = head; // Start from the head of the list

    // Traverse the list to find the account
    while (current != nullptr) {
        if (current->UniqeNum == accountNumber) {
            cout << "\n   Account " << accountNumber << " balance: " << current->balance << endl; // Print the balance
            return;
        }
        current = current->next; // Move to the next account

        cout << "Account not found." << endl;
    }
}


// Function to count the number of accounts
int BankingSystem::CountAccounts() {
    int count = 0;
    Account* current = head; // Start from the head of the linked list

    while (current != nullptr) {
        count++; // Increment the count for each account
        current = current->next; // Move to the next account
    }
    return count;
}

/* Non-member function to count the number of accounts
int count(const BankingSystem& bankSystem) {
    int count = 0;
    Account* current = bankSystem.head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}*/

