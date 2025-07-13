#include <iostream>
#include "BankSystem.h"

using namespace std;

int main() {
    // Welcome message to the user
    cout << "\n   ==>   Welcome to our Banking System ^_^  <==   \n";

    // Create an instance of the BankingSystem class
    BankingSystem obj;

    int choice; // Variable to store user choice
    int accountCount;

    // Loop to display the menu and perform selected actions
    do {
        cout << "\n   Choose Your Service: (^_^) \n";
        cout << "   .-._.-._.-._.-._.-._.-._.-.\n\n";
        cout << "   1. Create account\n"; // Option to create an account
        cout << "   2. Delete account\n"; // Option to delete an account
        cout << "   3. Deposit\n"; // Option to deposit money
        cout << "   4. Withdraw\n"; // Option to withdraw money
        cout << "   5. Check account balance\n"; // Option to check account balance
        cout << "   6. Total number of accounts:\n"; 
        cout << "   0. Exit\n"; // Option to exit the program
        cout << ".-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.\n";

        cin >> choice; // Read user's choice

        // Check if the input is valid
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            choice = -1; // Set choice to an invalid value to trigger the default case
        }

        // Perform the action based on user's choice
        switch (choice) {
        case 1:
            obj.CreateAccount(); // Call CreateAccount method
            break;
        case 2:
            obj.DeleteAccount(); // Call DeleteAccount method
            break;
        case 3:
            obj.Deposit(); // Call Deposit method
            break;
        case 4:
            obj.Withdraw(); // Call Withdraw method
            break;
        case 5:
            obj.CheckAccountBalance(); // Call CheckAccountBalance method
            break;
        case 6:
             accountCount = obj.CountAccounts();
            cout << "Total number of accounts: " << accountCount << endl;// Call CheckAccountBalance method
            break;

            /*case 6:
            cout << "Total Number of accounts: " << count(obj) << endl; // Count the number of accounts
            break;*/


        case 0:
            cout << "   Exiting......   :( " << endl; // Exit message
            break;
        default:
            cout << "   Invalid choice !!!   :( \n Please Enter a number from the following list  :)\n"; // Invalid choice message
        }
    } while (choice != 0); // Continue until user chooses to exit

    return 0; 
}


