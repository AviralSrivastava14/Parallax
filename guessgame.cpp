#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int MIN = 1;
    int MAX = 100;
    int guess = 0;
    int guesses = 0;
    int answer = 0;

    srand(time(0));

    answer = (rand() % MAX) + MIN;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
        cout << "Enter a guess: ";
        cin >> guess;

        if (guess > answer) {
            cout << "Too high!\n";
        } else if (guess < answer) {
            cout << "Too low!\n";
        } else {
            cout << "CORRECT!\n";
        }
        guesses++;
    } while (guess != answer);

    cout << "**********************\n";
    cout << "Answer: " << answer << "\n";
    cout << "Guesses: " << guesses << "\n";
    cout << "**********************\n";

    return 0;
}
