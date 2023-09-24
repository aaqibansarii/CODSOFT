#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100. Try to guess it." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if the input is valid (a number)
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;

            // Clear the error state of cin
            cin.clear();

            // Ignore any remaining characters in the input buffer until a newline character
            while (cin.get() != '\n');
            
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
