#include <iostream>
#include <string>
#include <limits> // For clearing input buffer
using namespace std;

class ATM {
private:
    string name;
    int pin;
    double balance;

public:
    ATM() {
        balance = 0.0;
    }

    void createAccount() {
        cout << "Enter your name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        getline(cin, name);

        cout << "Set a 4-digit PIN: ";
        while (!(cin >> pin) || pin < 1000 || pin > 9999) {
            cout << " Invalid PIN! Enter a 4-digit number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << " Account created successfully for " << name << "!\n";
    }

    bool verifyPIN() {
        int enteredPin;
        cout << "Enter your PIN: ";
        if (!(cin >> enteredPin)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Invalid input! Numbers only.\n";
            return false;
        }
        if (enteredPin == pin) {
            return true;
        } else {
            cout << " Incorrect PIN!\n";
            return false;
        }
    }

    void checkBalance() {
        if (verifyPIN()) {
            cout << "\n Current Balance: ₹" << balance << endl;
        }
    }

    void depositMoney() {
        if (verifyPIN()) {
            double amount;
            cout << "Enter amount to deposit: ₹";
            while (!(cin >> amount) || amount <= 0) {
                cout << " Invalid amount! Enter positive numbers: ₹";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            balance += amount;
            cout << " ₹" << amount << " deposited successfully!\n";
        }
    }

    void withdrawMoney() {
        if (verifyPIN()) {
            double amount;
            cout << "Enter amount to withdraw: ₹";
            while (!(cin >> amount) || amount <= 0) {
                cout << " Invalid amount! Enter positive numbers: ₹";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (amount <= balance) {
                balance -= amount;
                cout << " ₹" << amount << " withdrawn successfully!\n";
            } else {
                cout << " Insufficient balance!\n";
            }
        }
    }
};

int main() {
    ATM user;
    int choice;

    user.createAccount();

    do {
        cout << "\n=====  Mini ATM Menu =====\n";
        cout << "1 Check Balance\n";
        cout << "2 Deposit Money\n";
        cout << "3 Withdraw Money\n";
        cout << "4 Exit\n";
        cout << "Choose an option (1-4): ";

        if (!(cin >> choice)) {
            cout << " Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Skip to next loop iteration
        }

        switch (choice) {
            case 1:
                user.checkBalance();
                break;
            case 2:
                user.depositMoney();
                break;
            case 3:
                user.withdrawMoney();
                break;
            case 4:
                cout << " Thank you for using Mini ATM!\n";
                break;
            default:
                cout << " Invalid choice! Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}
