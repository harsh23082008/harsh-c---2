#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "🔢 Enter a number: ";
    cin >> num;
    if (num % 2 == 0)
        cout << "✅ " << num << " is Even.\n";
    else
        cout << "✅ " << num << " is Odd.\n";
    return 0;
}
