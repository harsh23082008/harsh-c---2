#include <iostream>
#include <ctime>   // For clock() and CLOCKS_PER_SEC
#include <conio.h> // For _getch() in Turbo C++
using namespace std;

void simpleStopwatch() {
    cout << "\n Simple Stopwatch\n";
    cout << "Press any key to START...\n";
    _getch(); // Wait for key press to start

    clock_t start = clock();
    cout << "Stopwatch started! Press any key to STOP...\n";
    _getch(); // Wait for key press to stop
    clock_t end = clock();

    double seconds = double(end - start) / CLOCKS_PER_SEC;
    cout << " Elapsed Time: " << seconds << " seconds\n";
    cout << "Press any key to return to menu...\n";
    _getch();
}
