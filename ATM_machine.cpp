#include <iostream>
using namespace std;

int main() {
    int pin = 4321;          // Use a single PIN variable
    int enteredPIN;
    int choice;
    double balance = 50000.0;
    double amount;
    int newPIN, confirmPIN;

    cout << "****** Welcome to ATM Machine ******" << endl;

    // PIN Verification
    cout << "Enter your 4-digit PIN: ";
    cin >> enteredPIN;

    if (enteredPIN != pin) {
        cout << "Incorrect PIN. Access Denied!" << endl;
        return 0;
    }

    do {
        cout << "\n===== ATM Menu =====" << endl;
        cout << "1. Cash withdrawal" << endl;
        cout << "2. Balance Inquiry" << endl;
        cout << "3. Deposit Cash" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;       // Added number for Exit
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount <= balance && amount > 0) {
                    balance -= amount;
                    cout << "Please collect your cash." << endl;
                    cout << "Remaining Balance: " << balance << endl;
                } else {
                    cout << "Insufficient balance or invalid amount!" << endl;
                }
                break;

            case 2:
                cout << "Your Current Balance is: " << balance << endl;
                break;

            case 3:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Amount deposited successfully." << endl;
                    cout << "Updated Balance: " << balance << endl;
                } else {
                    cout << "Invalid deposit amount!" << endl;
                }
                break;

            case 4:
                cout << "Enter your current PIN: ";
                cin >> enteredPIN;

                if (enteredPIN == pin) {
                    cout << "Enter new PIN: ";
                    cin >> newPIN;
                    cout << "Confirm new PIN: ";
                    cin >> confirmPIN;

                    if (newPIN == confirmPIN) {
                        pin = newPIN;   // Update the PIN
                        cout << "PIN changed successfully!" << endl;
                    } else {
                        cout << "PINs do not match. Try again." << endl;
                    }
                } else {
                    cout << "Incorrect current PIN. Access denied." << endl;
                }
                break;

            case 5:
                cout << "Thank you for using ATM. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);   // Loop until Exit

    return 0;
}
