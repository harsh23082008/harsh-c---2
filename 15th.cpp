#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, rev;
    cout << "🔄 Enter a word: ";
    cin >> str;

    rev = string(str.rbegin(), str.rend());
    if (str == rev)
        cout << "✅ It's a palindrome!\n";
    else
        cout << "❌ Not a palindrome.\n";

    return 0;
}
