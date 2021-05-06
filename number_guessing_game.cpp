// Copyright (c) 2021 Caylee Annett All rights reserved
//
// Created by Caylee Annett
// Created on May 2021
// This program is a game where the user tries to guess a randomly
//    generated number and will not crash

#include <iostream>
#include <random>
#include <string>

int main() {
    // This function tells the user if their guess is correct
    std::string integerAsString;
    int integerAsNumber;
    int correctNumber;

    // Input
    std::cout << "Guess what the integer between 0 and 10 is: ";
    std::cin >> integerAsString;
    std::cout << "" << std::endl;

    // Process & Output
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 10);  // [0, 10]
    correctNumber = idist(rgen);

    try {
        integerAsNumber = std::stoi(integerAsString);

        if (integerAsNumber == correctNumber) {
                std::cout << "You guessed it!" << std::endl;
        } else {
            std::cout << "Incorrect! The number was " << correctNumber
                << "." << std::endl;
        }
    } catch (std::invalid_argument) {
            std::cout << integerAsString << " is not an integer." <<std::endl;
    }
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
