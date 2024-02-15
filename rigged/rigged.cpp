/***************************************
Rigged
Author: Lawjay Lee
Date Completed: 2024-02-15
Description: Rigged game involving
random numbers that makes the player
always lose.
***************************************/

#include "RandomInt.hpp"

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the totally fair game!\n";
    cout
        << "\nIf you get all matching numbers, you win. Otherwise, you lose.\n";
    cout << "Enter the size of the set of numbers to produce (min = 2)\n";

    int setSize;
    cin >> setSize;

    Random::RandomInt randomIntGenerator(1, 7, setSize - 1);
    for (int i = 0; i < setSize - 1; i++) {
        cout << randomIntGenerator.get() << " ";
    }
    cout << randomIntGenerator.get();

    cout << "\nNot all numbers match. I can't believe you lost!\n";

    return 0;
}
