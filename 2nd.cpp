#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

void writeNote() {
    string note;
    cout << "Enter your note: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    getline(cin, note);

    ofstream file("diary.txt", ios::app);
    if (file.is_open()) {
        file << note << endl;
        file.close();
        cout << " Note saved successfully!\n";
    } else {
        cout << " Error opening file!\n";
    }
}

void readNotes() {
    string line;
    ifstream file("diary.txt");
    if (file.is_open()) {
        cout << "\n --- Your Saved Notes ---\n";
        bool empty = true;
        while (getline(file, line)) {
            cout << "• " << line << endl;
            empty = false;
        }
        if (empty) cout << "No notes found.\n";
        file.close();
    } else {
        cout << " No notes file found. Start by writing a note!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n --- Personal Diary Menu --- ✨\n";
        cout << "1 Write Note\n";
        cout << "2 Read Notes\n";
        cout << "3 Exit\n";
        cout << "Choose an option (1-3): ";
        if (!(cin >> choice)) {
            cout << " Invalid input! Enter numbers only.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard wrong input
            continue; // Skip to next iteration
        }

        switch (choice) {
            case 1:
                writeNote();
                break;
            case 2:
                readNotes();
                break;
            case 3:
                cout << " Exiting Personal Diary. Goodbye!\n";
                break;
            default:
                cout << " Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
