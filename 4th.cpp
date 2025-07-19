#include <iostream>
using namespace std;

class Student {
    string name;
    int rollNo;
    float marks[5];
    float total, percentage;
    char grade;

public:
    void input() {
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
        total = 0;
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << i+1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
        percentage = total / 5;
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'D';
    }

    void display() {
        cout << "\n--- Report Card ---\n";
        cout << "Name: " << name << "\nRoll No: " << rollNo << endl;
        cout << "Total Marks: " << total << "\nPercentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.display();
    return 0;
}
