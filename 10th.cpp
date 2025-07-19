#include <iostream>
using namespace std;

int main() {
    int score = 0, answer;

    cout << "📝 Simple Quiz\n";

    cout << "1. What is the capital of India?\n";
    cout << "1) Mumbai  2) Delhi  3) Kolkata  4) Chennai\n";
    cin >> answer;
    if (answer == 2) score++;

    cout << "2. 2 + 2 = ?\n";
    cout << "1) 3  2) 4  3) 5  4) 6\n";
    cin >> answer;
    if (answer == 2) score++;

    cout << "Your score: " << score << "/2\n";
    return 0;
}
