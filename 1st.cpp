#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeNote() {
    string note;
    cout << "Enter your note: ";
    cin.ignore(); // To clear input buffer
    getline(cin, note);

    ofstream file("diary.txt", ios::app); // Open file in append mode
    if (file.is_open()) {
        file << note << endl;
        file.close();
        cout << "Note saved successfully!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

void readNotes() {
    string line;
    ifstream file("diary.txt"); // Open file to read
    if (file.is_open()) {
        cout << "\n--- Your Saved Notes ---\n";
        while (getline(file, line)) {
            cout << "- " << line << endl;
        }
        file.close();
    } else {
        cout << "No notes found. Start writing your first note!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Personal Diary ---\n";
        cout << "1. Write Note\n";
        cout << "2. Read Notes\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeNote();
                break;
            case 2:
                readNotes();
                break;
            case 3:
                cout << "Exiting Personal Diary. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
