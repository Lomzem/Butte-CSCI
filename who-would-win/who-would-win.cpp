/***************************************
Who Would Win
Author: Lawjay Lee
Date Completed: 2024-02-08
Description: Asks user to select two
animals and displays winning animal
***************************************/

#include <array>
#include <iostream>
using namespace std;

struct Animal {
    string Type;
    int Strength;
    int Toughness;
    int Luck;
};

Animal determineWinner(array<Animal, 5> &animals, int choice1, int choice2) {
    Animal animal1 = animals.at(choice1);
    Animal animal2 = animals.at(choice2);

    int score1 = animal1.Strength + animal1.Toughness;
    int score2 = animal2.Strength + animal2.Toughness;

    if (score1 < score2) {
        score1 += animal1.Luck;
    } else if (score1 > score2) {
        score2 += animal2.Luck;
    } else {
        score1 += animal1.Luck;
        score2 += animal2.Luck;
    }

    // TODO! Handle what happens if they have the same score
    if (score1 > score2) {
        return animal1;
    } else {
        return animal2;
    }
}

int main() {
    Animal bear;
    bear.Type = "Bear";
    bear.Strength = 8;
    bear.Toughness = 6;
    bear.Luck = 2;

    Animal shark;
    shark.Type = "Shark";
    shark.Strength = 5;
    shark.Toughness = 5;
    shark.Luck = 3;

    Animal gorilla;
    gorilla.Type = "Gorilla";
    gorilla.Strength = 7;
    gorilla.Toughness = 5;
    gorilla.Luck = 3;

    Animal lion;
    lion.Type = "Lion";
    lion.Strength = 5;
    lion.Toughness = 6;
    lion.Luck = 4;

    Animal crocodile;
    crocodile.Type = "Crocodile";
    crocodile.Strength = 3;
    crocodile.Toughness = 9;
    crocodile.Luck = 4;

    array<Animal, 5> animals;
    animals.at(0) = bear;
    animals.at(1) = shark;
    animals.at(2) = gorilla;
    animals.at(3) = lion;
    animals.at(4) = crocodile;

    cout << "From the following list, pick two different animals to "
            "fight:\n";

    // i = 1 because we want to count from 1 up
    // need to adjust size + 1 because of this
    for (int i = 1; i < animals.size() + 1; i++) {
        /*
        Should come out:
        1. Bear
        2. Shark
        etc.
        */
        cout << i << ". " + animals.at(i - 1).Type + "\n";
    }

    int choice1;
    cin >> choice1;
    int choice2;
    cin >> choice2;

    if (choice1 == choice2) {
        cout << "\nYou must choose two different animals\n";
        return -1; // end program early, -1 return could mean error
    }

    // decrement because choices start from 1, need to readjust
    Animal winner = determineWinner(animals, choice1 - 1, choice2 - 1);
    cout << "\nThe " << winner.Type << " is the winner!\n";

    return 0;
}
