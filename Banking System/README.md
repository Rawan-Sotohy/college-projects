### 🏦 Banking System – C++ Project

A simple command-line Banking System implemented in C++ as a practical application of Data Structures (specifically Linked List).
 This system allows users to:
* Create an account
* Delete an account
* Deposit money
* Withdraw money
* Check account balance
* Count total number of accounts

---

### 📁 Project Structure

```
/Banking-System
│
├── BankSystem.h         # Header file defining the Account structure and BankingSystem class
├── BankSystem.cpp       # Implementation of banking operations (create, delete, deposit, etc.)
├── main.cpp             # Main function with menu-driven interface
└── README.md            # Project description and usage
```

---

### ⚙️ Features

✅ Create and manage accounts with unique account numbers

🔒 Password protection for deleting and withdrawing

💰 Deposit and withdraw money

📊 View balance and number of active accounts

📚 Demonstrates core Linked List operations: insert, delete, traverse


---

### 🧑‍💻 How to Compile and Run

You can use `g++` to compile the program from the terminal:

```bash
g++ main.cpp BankSystem.cpp -o BankingSystem
./BankingSystem
```

Make sure you have all the files (`main.cpp`, `BankSystem.cpp`, `BankSystem.h`) in the same directory.

---

### 📷 Example Interaction

```
==>   Welcome to our Banking System ^_^  <==

Choose Your Service:
1. Create account
2. Delete account
3. Deposit
4. Withdraw
5. Check account balance
6. Total number of accounts
0. Exit
```
