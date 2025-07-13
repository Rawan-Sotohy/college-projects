#pragma once 
#include <iostream>
using namespace std;

// Define a structure representing a bank account
struct Account {
    int UniqeNum;      // Unique account number
    string name;       // Account name
    double balance;    // Account balance
    string password;   // Account password
    Account* next;     // Pointer to the next account in the linked list
};

// Define a class for the banking system
class BankingSystem {
    Account* head;            // Pointer to the head of the linked list of accounts
    int nextAccountNumber;    // The next unique account number to be assigned

public:
    BankingSystem();            // Constructor to initialize the banking system
    void CreateAccount();       // Fn to create a new account
    void DeleteAccount();       // Fn to delete an existing account
    void Deposit();             // Fn to deposit an amount into an account
    void Withdraw();            // Fn to withdraw an amount from an account
    void CheckAccountBalance(); // Fn to check the balance of an account
    int CountAccounts();
    /*  // Friend declaration for the non-member count function
    friend int count(const BankingSystem& bankSystem);
};

// Non-member function to count the number of accounts
int count(const BankingSystem& bankSystem);*/
};


   
