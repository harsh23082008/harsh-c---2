#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime> // Added for srand, rand
using namespace std;

// ===============================
// Utility Functions
// ===============================
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ===============================
// Student Management System
// ===============================
void addStudent() {
    ofstream file("students.txt", ios::app);
    string name, roll;
    cout << "\n--- Add Student ---\n";
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Roll No: ";
    getline(cin, roll);
    file << roll << " | " << name << endl;
    file.close();
    cout << "✅ Student Added Successfully!\n";
    waitForEnter();
}

void viewStudents() {
    ifstream file("students.txt");
    string line;
    cout << "\n--- Student List ---\n";
    if (!file) {
        cout << "📂 No student records found.\n";
    } else {
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
    file.close();
    waitForEnter();
}

// ===============================
// Personal Diary
// ===============================
void writeDiary() {
    ofstream file("diary.txt", ios::app);
    string note;
    cout << "\n--- Write Diary ---\n";
    cin.ignore();
    cout << "Enter Note: ";
    getline(cin, note);
    file << note << endl;
    file.close();
    cout << "✅ Note Saved!\n";
    waitForEnter();
}

void readDiary() {
    ifstream file("diary.txt");
    string line;
    cout << "\n--- Diary Notes ---\n";
    if (!file) {
        cout << "📂 No notes found.\n";
    } else {
        while (getline(file, line)) {
            cout << "- " << line << endl;
        }
    }
    file.close();
    waitForEnter();
}

// ===============================
// Mini ATM
// ===============================
double balance = 0.0;

void checkBalance() {
    cout << "\n💰 Current Balance: ₹" << balance << endl;
    waitForEnter();
}

void depositMoney() {
    double amount;
    cout << "\n--- Deposit Money ---\n";
    cout << "Enter amount: ₹";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "✅ ₹" << amount << " Deposited!\n";
    } else {
        cout << "❌ Invalid Amount!\n";
    }
    waitForEnter();
}

void withdrawMoney() {
    double amount;
    cout << "\n--- Withdraw Money ---\n";
    cout << "Enter amount: ₹";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "✅ ₹" << amount << " Withdrawn!\n";
    } else {
        cout << "❌ Invalid Amount or Insufficient Balance!\n";
    }
    waitForEnter();
}

// ===============================
// Games: Guess the Number
// ===============================
void guessNumberGame() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess, tries = 0;

    cout << "\n🎯 Guess the Number (1-100)\n";
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;
        if (guess > number) cout << "📉 Too High!\n";
        else if (guess < number) cout << "📈 Too Low!\n";
        else cout << "🎉 Correct! You guessed it in " << tries << " tries.\n";
    } while (guess != number);
    waitForEnter();
}

// ===============================
// Main Menu
// ===============================
void mainMenu() {
    int choice;
    do {
        cout << "\n==============================\n";
        cout << "✨ SMART MANAGEMENT SYSTEM ✨\n";
        cout << "==============================\n";
        cout << "1️⃣ Student Management\n";
        cout << "2️⃣ Personal Diary\n";
        cout << "3️⃣ Mini ATM\n";
        cout << "4️⃣ Play Game (Guess Number)\n";
        cout << "5️⃣ Exit\n";
        cout << "Choose an option (1-5): ";

        if (!(cin >> choice)) {
            cout << "❌ Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int subChoice;
                do {
                    cout << "\n--- Student Management ---\n";
                    cout << "1. Add Student\n";
                    cout << "2. View Students\n";
                    cout << "3. Back to Main Menu\n";
                    cout << "Choose (1-3): ";
                    cin >> subChoice;
                    if (subChoice == 1) addStudent();
                    else if (subChoice == 2) viewStudents();
                    else if (subChoice != 3) cout << "❌ Invalid Option!\n";
                } while (subChoice != 3);
                break;
            }
            case 2: {
                int subChoice;
                do {
                    cout << "\n--- Personal Diary ---\n";
                    cout << "1. Write Note\n";
                    cout << "2. Read Notes\n";
                    cout << "3. Back to Main Menu\n";
                    cout << "Choose (1-3): ";
                    cin >> subChoice;
                    if (subChoice == 1) writeDiary();
                    else if (subChoice == 2) readDiary();
                    else if (subChoice != 3) cout << "❌ Invalid Option!\n";
                } while (subChoice != 3);
                break;
            }
            case 3: {
                int subChoice;
                do {
                    cout << "\n--- Mini ATM ---\n";
                    cout << "1. Check Balance\n";
                    cout << "2. Deposit Money\n";
                    cout << "3. Withdraw Money\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Choose (1-4): ";
                    cin >> subChoice;
                    if (subChoice == 1) checkBalance();
                    else if (subChoice == 2) depositMoney();
                    else if (subChoice == 3) withdrawMoney();
                    else if (subChoice != 4) cout << "❌ Invalid Option!\n";
                } while (subChoice != 4);
                break;
            }
            case 4: guessNumberGame(); break;
            case 5: cout << "👋 Exiting Smart Management System...\n"; break;
            default: cout << "⚠️ Invalid Option! Try Again.\n";
        }
    } while (choice != 5);
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {
    mainMenu();
    return 0;
}
