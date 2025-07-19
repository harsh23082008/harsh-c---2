#include <iostream>
using namespace std;

int main() {
    float temp;
    char choice;

    cout << " Temperature Converter\n";
    cout << "Convert (C)elsius to (F)ahrenheit or (F) to (C)? ";
    cin >> choice;

    if (choice == 'C' || choice == 'c') {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        cout << "In Fahrenheit: " << (temp * 9/5) + 32 << endl;
    } else if (choice == 'F' || choice == 'f') {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        cout << "In Celsius: " << (temp - 32) * 5/9 << endl;
    } else {
        cout << " Invalid choice!\n";
    }

    return 0;
}
