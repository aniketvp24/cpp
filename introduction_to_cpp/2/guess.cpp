# include <iostream>
using namespace std;

int main() {
    int secretNumber = 7, numberOfGuesses = 3, guessCount = 0;
    int guess;
    bool outOfGuesses = false;

    while (guess != secretNumber && !outOfGuesses) {
        if (guessCount < numberOfGuesses) {
            cout << "Enter guess: ";
            cin >> guess;
            guessCount++;
        } else {
            outOfGuesses = true;
        }
    }

    if (outOfGuesses) {
        cout << "You Lose!" << endl;
    } else {
        cout << "You win!" << endl;
    }

    return 0;
}