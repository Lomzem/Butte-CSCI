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
    int Score;

    // const &string since an animal's name shouldn't change
    // if we later need to change the animal's name for some
    // reason, we could use "string type"
    Animal(const string &type, int strength, int toughness, int luck) {
        Type = type;
        Strength = strength;
        Toughness = toughness;
        Luck = luck;
        Score = 0;
    }
};

// Could choose to return pointer to Animal instead
/*
Animal *determineWinner(array<Animal, 5> &animals, int choice1, int choice2) {
    Animal animal1 = animals.at(choice1);
    Animal animal2 = animals.at(choice2);

    animal1.Score = animal1.Strength + animal1.Toughness;
    animal2.Score = animal2.Strength + animal2.Toughness;

    if (animal1.Score < animal2.Score) {
        animal1.Score += animal1.Luck;
    } else if (animal1.Score > animal2.Score) {
        animal2.Score += animal2.Luck;
    } else {
        animal1.Score += animal1.Luck;
        animal2.Score += animal2.Luck;
    }

    // TODO! Handle what happens if they have the same score
    if (animal1.Score > animal2.Score) {
        return &animals.at(choice1);
    } else {
        return &animals.at(choice2);
    }
}
*/

// NOTE: This mutates animal.Score, meaning it has SIDE EFFECTS
// This may cause problems, but code assumes user only wants one "fight" per
// program start. Possible fix is to set animal.Score to 0 before function
// return, assuming that animal.Score should always start at 0
Animal determineWinner(array<Animal, 5> &animals, int choice1, int choice2) {
    Animal animal1 = animals.at(choice1);
    Animal animal2 = animals.at(choice2);

    animal1.Score = animal1.Strength + animal1.Toughness;
    animal2.Score = animal2.Strength + animal2.Toughness;

    if (animal1.Score < animal2.Score) {
        animal1.Score += animal1.Luck;
    } else if (animal1.Score > animal2.Score) {
        animal2.Score += animal2.Luck;
    } else {
        animal1.Score += animal1.Luck;
        animal2.Score += animal2.Luck;
    }

    // TODO! Handle what happens if they have the same score
    if (animal1.Score > animal2.Score) {
        return animal1;
    } else {
        return animal2;
    }
}

int main() {
    array<Animal, 5> animals = {
        Animal("Bear", 8, 6, 2),      Animal("Shark", 5, 5, 3),
        Animal("Gorilla", 7, 5, 3),   Animal("Lion", 5, 6, 4),
        Animal("Crocodile", 3, 9, 4),
    };

    cout << "From the following list, pick two different animals to fight:\n";

    // i = 1 because we want to count from 1 up
    // need to adjust size + 1 because of this
    for (int i = 1; i < animals.size() + 1; i++) {
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
    choice1--;
    choice2--;

    Animal winner = determineWinner(animals, choice1, choice2);

    // for pointer version:
    // Animal winner = *determineWinner(animals, choice1, choice2);
    cout << "\nThe " << winner.Type << " is the winner!\n";

    return 0;
}
