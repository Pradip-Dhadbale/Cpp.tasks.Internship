/*Create a program that generates a random number and asks the user to guess it.
  Provide feedback on whether the guess is too high or too low until the user guesses the correct number./

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 int main() 
 {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    cout << "Welcome to the Number Guessing Game." << endl;
    cout << "I have picked a number between 1 to 100. Can you "
                  "guess it ?" << endl;
    do {
         cout << "Enter your guess: ";
        cin >> guess;
        if (guess < randomNumber) {
            cout << "Too low.. Try again.." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high.. Try again.." << endl;
        }
        attempts++;
    } while (guess != randomNumber);
    cout << "Congratulations! You guessed the number " <<           
    randomNumber << " in " << attempts << " attempts." << endl;
    return 0;
 }