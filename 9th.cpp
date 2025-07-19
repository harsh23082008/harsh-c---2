#include <iostream>
#include <limits>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "🖩 Simple Calculator\n";
    cout << "Enter expression (e.g., 5 + 2): ";
    while (!(cin >> num1 >> op >> num2)) {
        cout << " Invalid input! Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (op) {
        case '+': cout << "Result: " << num1 + num2 << endl; break;
        case '-': cout << "Result: " << num1 - num2 << endl; break;
        case '*': cout << "Result: " << num1 * num2 << endl; break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << " Cannot divide by zero!\n";
            break;
        default: cout << " Invalid operator!\n";
    }
    return 0;
}
