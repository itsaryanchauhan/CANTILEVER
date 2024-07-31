#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

void playGame(int lowerBound, int upperBound) {
    std::srand(std::time(0));
    int randomNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound;
    int userGuess = 0;
    int attempts = 0;
    bool guessedCorrectly = false;

    std::cout << "Guess the number between " << lowerBound << " and " << upperBound << ":\n";

    while (!guessedCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            std::cout << "Too low! ";
            if (randomNumber - userGuess <= 10) {
                std::cout << "But very close!\n";
            } else {
                std::cout << "Try again.\n";
            }
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! ";
            if (userGuess - randomNumber <= 10) {
                std::cout << "But very close!\n";
            } else {
                std::cout << "Try again.\n";
            }
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            guessedCorrectly = true;
        }

        // Add a small delay to enhance user experience
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void displayWelcomeScreen() {
    std::cout << "****************************\n";
    std::cout << "*  Welcome to the Number   *\n";
    std::cout << "*     Guessing Game!       *\n";
    std::cout << "****************************\n";
}

void displayGoodbyeScreen() {
    std::cout << "****************************\n";
    std::cout << "*  Thank you for playing!  *\n";
    std::cout << "*        Goodbye!          *\n";
    std::cout << "****************************\n";
}

int main() {
    int lowerBound, upperBound;
    char playAgain = 'y';

    displayWelcomeScreen();
    
    while (playAgain == 'y' || playAgain == 'Y') {
        std::cout << "Enter the lower bound of the range: ";
        std::cin >> lowerBound;
        std::cout << "Enter the upper bound of the range: ";
        std::cin >> upperBound;

        if (lowerBound >= upperBound) {
            std::cout << "Invalid range. The lower bound must be less than the upper bound.\n";
            continue;
        }

        playGame(lowerBound, upperBound);

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    displayGoodbyeScreen();
    return 0;
}
